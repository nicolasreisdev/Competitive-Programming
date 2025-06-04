R, X = map(int, input().split())

if X == 1:
    print("Yes" if 1600 <= R <= 2999 else "No")
else:  # X == 2
    print("Yes" if 1200 <= R <= 2399 else "No")
