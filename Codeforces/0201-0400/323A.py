if __name__ == "__main__":
    n = int(input())
    if n % 2 == 1:
        print(-1)
        exit()
    str1 = ''.join(['bb' if i % 2 == 1 else 'ww' for i in range(n // 2)])
    str2 = ''.join(['bb' if i % 2 == 0 else 'ww' for i in range(n // 2)])

    for i in range(n):
        str1, str2 = str2, str1
        for j in range(n // 2):
            print(str1 if j % 2 == 0 else str2)
            print(str1 if j % 2 == 0 else str2)
        print('')
