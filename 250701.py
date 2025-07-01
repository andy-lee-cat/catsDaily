# 1251C 1600

from collections import deque

def solve():
    s = input()
    n = len(s)
    q0 = deque()
    q1 = deque()
    for c in s:
        c = int(c)
        if c % 2 == 0:
            q0.append(c)
        else:
            q1.append(c)
    
    ans = []
    while q0 and q1:
        if q0[0] < q1[0]:
            ans.append(q0.popleft()) 
        else:
            ans.append(q1.popleft())
    while q0:
        ans.append(q0.popleft())
    while q1:
        ans.append(q1.popleft())
    print(''.join(map(str, ans)))

t = 1
t = int(input())
for i in range(t):
    solve()

