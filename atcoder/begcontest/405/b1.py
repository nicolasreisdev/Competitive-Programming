n, m = map(int, input().split())
v = list(map(int, input().split()))
ans = 0
s = set()
for i in range(n-1, -1, -1):
    s.add(v[i])
    if not all (x in s for x in range(1, m+1)):
        ans = n-i

print(ans)