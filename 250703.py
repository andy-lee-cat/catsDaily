# 1632C 1600
def solve():
    a, b = map(int, input().split())
    res = b - a
    # (a_ - a) + (b_ - b) + ((a_ | b_) - b_) + 1
    # a_ + (a_ | b_) + (1 - a - b)
    # so just to minimize { a_ + (a_ | b_) }
    # 1000100
    # 0001010
    # 010
    # 101
    for a_ in range(a, b + 1):
        b_ = b
        for i in range(21, -1, -1):
            ai, bi = ((a_ >> i) & 1), ((b >> i) & 1)
            if ai == 1 and bi == 0:
                b_ |= (1 << i)
                # 后边的位都置0
                b_ &= ((1 << 21) - 1) - ((1 << i) - 1)
                break
        res2 = a_ + (a_ | b_) + (1 - a - b)
        res = min(res, res2)
    print(res)

t = 1
t = int(input())
for i in range(t):
    solve()

