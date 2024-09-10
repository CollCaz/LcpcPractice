n1 = 0
n2 = 0
while True:
    try:
        n1 = int(input())
        n2 = int(input())
    except EOFError:
            break
    print(n1 * n2)
