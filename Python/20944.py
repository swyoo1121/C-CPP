import random

N = int(input())
alphabet = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']

if N % 2 == 0:
    answer = alphabet[random.randrange(0, 26)] * N
else:
    answer1 = alphabet[random.randrange(0, 26)] * (int)((N-1) / 2)
    answer2 = alphabet[random.randrange(0, 26)]
    answer = answer1 + answer2 + answer1

print(answer)