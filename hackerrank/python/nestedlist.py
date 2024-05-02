n = int(input()) # tamanho da lista
students = []  # lista de alunos
for i in range(n): 
    name = str(input()) # nome do aluno
    score = float(input()) # nota do aluno
    students.append([name, score])  # adiciona o aluno e a nota na lista
        
students.sort(key=lambda x: x[1]) # ordena a lista de alunos por nota
for i in students:
    if i[1] != students[0][1]: # pega a segunda menor nota
        second_lowest = i[1] 
        break 
sortstudents = [] # lista de alunos com a segunda menor nota
for i in range(n): 
    if students[i][1] == second_lowest: # pega os alunos com a segunda menor nota
        sortstudents.append(students[i][0]) # adiciona o aluno na lista
        
sortstudents.sort() # ordena a lista de alunos por nome
for i in sortstudents:
    print(i)  # imprime o nome do aluno