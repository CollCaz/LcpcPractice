#/bin/lua
-- Require "lummander"
local Lummander = require "lummander"
local lfs = require "lfs"

-- Create a lummander instance
local cli = Lummander.new {
	title = "CodeForces Practice Helper",                                            -- <string> title for CLI. Default: ""
	tag = "myapp",                                                                   -- <string> CLI Command to execute your program. Default: "".
	description = "A simple Helper script to make practicing with CodeForces easier", -- <string> CLI description. Default: ""
	version = "0.1.1",                                                               -- <string> CLI version. Default: "0.1.0"
	author = "CollCaz",                                                              -- <string> author. Default: ""
	root_path = "",                                                                  -- <string> root_path. Default "". Concat this path to load commands of a subfolder
	theme = "default",                                                               -- Default = "default". "default" and "acid" are built-in themes
	flag_prevent_help = false                                                        -- <boolean> Prevent help message if not command found. Default: false
}

-- Add commands
cli:command("mycmd", "My command description")
		:action(function(_, _, _)
			print("You activated `mycmd` command")
		end)

cli:command("new <value1> <value2>", "new practice session")
		:action(function(parsed, _, _)
			local dirName = "./" .. parsed.value2 .. "/"
			lfs.mkdir(dirName)
			local codeFile = io.open(dirName .. parsed.value2 .. ".cpp", "w")
			if codeFile ~= nil then
				codeFile:write("#include <iostream>\nusing namespace std;")
				codeFile:close()
			end
			local infoFile = io.open(dirName .. "info.txt", "w")
			if infoFile ~= nil then
				infoFile:write("link: " .. parsed.value1 .. "\ntime started: " .. os.date("%H:%M %a %x") .. "\nrating: ?")
				infoFile:close()
			end
		end)

cli:command("sum <value1> <value2>", "Sum 2 values")
		:option(
			"option1", "o", "Option1 description", nil, "normal", "option_default_value")
		:option(
			"option2", "p", "Option2 description", nil, "normal", "option2_default_value")
		:action(function(parsed, _, _)
			print("" .. parsed.value1 .. "+" .. parsed.value2 .. " = " ..
				tostring(tonumber(parsed.value1) + tonumber(parsed.value2)))
		end)

-- Parse and execute the command wrote
cli:parse(arg) -- parse arg and execute if a command was written
