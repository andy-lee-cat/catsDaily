# 289B 1400
def solve():
    n, m, d = map(int, input().split())
    a = []
    for _ in range(n):
        row = list(map(int, input().split()))
        a += row

    n *= m
    a.sort()
    mod = a[0] % d
    for v in a:
        if v % d != mod:
            print(-1)
            return
    
    for i in range(len(a)):
        a[i] = (a[i] - mod) // d
    
    l, r = a[0], a[n - 1]
    res = 0
    while l < r:
        mid = (l + r) // 2
        sm, la = 0, 0
        for v in a:
            if mid > v:
                la += 1
            elif mid < v:
                sm += 1
        if sm >= la:
            l = mid + 1
        else:
            r = mid
    # l is the first sm > la
    res1 = 0
    for v in a:
        res1 += abs(l - v)
    l -= 1
    res2 = 0
    for v in a:
        res2 += abs(l - v)
    print(min(res1, res2))


t = 1
# t = int(input())
for i in range(t):
    solve()

