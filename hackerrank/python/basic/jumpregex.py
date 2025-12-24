import re

n = input()
n = re.sub(r'[,.]', '\n', n) # substitui as vírgulas e pontos por quebras de linha
print(n)