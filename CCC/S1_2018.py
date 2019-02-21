n = int(input())
villages = [int(input()) for i in range(n)]

ns = []
villages.sort()

for i in range(1, n - 1):
    village = villages[i]
    left = (village - villages[i - 1]) / 2
    right = (villages[i + 1] - village) / 2

    ns.append(left + right)

print(round(min(ns), 1))