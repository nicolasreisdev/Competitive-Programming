

t = int(input())

for vai in range(t):
    n, k = map(int, input().split())
    ans = 0
    for i in range(n, n-k, -1):
        ans += pow(i,i)
    if ans % 2 == 0:
        print("YES")
    else:
        print("NO")