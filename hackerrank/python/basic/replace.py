# Enter your code here. Read input from STDIN. Print output to STDOUT

x, k = input().split()
poly = input()
poly = poly.replace("x", x)
    
if eval(poly) == int(k):
    print(True)
else:
    print(False)


# Sample

# 1 4
# x**3 + x**2 + x + 1