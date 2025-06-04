MOD = 10**9 + 7

N = int(input())
A = list(map(int, input().split()))

total = sum(A) % MOD
ans = 0

for a in A:
    total = (total - a + MOD) % MOD
    ans = (ans + a * total) % MOD

inv2 = pow(2, MOD - 2, MOD)
ans = (ans * inv2) % MOD

print(ans)
