# Enter your code here. Read input from STDIN. Print output to STDOUT

n = input()
vectorForAll = list(map(int, input().split()))
vectorForAny = list(map(str, vectorForAll))
# for i, value in enumerate(vector):
#     print(value)
#     print(vector[i][::-1])))
if(not all(number > 0 for number in vectorForAll)):
    print(False)
elif(not any(number == vectorForAny[i][::-1] for i, number in enumerate(vectorForAny))):
    print(False)
else:
    print(True)