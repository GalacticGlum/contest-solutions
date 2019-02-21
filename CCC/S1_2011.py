n = int(input())
s_count = 0
t_count = 0
for _ in range(n):
  line = input()
  s_count += line.count('s') + line.count('S')
  t_count += line.count('t') + line.count('T')

if t_count > s_count: print('English')
if t_count == s_count or t_count < s_count: print('French')
