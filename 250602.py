# 1332C 1500
from collections import defaultdict

def solve():
    n, k = map(int, input().split())
    s = input()
    if k % 2 == 0:
        loop = k // 2
    else:
        loop = k // 2 + 1

    res = 0
    for i in range(loop):
        cnts = defaultdict(int)
        for j in range(n // k):
            cnts[s[j * k + i]] += 1
            cnts[s[j * k + k - 1 - i]] += 1
        total = sum(cnts.values())
        maxv = max(cnts.values(), default=0)
        add = total - maxv
        if i == loop - 1 and k % 2 == 1:
            add //= 2
        res += add
    print(res)

t = 1
t = int(input())
for i in range(t):
    solve()

