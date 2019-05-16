from math import sqrt

eps = 1e-6

class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def __add__(self, a):
        return Vector(self.x + a.x, self.y + a.y)
    def __sub__(self, a):
        return Vector(self.x - a.x, self.y - a.y)
    def __mul__(self, a : float):
        return Vector(self.x * a, self.y * a)
    def __truediv__(self, a : float):
        return Vector(self.x / a, self.y / a)
    def __abs__(self):
        return sqrt(self.x * self.x + self.y * self.y)
    def normal(self):
        return Vector(self.y, -self.x)

points = []
ans = 1

def getAns(O : Vector) -> int:
    ans = 0
    for P in points:
        if abs(P - O) <= 2.5 + eps:
            ans += 1
    return ans

def check(A : Vector, B : Vector) -> int:
    d = abs(A - B) / 2
    d = sqrt(2.5 * 2.5 - d * d)
    norm = (B - A).normal()
    norm = norm / abs(norm) * d
    return max(getAns((A + B) / 2 + norm), getAns((A + B) / 2 - norm))

if __name__ == "__main__":
    while True:
        try:
            x, y = [float(x) for x in input().split()]
        except:
            break
        else:
            points.append(Vector(x, y))
    for i in range(len(points)):
        for j in range(i + 1, len(points)):
            if abs(points[i] - points[j]) > 5.0 + eps:
                continue
            ans = max(ans, check(points[i], points[j]))
    print(ans)
