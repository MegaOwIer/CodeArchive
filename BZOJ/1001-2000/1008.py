if __name__ == "__main__":
    m, n = map(int, input().split())
    mod = 100003
    print((pow(m, n, mod) - m * pow(m - 1, n - 1, mod)) % mod)
