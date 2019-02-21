notes = [int(i) for i in input().split()]
if all(notes[i] <= notes[i+1] for i in range(len(notes)-1)):
    print('ascending')
elif all(notes[i] >= notes[i+1] for i in range(len(notes)-1)):
    print('descending')
else:
    print('mixed')