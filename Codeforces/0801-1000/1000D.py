if __name__ == "__main__":
    N = int(input())
    a = [0] + list(map(int, input().split()))
    mod = 998244353
    dp = [[0 for i in range(N + 2)] for i in range(N + 1)]
    for i in range(1, N + 1):
        for j in range(N + 1):
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j + 1]) % mod
        if a[i] <= N and a[i] > 0:
            dp[i][a[i]] = (dp[i][a[i]] + dp[i - 1][0] + 1) % mod
    print(dp[N][0])
