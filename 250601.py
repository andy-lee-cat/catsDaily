# 702C 1500
def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    l, r = 0, int(2e9)

    l = max(0, b[0] - a[0], a[-1] - b[-1])
    while l < r:
        mid = (l + r) // 2
        nowb = 0
        flag = True
        for nowa in range(n):
            while nowb < m and b[nowb] + mid < a[nowa]:
                nowb += 1
            if nowb == m or b[nowb] - mid > a[nowa]:
                flag = False
                break
        if flag:
            r = mid
        else:
            l = mid + 1
    print(l)



t = 1
t = int(input())
for i in range(t):
    solve()

