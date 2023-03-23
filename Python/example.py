count=0
n1=int(input())
n=n1
while True:
    count+=1
    if n<10:
        x,y=(0,n)
    else:
        x,y=str(n)
        x=int(x)
        y=int(y)
    num1=x+y
    if num1<10:
        numx,numy=(0,num1)
        num262=int(str(y)+str(numy))
    else:
        numx,numy=str(num1)
        numx=int(numx)
        numy=int(numy)
        num2=int(str(y)+str(numy))
    if num2==n1:
        break
    else:
        n=num2
print(count)