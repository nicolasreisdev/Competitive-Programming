n, m = map(int, input().split())
for i in range(n//2) :
    print((('.|.'*(1+(2*i))).center(m,'-')))
print('WELCOME'.center(int(m),'-'))
for i in range(n//2, 0, -1) :
    print((('.|.'*(1+(2*(i-1)))).center(m,'-')))