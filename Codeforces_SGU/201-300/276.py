if __name__ == "__main__":
    n, m = [int(x) for x in input().split()]
    if n >= m:
        ans = 0
    elif m - n < 300:
        ans = 1
    elif m - n < 900:
        ans = 2
    elif m - n < 1800:
        ans = 3
    else:
        ans = 4
    print(ans)