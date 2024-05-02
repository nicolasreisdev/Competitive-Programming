import re

"""
^ : start of string
[ : beginning of character group
a-z : any lowercase letter
A-Z : any uppercase letter
0-9 : any digit
_ : underscore
] : end of character group
* : zero or more of the given characters
$ : end of string
"""

import re

n = str(input())
print(n)
r = re.compile(r'[^a-zA-Z0-9]')
ans = r.sub('', n)
stop = False
tam = []
for i in range(len(ans)):
    for j in range(i+1, len(ans)):
        if ans[j] == ans[i]:
            stop = True
            tam.append([ans[i], j-i]) 
            break
if not stop:
    print(-1)
else:
    tam.sort(key=lambda x: x[1])
    print(tam[0][0])