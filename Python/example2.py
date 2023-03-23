cycles = 0
target = int(input())
temp = target

while True:
	temp = (temp % 10) * 10 + ((temp // 10) + (temp % 10)) % 10
	cycles += 1
	if (temp == target):
	    break

print(cycles)
