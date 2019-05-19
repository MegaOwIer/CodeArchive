if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        n, m = [int(x) + 1 for x in input().split()]
        print(2 ** n - 2 ** m, ".00", sep="")
