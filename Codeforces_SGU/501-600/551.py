from math import ceil

if __name__ == "__main__":
    n, a, b = [int(x) for x in input().split()]
    L = 1
    R = n * max(a, b)
    while L <= R:
        mid = (L + R) >> 1
        val = mid // a + mid // b
        if val < n:
            L = mid + 1
        else:
            ans = mid
            R = mid - 1
    ans = max(ceil(ans / a) * a, ceil(ans / b) * b)
    print(min(n + 1, ans // a + ans // b), ans)