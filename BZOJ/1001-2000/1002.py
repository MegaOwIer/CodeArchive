if __name__ == "__main__":
    n = int(input())
    ans = [1, 5]
    for i in range(n - 2):
        ans.append(ans[-1] * 3 - ans[-2] + 2)
    print(ans[-1])
