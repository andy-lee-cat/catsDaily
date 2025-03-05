import random

easy = [1200, 1300, 1400]
medium = [1400, 1500, 1600]
hard = [1600, 1700, 1800, 1900]
url = "https://codeforces.com/problemset?order=BY_SOLVED_DESC&tags="

print("输入今日难度系数(1简单，2中等，3困难): ")
level = int(input())
if level == 1:
    elo = random.choice(easy)
elif level == 2:
    elo = random.choice(medium)
elif level == 3:
    elo = random.choice(hard)

elo += 200
url += str(elo) + '-' + str(elo)
print(url)
