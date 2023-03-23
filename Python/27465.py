import random

N = int(input())

answer = random.randrange(N, 1000000001)

if answer % 2 == 1:
    answer = answer+1

print(answer)