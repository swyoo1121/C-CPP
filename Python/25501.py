def recursion(s, l, r):
    global count
    count = count + 1
    if l >= r: return 1
    elif s[l] != s[r]: return 0
    else: return recursion(s, l+1, r-1)

def isPalindrome(s):
    return recursion(s, 0, len(s)-1)

N = int(input())

for i in range(0, N):
    count = 0
    target = input()
    ans = isPalindrome(target)
    print("%d %d" % (ans, count))
    