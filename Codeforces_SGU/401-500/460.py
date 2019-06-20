if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        s = input()
        if s.endswith(('ch', 's', 'x', 'o')):
            print(s + 'es')
        elif s.endswith('f'):
            print(s[:-1] + 'ves')
        elif s.endswith('fe'):
            print(s[:-2] + 'ves')
        elif s.endswith('y'):
            print(s[:-1] + 'ies')
        else:
            print(s + 's')
