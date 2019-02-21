from math import floor, ceil

n = int(input())
for i in range(n):
    teams = int(input())

    rounds = 0
    undefeated = teams
    one_loss = 0
    eliminated = 0

    while True:
        print('Round {0}: {1} undefeated, {2} one-loss, {3} eliminated'.format(rounds, undefeated, one_loss, eliminated))

        if undefeated + one_loss == 1:
            break
        
        rounds += 1
        if undefeated + one_loss == 2:
            if undefeated != 0:
                undefeated -= 1
                one_loss += 1
            elif undefeated == 0:
                one_loss -= 1
                eliminated += 1
        else:
            b = one_loss >> 1
            one_loss -= b
            eliminated += b

            b = undefeated >> 1
            undefeated -= b
            one_loss += b

    print('There are {0} rounds.'.format(rounds))