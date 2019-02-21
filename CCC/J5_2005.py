word = input()
while word != 'X':
    while 'BAS' in word or 'ANA' in word:
        word = word.replace('BAS', 'A')
        word = word.replace('ANA', 'A')

    result = 'YES' if word == 'A' else 'NO'
    print(result)

    word = input()