

def split_and_join(line):
    ans = line.split(" ") # divide a string em uma lista de strings separadas por espaço
    ans = "-".join(ans) # junta as strings da lista separadas por '-'
    return ans

if __name__ == '__main__':
    line = input()
    result = split_and_join(line)
    print(result)