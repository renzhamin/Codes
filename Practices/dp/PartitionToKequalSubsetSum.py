nums=[4, 3, 2, 3, 5, 2, 1]
k=4

n=len(nums)
target=sum(nums)//k
N=1<<n
dp=[-1]*N

dp[0] = 0

for mask in range(0,N-1):
    if dp[mask] == -1:continue
    for i in range(n):
        if (mask>>i)&1:continue
        tmp = dp[mask] + nums[i]
        if tmp <= target:
            dp[mask|1<<i] = tmp%target

print(dp[-1])
