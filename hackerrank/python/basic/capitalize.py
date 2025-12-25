#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the solve function below.
def solve(s):
    name = s.split(' ')
    ans = ""
    for index, name in enumerate(name):
        ans += name.capitalize() + ' '

    # ans = s.title() # or just use title function haha
    
    return ans

if __name__ == '__main__':
    # fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = solve(s)
    print(result)
    # fptr.write(result + '\n')

    # fptr.close()
