

import itertools
s, size = input().split()
s = list(s)
size = int(size)
s.sort()
ans = list(itertools.permutations(s, size))
for i, value in enumerate(ans):
    permPrint = ""
    for letter in value:
        permPrint = permPrint + letter

    print(permPrint)