if __name__ == "__main__":
    n = int(input())
    if n % 2 == 1:
        print(0)
    else:
        print(2 ** (n // 2))