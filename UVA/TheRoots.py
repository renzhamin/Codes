# Newton-Raphson
from sys import stdin

prec=10**-9

def f(l,r,x,fx):
    s=p=0
    for i in range(l,r):
        s += fx[i]*(x**p)
        p+=1
    return s

def findRoot(l,r,fx):
    fpx=[0]*(r+1)
    c=1
    for i in range(l+1,r):
        fpx[i]=fx[i]*c
        c+=1

    x=25
    nx=-25
    while abs(nx-x)>=prec:
        x = nx
        nx = x - f(l,r,x,fx)/f(l+1,r,x,fpx)
    return nx

def solve(fx,n):
    l=0
    r=n+1
    for i in range(n):
        x = findRoot(l,r,fx);
        print(" {0:.4f}".format(x),end="")
        for i in range(n-1,l,-1):
           fx[i]+=fx[i+1]*x
        l+=1

    print("")

T=1
for line in stdin:
    n=int(line[0])
    if not n:break
    fx=list((map(float,line[1:].split())))
    fx.reverse()
    print("Equation",T,end=":")
    T+=1
    solve(fx,n)

