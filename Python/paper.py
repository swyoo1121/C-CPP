N=int(input())
s=list(input().split() for _ in range(N))
a=[]
def paper(x,y,n):
    color=s[y][x]
    for i in range(y,y+n):
        for j in range(x,x+n):
            if color!=s[i][j]:
                paper(x,y,n//2)
                paper(x,y+n//2,n//2)
                paper(x+n//2,y,n//2)
                paper(x+n//2,y+n//2,n//2)
                return
    if color==1:
        a.append("1")
    else:
        a.append("0")
paper(0,0,N)
print(a.count("0"),a.count("1"))