from math import sqrt, floor

if __name__ == "__main__":
    L = 1
    R = 10 ** 500
    N = int(input())
    while L <= R:
        mid = (L + R) >> 1
        if mid * mid <= N:
            ans = mid
            L = mid + 1
        else:
            R = mid - 1
    print(ans)