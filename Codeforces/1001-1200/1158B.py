if __name__ == "__main__":
    N, K = [int(x) for x in input().split()]
    len = (N - K) // 2 + 1
    s0 = '0' * (len - 1) + '1'
    print(s0 * (N // len) + s0[ : N % len])
