if __name__ == '__main__':
    s = input()
    isAlphaNum = False
    isAlpha = False
    isDigit = False
    isLower = False
    isUpper = False
    for i in s:
        if(i.isalnum()):
            isAlphaNum = True
        if(i.isalpha()):
            isAlpha = True
        if(i.isdigit()):
            isDigit = True
        if(i.islower()):
            isLower = True
        if(i.isupper()):
            isUpper = True
    
    print(isAlphaNum)
    print(isAlpha)
    print(isDigit)
    print(isLower)
    print(isUpper)