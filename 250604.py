# 1624D 1400

from collections import Counter

def solve():
    n, k = map(int, input().split())
    s = input()
    cnts = Counter(s)
    cntpairs, cntodd = 0, 0
    for cnt in cnts.values():
        cntpairs += cnt // 2
        cntodd += cnt % 2
    
    res = 2 * (cntpairs // k)
    cntodd += 2 * (cntpairs % k)
    if cntodd >= k:
        res += 1
    print(res)

t = 1
t = int(input())
for i in range(t):
    solve()
