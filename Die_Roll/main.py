from fractions import Fraction

y, d = [int(x) for x in input().split()]

wc = abs(max(y, d) - 7)

f = Fraction(wc, 6)
if f == 1:
    f = "1/1"

if f == 0:
    f = "0/1"

print(f)
