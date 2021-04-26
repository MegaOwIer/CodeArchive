if __name__ == "__main__":
    n = int(input())

    fac = [1]
    for i in range(1, n):
        fac.append(fac[-1] * i)

    res = n - 2
    ans = fac[n - 2]
    cnt = 0

    for i in range(n):
        cur = int(input())
        if cur != -1:
            ans //= fac[cur - 1]
            res -= cur - 1
        else:
            cnt += 1
    
    print(ans // fac[res] * pow(cnt, res))
