n = int(input())
first_names = input().split(' ')
second_names = input().split(' ')

def check_names():
    for i in range(n):
        if first_names[i] == second_names[i]:
            return False

        student = first_names[i]
        partner = second_names[i]

        for j in range(n):
            has_match = (first_names[j] == student and second_names[j] != partner)
            has_reverse_match = (second_names[j] == student and first_names[j] != partner)

            if has_match or has_reverse_match:          
                return False

    return True

if check_names():
    print('good')
else:
    print('bad')