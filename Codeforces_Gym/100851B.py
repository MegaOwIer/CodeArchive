import sys
sys.stdin = open("binary.in", "r")
sys.stdout = open("binary.out", "w")

if __name__ == "__main__":
    ans = [(0, 1), (1, 1)]
    N = int(input())
    x = 10
    lenx = 1
    while ans.__len__() <= N:
        for (val, lth) in ans:
            if lth == lenx + 1:
                break
            tmp = val >> lth
            if not tmp & ((1 << (lenx - lth + 1)) - 1):
                ans.append((val + x, lenx + 1))
        x *= 10
        lenx += 1
    print(ans[N][0])