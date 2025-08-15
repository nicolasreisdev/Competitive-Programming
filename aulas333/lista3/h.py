n = int(input())
for i in range (n):
    x = str(input())
    y = reversed(x)
    cont = 0
    print(x, y)
    while x != y:
        cont += 1
        x = str(int(x) + int(y))
        y = reversed(x)
    print(cont, x)