n = int(input())
payout_a = int(input())
payout_b = int(input())
payout_c = int(input())

slot = 0
total_plays = 0

while n > 0:
  if slot == 0:
    payout_a += 1
    
    if payout_a == 35:
      n += 30
      payout_a = 0

  elif slot == 1:
    payout_b += 1
    
    if payout_b == 100:
      n += 60
      payout_b = 0

  elif slot == 2:
    payout_c += 1
    
    if payout_c == 10:
      n += 9
      payout_c = 0
    
  n -= 1
  total_plays += 1
  slot = (slot + 1) % 3
  
print('Martha plays {0} times before going broke.'.format(total_plays))