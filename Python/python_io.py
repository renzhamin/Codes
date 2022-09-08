n,m=map(int,input().split())
vis=[0]*n
g=[set() for _ in range(n+1)]

for _ in range(m):
    a,b=map(int,input().split())
    g[a].add(b)
    g[b].add(a)


print(g)
