if __name__ == "__main__":
    n, k = [int(x) for x in input().split()]
    if k > n:
        ans = 0
    else:
        ans = 1
        for i in range(n, n - k, -1):
            ans *= i * i
        for i in range(k, 0, -1):
            ans //= i
    print(ans)
