if __name__ == "__main__":
    n = int(input())
    arr = [1, 2]
    while True:
        tmp = arr[-1] + arr[-2]
        if tmp > n:
            break
        arr.append(tmp)
    print(len(arr) - 1)
