n = int(input())
numbers = [int(input()) for i in range(n)]

for n in numbers:
  factors = []
  while n % 2 == 0:
    factors.append('2')
    n >>= 1
  
  for i in range(3, int(n**0.5 + 1), 2):
    while n % i == 0:
      factors.append(str(i))
      n //= i
  
  if n > 2:
    factors.append(str(n))

  print(' '.join(factors))