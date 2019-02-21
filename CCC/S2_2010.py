k = int(input())

encoding_map = {}
for i in range(k):
    character, encoding = input().split()
    encoding_map[encoding] = character

sequence = input()
message = str()

n = len(sequence)
ptr = 0
while ptr < n:
    current_encoding = str()
    for j in range(ptr, n):
        current_encoding += sequence[j]
        if current_encoding in encoding_map:
            message += encoding_map[current_encoding]
            ptr = j
            break
        
    ptr += 1

print(message)