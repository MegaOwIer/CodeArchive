if __name__ == "__main__":
    arr = []
    for i in range(3):
        arr.append(sorted([int(x) for x in input().split()])[1])
    print(sorted(arr)[1])