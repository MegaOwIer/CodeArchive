# Round 1B
# https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae694

from itertools import permutations

if __name__ == '__main__':
    T = int(input())
    mod = 12 * 3600 * 10**9
    phi = mod * 4 // 15
    inv_m = pow(11, phi - 1, mod)
    inv_s = pow(719, phi - 1, mod)
    for _ in range(T):
        arr = list(map(int, input().split()))
        for cur in permutations(arr):
            delta_m = (cur[1] - cur[0]) * inv_m % mod
            delta_s = (cur[2] - cur[0]) * inv_s % mod
            if delta_m == delta_s:
                n = delta_m % 10**9
                s = delta_m // 10 ** 9 % 60
                m = delta_m // 10 ** 9 // 60 % 60
                h = delta_m // 10 ** 9 // 3600
                print(F'Case #{_ + 1}: {h} {m} {s} {n}')
                break
