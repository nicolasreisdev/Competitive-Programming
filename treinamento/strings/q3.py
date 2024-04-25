import string

pangram = input(str())
result = ''

a = list(string.ascii_uppercase)
for i in range(0):
    if result[i] in a:
        a.remove(result[i])
        
if len(a) == 0:
    print("YES")
else:
    print("NO")
    