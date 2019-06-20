def check(n):
    ans = 0
    while n > 0:
        n //= 5
        ans += n
    return ans

if __name__ == "__main__":
    N = int(input())
    L = 1
    R = 1000000000
    ans = "No solution"
    while L <= R:
        mid = (L + R) >> 1
        num = check(mid)
        if num > N:
            R = mid - 1
        elif num < N:
            L = mid + 1
        else:
            ans = mid
            R = mid - 1
    print(ans)
