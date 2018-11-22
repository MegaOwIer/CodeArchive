from math import sqrt, atan, asin, cos

def check(a, b, d, e):
    if a <= d and b <= e:
        return True
    R = sqrt(a * a + b * b) / 2
    mn = atan(b / a)
    mx = asin(e / 2 / R)
    if mx < mn or R * min(cos(mn), cos(mx - mn * 2)) * 2 > d:
        return False
    else:
        return True

if __name__ == "__main__":
    inf = open('bricks.in', 'r')
    ouf = open('bricks.out', 'w')
    a, b, c, d, e = [float(x) for x in inf.readline().split()]
    arr1 = sorted([a, b, c])
    arr2 = sorted([d, e])
    if check(arr1[1], arr1[0], arr2[1], arr2[0]):
        print('YES', file=ouf)
    else:
        print('NO', file=ouf)
