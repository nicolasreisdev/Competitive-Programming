x,y = input().split()
while x != "0" and y != "0":
    cont = 0
    for i in range(len(x)):
        if (x[i]+y[i])>9:
            cont+=1
        