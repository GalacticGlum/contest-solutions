n = int(input())
tides = sorted([int(i) for i in input().split()])
start = int((n + n % 2) / 2)

low = list(reversed(tides[:start]))
high = tides[start:]

result = []
for i in range(start):
    result.append(low[i])
    if i < len(high):
        result.append(high[i])

result_str = str()
for tide in result:
    result_str += str(tide) + " "

print(result_str[:-1])