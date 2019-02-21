from bisect import bisect_left, bisect_right

def get_palindrome(n, odd):
  result = n
  if odd:
    n //= 10

  while n > 0:
    result *= 10
    result += n % 10
    n //= 10

  return result

def generate_palindromes(max_n):
  palindromes = []

  index = 1
  result = get_palindrome(index, False)
  while result <= max_n:
    if result % k == 0:
      palindromes.append(result)

    index += 1
    result = get_palindrome(index, False)

  index = 1
  result = get_palindrome(index, True)
  while result <= max_n:
    if result % k == 0:
      palindromes.append(result)

    index += 1
    result = get_palindrome(index, True)

  return sorted(palindromes)

q, k = map(int, input().split())

queries = []
max_n = 0
for _ in range(q):
  m, n = map(int, input().split())
  if n > max_n:
    max_n = n

  queries.append((m, n))

palindromes = generate_palindromes(max_n)

for m, n in queries:
  result = bisect_right(palindromes, n) - bisect_left(palindromes, m)
  print(result)