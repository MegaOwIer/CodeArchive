if __name__ == "__main__":
    n, k = [int(x) for x in input().split()]
    ans = n * k
    n = min(n, k)
    i = 1
    while i <= n:
        d = k // i
        j = min(k // d, n)
        ans -= d * (j + i) * (j - i + 1) // 2
        i = j + 1
    print(ans)
