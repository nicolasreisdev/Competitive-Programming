import string

x = int(input())
pangram = input(str())
result = ''
    
for i in pangram:
    if i.islower():
        result += i.upper()
    else:
        result += i    

a = list(string.ascii_uppercase)
for i in range(0,x):
    if result[i] in a:
        a.remove(result[i])
        
if len(a) == 0:
    print("YES")
else:
    print("NO")
    