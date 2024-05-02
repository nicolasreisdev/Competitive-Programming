
#string = str(input())
#pos = int(input())
#char = str(input())
#l = list(string)
#l[pos] = char
#string = ''.join(l)
#print(string)

# --------------------------------------------

string = str(input())
pos, char = input().split()
string = string[:int(pos)] + char + string[int(pos)+1:]
print(string)