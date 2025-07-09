# 1371D 1600
def solve():
    n, k = map(int, input().split())
    arr = [[0] * n for _ in range(n)]
    i, j = 0, 0
    while k > 0:
        k -= 1
        arr[i][j] = 1
        i += 1
        j = (j + 1) % n
        if i == n:
            i = 0
            j = (j + 1) % n

    R = [0] * n
    C = [0] * n
    for i in range(n):
        for j in range(n):
            R[i] += arr[i][j]
            C[j] += arr[i][j]
    print((max(R) - min(R)) ** 2 + (max(C) - min(C)) ** 2)
    for i in range(n):
        for j in range(n):
            print(arr[i][j], end='')
        print()

t = 1
t = int(input())
for i in range(t):
    solve()

