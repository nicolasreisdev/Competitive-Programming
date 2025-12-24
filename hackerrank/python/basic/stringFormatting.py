
def print_formatted(number):
    width = len(bin(number)[2:])
    for i in range(1,number+1):
        deci = f"{i:d}".rjust(width)
        octal = f"{i:o}".rjust(width)
        hexa = f"{i:x}".rjust(width).upper()
        binary = f"{i:b}".rjust(width)
        print(f"{deci} {octal} {hexa} {binary}")

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)