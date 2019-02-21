n = int(input())
values = [int(input()) for i in range(n)]
values.sort(reverse=True)

min_time = 0
for i in range(n):
    min_time += (values[i] % 10007) * (values[n-i-1] % 10007)

print(min_time % 10007)