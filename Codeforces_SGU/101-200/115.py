from datetime import datetime

if __name__ == "__main__":
    n, m = input().split()
    try:
        ans = datetime.strptime(F'2001{m.zfill(2)}{n.zfill(2)}', '%Y%m%d').weekday() + 1
    except:
        ans = 'Impossible'
    print(ans)
