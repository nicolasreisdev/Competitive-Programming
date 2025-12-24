n = int(input()) # tamanho da lista
student_marks = {} # dicionário de alunos
for _ in range(n):
    name, *line = input().split() # nome e notas do aluno
    scores = list(map(float, line)) # converte as notas para float
    student_marks[name] = scores # adiciona o aluno e as notas no dicionário
query_name = input() # nome do aluno
sum = 0
for i in student_marks[query_name]:
    sum += i # soma as notas do aluno
    
print("{:.2f}".format(sum/3), end="") # imprime a média das notas do aluno com duas casas decimais
print()
    