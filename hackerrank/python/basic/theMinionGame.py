def minion_game(string):
    # your code goes here
    vowels = "AEIOU"
    
    kevsc, stusc = 0, 0
    for index, value in enumerate(string):
        if(value in vowels):
            kevsc += len(string) - index
        else:
            stusc += len(string) - index
    
    if (kevsc > stusc):
        print(f"Kevin {kevsc}")
    elif (stusc > kevsc):
        print(f"Stuart {stusc}")
    else:
        print("Draw")

if __name__ == '__main__':
    s = input()
    minion_game(s)