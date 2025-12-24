def count_substring(string, sub_string):
    length = len(sub_string)
    cont = 0
    for i in range(0, len(string) - length + 1):
        if(string[i:i+length] == sub_string):
            cont+=1
        
    return cont

if __name__ == '__main__':
    string = input().strip()
    sub_string = input().strip()
    
    count = count_substring(string, sub_string)
    print(count)