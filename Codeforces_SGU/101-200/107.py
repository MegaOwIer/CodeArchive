if __name__ == "__main__":
    N = int(input())
    if N <= 8:
        ans = '0'
    elif N == 9:
        ans = '8'
    else:
        ans = '72' + '0' * (N - 10)
    print(ans)
    
