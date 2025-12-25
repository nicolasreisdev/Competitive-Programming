def merge_the_tools(string, k):
    # your code goes here
    substr = []
    index = 0
    for i in range(0, len(string)//k):
        substr.append(string[index:len(string)//k + index])
        index = len(string)//k + index
    
    for index, value in enumerate(substr):
        whitoutRepeat = set()
        for i in value:
            whitoutRepeat.add(i)
        
        print(whitoutRepeat)
        
        

if __name__ == '__main__':
    string, k = input(), int(input())
    merge_the_tools(string, k)


def otherSolution(S, N):
    for part in zip(*[iter(S)] * N):
        d = dict()
        print(''.join([ d.setdefault(c, c) for c in part if c not in d ]))