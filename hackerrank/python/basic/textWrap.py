import textwrap

def wrap(string, max_width):
    ans = ""
    for index, letter  in enumerate(string):
        if(index % max_width == 0 and index != 0):
            ans += '\n'
        ans += letter 

    return ans


if __name__ == '__main__':
    string, max_width = input(), int(input())
    result = wrap(string, max_width)
    print(result)