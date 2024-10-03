#!/usr/bin/env lua
-- Require "lummander"
local Lummander = require "lummander"
local lfs = require "lfs"
local sqlite3 = require "lsqlite3"



local schema = [=[
CREATE TABLE IF NOT EXISTS days(date UNIQUE, amount);
]=]

local updateDayQ = [=[
INSERT OR IGNORE INTO days(date, amount) VALUES("%s", 0);
UPDATE days set amount = amount+1 WHERE date = "%s";
]=]

local db = nil

local openDB = function(root)
	if db == nil then
		db = sqlite3.open(root .. ".db.sqlite")
		db:exec(schema)
	end
end

local closeDB = function()
	if db ~= nil then
		db:close()
		db = nil
	end
end

local updateDay = function()
	local q = string.format(updateDayQ, os.date("%d/%m/%Y"), os.date("%d/%m/%Y"))
	if db ~= nil then
		db:exec(q)
	end
end

local ratingRange = function(rating)
	local r = tonumber(rating)
	if (r == nil) then return rating end
	if (r < 1000) then return "0-1000" end
	if (r < 1500) then return "1000-1500" end
	if (r < 2000) then return "1500-2000" end
	if (r < 2500) then return "2000-2500" end
	if (r < 3000) then return "2500-3000" end
	if (r > 3000) then return "3000-∞" end
end
-- Create a lummander instance
local cli = Lummander.new {
	title = "CodeForces Practice Helper",                                            -- <string> title for CLI. Default: ""
	tag = "helper",                                                                  -- <string> CLI Command to execute your program. Default: "".
	description = "A simple Helper script to make practicing with CodeForces easier", -- <string> CLI description. Default: ""
	version = "0.1.1",                                                               -- <string> CLI version. Default: "0.1.0"
	author = "CollCaz",                                                              -- <string> author. Default: ""
	root_path = "/home/coll/Stuff/Dev/LcpcPractice/",                                -- <string> root_path. Default "". Concat this path to load commands of a subfolder
	theme = "default",                                                               -- Default = "default". "default" and "acid" are built-in themes
	flag_prevent_help = false                                                        -- <boolean> Prevent help message if not command found. Default: false
}

openDB(cli.root_path)

local makeFileText = [[
CFLAGS=-std=c++20
CC= c++

.PHONY: all clean

all: build

build:
	$(CC) main.cpp $(CFLAGS) -o main

clean:
	rm -f main
]]

-- Add commands
cli:command("here <link> <name>", "new problem")
		:action(function(parsed, _, _)
			local dirName = "./" .. parsed.name .. "/"
			lfs.mkdir(dirName)
			local codeFile = io.open(dirName .. "main.cpp", "w")
			if codeFile ~= nil then
				codeFile:write(
					"#include <iostream>\n" ..
					"using namespace std;\n" ..
					"\n" ..
					"int main () {\n\n}"
				)
				codeFile:close()
			end
			local infoFile = io.open(dirName .. "info.txt", "w")
			if infoFile ~= nil then
				infoFile:write(
					"link: " .. parsed.link ..
					"\ntime started: " .. os.date("%H:%M %a %x")
				)
				infoFile:close()
			end
			local makeFile = io.open(dirName .. "Makefile", "w")
			if makeFile ~= nil then
				makeFile:write(makeFileText)
			end
			os.execute("echo cd " .. dirName .. " | wl-copy")
		end)
cli:command("new <link> <name> <rating>", "new practice session")
		:action(function(parsed, _, _)
			local r = parsed.rating
			if (r == "?") then r = "UNKOWN" end
			local newName
			if (r == "UNKOWN") then
				newName = string.gsub(parsed.name, " ", "_")
				newName = string.gsub(newName, "'", "")
			else
				newName = r .. "-" .. string.gsub(parsed.name, " ", "_")
				newName = string.gsub(newName, "'", "")
			end
			local dirName = cli.root_path .. ratingRange(r) .. "/" .. newName .. "/"
			lfs.mkdir(dirName)
			local codeFile = io.open(dirName .. "main.cpp", "w")
			if codeFile ~= nil then
				codeFile:write(
					"#include <iostream>\n" ..
					"using namespace std;\n" ..
					"\n" ..
					"int main () {\n\n}"
				)
				codeFile:close()
			end
			local infoFile = io.open(dirName .. "info.txt", "w")
			if infoFile ~= nil then
				infoFile:write(
					"link: " .. parsed.link ..
					"\nrating: " .. r ..
					"\ntime started: " .. os.date("%H:%M %a %x")
				)
				infoFile:close()
			end
			local makeFile = io.open(dirName .. "Makefile", "w")
			if makeFile ~= nil then
				makeFile:write(makeFileText)
			end
			os.execute("echo cd " .. dirName .. " | wl-copy")
		end)

cli:command("done")
		:action(function(_, _, _)
			if (io.open("info.txt", "r") ~= nil) then
				local infoFile = io.open("info.txt", "a+")
				if infoFile ~= nil then
					infoFile:write(
						"\ntime finished: " .. os.date("%H:%M %a %x")
					)
					infoFile:close()
				end
			end
			updateDay()
		end)
cli:command("today")
		:action(function(_, _, _)
			openDB(cli.root_path)
			local q = string.format("SELECT * FROM days WHERE date = \"%s\" LIMIT 1", os.date("%d/%m/%Y"))
			if db ~= nil then
				for x in db:nrows(q) do
					print(x.amount)
				end
			end
			closeDB()
		end)

cli:command("contest <link> <round> <div>")
		:action(function(parsed, _, _)
			local dirName = cli.root_path .. "Contests/" .. parsed.round .. "-" .. "div-" .. parsed.div .. "/"
			lfs.mkdir(dirName)
		end)

cli:command("problem <rank>")
		:action(function(parsed, _, _)
			local dirName = "./" .. parsed.rank .. "/"
			lfs.mkdir(dirName)
			local codeFile = io.open(dirName .. "main.cpp", "w")
			if codeFile ~= nil then
				codeFile:write(
					"#include <iostream>\n" ..
					"using namespace std;\n" ..
					"\n" ..
					"int main () {\n\n}"
				)
				codeFile:close()
			end
			local infoFile = io.open(dirName .. "info.txt", "w")
			if infoFile ~= nil then
				infoFile:write(
					"\ntime started: " .. os.date("%H:%M %a %x")
				)
				infoFile:close()
			end
			local makeFile = io.open(dirName .. "Makefile", "w")
			if makeFile ~= nil then
				makeFile:write(makeFileText)
			end
			os.execute("echo " .. dirName .. " | wl-copy")
		end)

-- Parse and execute the command wrote
cli:parse(arg) -- parse arg and execute if a command was written
closeDB()
