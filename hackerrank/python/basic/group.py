# group(), groups(), groupdict() in Python
# https://www.geeksforgeeks.org/group-groups-groupdict-python-regular-expression/
import re

m = re.match(r"(?P<user>\w+)@(?P<website>\w+)\.(?P<extension>\w+)", input()) # procura por um padrão de email
print(m.group(0)) # imprime o email completo ex: username@hackerrank.com
print(m.group(1)) # imprime o nome do email ex: username
print(m.group(2)) # imprime o domínio do email ex: hackerrank
print(m.group(3)) # imprime a extensão do email ex: com
print(m.groups()) # imprime todos os grupos encontrados ex: ('username', 'hackerrank', 'com')
print(m.groupdict()) # imprime todos os grupos encontrados em um dicionário com os nomes dos grupos 
                    #ex: {'user': 'username', 'website': 'hackerrank', 'extension': 'com'}
                    