n = int(input())
list = []
for i in range(n):
    command = input().split() # divide a entrada em uma lista de strings separadas por espaço
    print(i)
    if command[0] == 'insert': # se o primeiro elemento da lista for 'insert'
        list.insert(int(command[1]), int(command[2])) # insere o elemento na posição indicada
    elif command[0] == 'print': # se o primeiro elemento da lista for 'print'
        print(list) # imprime a lista
    elif command[0] == 'remove': # se o primeiro elemento da lista for 'remove'
        list.remove(int(command[1])) # remove o elemento indicado
    elif command[0] == 'append': # se o primeiro elemento da lista for 'append'
        list.append(int(command[1])) # adiciona o elemento indicado ao final da lista
    elif command[0] == 'sort': # se o primeiro elemento da lista for 'sort'
        list.sort() # ordena a lista
    elif command[0] == 'pop': # se o primeiro elemento da lista for 'pop'
        list.pop() # remove o último elemento da lista
    elif command[0] == 'reverse': # se o primeiro elemento da lista for 'reverse'
        list.reverse() # inverte a lista
    else:
        pass 