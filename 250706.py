# 1327E 1800
MOD = 998244353
p = [1] * 200005
def init():
    for i in range(1, 200005):
        p[i] = p[i - 1] * 10 % MOD

def solve():
    n = int(input())
    for i in range(1, n):
        res = 2 * 10 * 9 * p[n - i - 1]
        res += (n - i - 1) * 10 * 9 * 9 * p[n - i - 2]
        res %= MOD
        print(res, end=' ')
    print(10)

t = 1
t = int(input())
init()
for i in range(t):
    solve()

