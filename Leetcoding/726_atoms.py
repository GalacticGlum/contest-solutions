atoms = dict()
def count_atoms(base_formula):
    stack=[(base_formula,1)]
    while len(stack) > 0:
        formula,coeff=stack.pop()
        if formula.count('(') == 0:
            # parse formula without any groups
            for i in range(len(formula)):
                char=formula[i]
                if char.isupper():
                    name = char
                    c=str()
                    # find name
                    while i < len(formula)-1 and formula[i+1].islower():
                        i+=1
                        name+=formula[i]

                    # find coefficient
                    while i < len(formula)-1 and formula[i+1].isdigit():
                        i+=1
                        c+=formula[i]

                    c=int(c)if len(c)>0 else 1
                    if name not in atoms:
                        atoms[name]=0
                    atoms[name]+=c*coeff
        else:
            start_group_index = 0
            parentheses_count = 0
            result_formula = formula

            for i in range(len(formula)):
                char = formula[i]
                if char == '(':
                    if parentheses_count == 0:
                        start_group_index = i

                    parentheses_count += 1
                elif char == ')':
                    parentheses_count -= 1
                    if parentheses_count == 0:
                        c = str()
                        for j in range(i, len(formula)):
                            if not formula[j].isdigit(): continue
                            c += formula[j]
            
                        c=int(c)if len(c)>0 else 1
                        # get the group without parentheses
                        group = formula[start_group_index+1:i]
                        stack.append((group,c*coeff))
                        # hacky solution to get rid of all the groups that we find since they have already been processed
                        # the result will be that formula consists of the atoms without any group...
                        result_formula=result_formula.replace('('+group+')'+(str(c) if c > 1 else ''), '', 1)

            # process the groupless formula
            stack.append((result_formula,coeff))

count_atoms(input())
# construct output
output = str()
for key in sorted(atoms.keys()):
    coeff=str(atoms[key]) if atoms[key]>1 else ''
    output+=key+coeff

print(output)