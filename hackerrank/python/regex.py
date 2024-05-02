import re


n = str(input()) # input() retorna uma string

# ------------------------------------------------------------------------------------


#r = re.compile(r'[^0-9]') # cria um padrão regex que procura por qualquer coisa que não seja um número
#m = r.sub('', n) # substitui qualquer coisa que não seja um número por uma string vazia


# ------------------------------------------------------------------------------------

r = re.compile(r'\D')
m = r.sub('', n)

# ------------------------------------------------------------------------------------

#r = re.compile(r'\D', re.ASCII)
#m = r.sub('', n)



print(m)