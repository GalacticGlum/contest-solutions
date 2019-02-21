eval_stack = []
for value in input().split():
    if value.isdigit():
        eval_stack.append(int(value))
    else:
        b = eval_stack.pop()
        a = eval_stack.pop()

        if value == '*':
            eval_stack.append(a * b)
        elif value == '/':
            eval_stack.append(a / b)
        elif value == '+':
            eval_stack.append(a + b)
        elif value == '-':
            eval_stack.append(a - b)
        elif value == '%':
            eval_stack.append(a % b)
        elif value == '^':
            eval_stack.append(a**b)

print(eval_stack.pop())