# 1554C 1800
def solve():
    n, m = map(int, input().split())
    debug = 0
    if debug:
        print(bin(n))
        print(bin(m))
    if n > m:
        print(0)
        return
    ans = 0
    # 神奇的加这一行，然后注释掉下面的if i==0
    m += 1
    for i in range(30, -1, -1):
        a, b = (n >> i) & 1, (m >> i) & 1
        """
        if i == 0:
            if b == 1:
                ans += 2
            elif a == 0 and b == 0:
                ans += 1
            continue
        """

        if a == 0 and b == 1:
            ans += (1 << i)
        elif a == 1 and b == 0:
            break
        # a,b=1,1 or 0,0 continue
    if debug:
        print(bin(ans))
    print(ans)

t = 1
t = int(input())
for i in range(t):
    solve()

