# 1320A 1400
from collections import defaultdict

def solve():
    n = int(input())
    b = list(map(int, input().split()))
    res = defaultdict(int)
    for i in range(n):
        res[b[i] - i] += b[i]
    print(max(res.values()))
    

t = 1
t = int(input())
for i in range(t):
    solve()

