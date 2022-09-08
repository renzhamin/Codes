precision = 1e-12

def gaussJordan(a,b):
    n,m = len(b),len(a[0])
    row = 0
    for col in range(m):
        sel = row
        for i in range(row+1,n):
            if abs(a[sel][col])<abs(a[i][col]):
                sel = i

        if abs(a[sel][col]) < precision : continue

        a[row],a[sel] = a[sel],a[row]
        b[row],b[sel] = b[sel],b[row]

        pivot = a[row][col]
        for i in range(col,m):
            a[row][i]/=pivot

        b[row]/=pivot

        for i in range(n):
            if i==row or a[i][col]==0:continue
            f = a[i][col]
            for j in range(col,m):
                a[i][j] -= f*a[row][j]
            b[i] -= f*b[row]

        row+=1
        if row == n: break

    return b,a 


a = [[1,1,2],[2,4,-3],[3,6,-5]]
b = [9,1,0]


x,A = gaussJordan(a,b)

[ print(round(i),end=" ") for i in x ]
