## STATUS: 30/50 (TLE)

from sys import maxsize as int_max
from copy import deepcopy
from queue import Queue

class State(object):
    def __init__(self, positions, turns_needed):
        self.positions = positions
        self.turns_needed = turns_needed

    def __hash__(self):
        return hash(self.positions)

    def __eq__(self, other):
        return hash(self) == hash(other)

    def __ne__(self, other):
        return not (self == other)

    def __str__(self): return '({0}, {1})'.format(self.positions, self.turns_needed)


while True:
    n = int(input())
    if n == 0:
        break
    
    coins = State(tuple([(int(i),) for i in input().split()]), 0)

    def copy_and_move(state, source, destination):
        list_positions = list(state.positions)

        source_position_list = list(list_positions[source])
        source_value_to_move = source_position_list.pop()

        list_positions[source] = tuple(source_position_list)

        destination_position_list = list(list_positions[destination])
        destination_position_list.append(source_value_to_move)

        list_positions[destination] = tuple(destination_position_list)

        return State(tuple(list_positions), state.turns_needed + 1)

    def get_all_possible_moves(coin_state):
        moves = []

        for i in range(n):
            current_position = coin_state.positions[i]
            if len(current_position) == 0: continue
            if i - 1 >= 0:
                left_position = coin_state.positions[i - 1]
                left_position_len = len(left_position)

                if left_position_len == 0 or current_position[len(current_position) - 1] < left_position[left_position_len - 1]:
                    moves.append(copy_and_move(coin_state, i, i - 1))

            if i + 1 < n:
                right_position = coin_state.positions[i+1]
                right_position_len = len(right_position)

                if right_position_len == 0 or current_position[len(current_position) - 1] < right_position[right_position_len - 1]:
                    moves.append(copy_and_move(coin_state, i, i + 1))


        return moves

    def is_solution(coin_state):
        return all(len(coin_state.positions[i]) == 1 for i in range(n)) and \
        all(coin_state.positions[i] <= coin_state.positions[i + 1] for i in range(n - 1))

    def find_solution(coin_state):
        visited = {}

        moves_to_look = Queue()
        moves_to_look.put(coin_state)

        min_turns = int_max
        while not moves_to_look.empty():
            current_state = moves_to_look.get()
            if current_state.turns_needed >= min_turns:
                continue

            moves = get_all_possible_moves(current_state)

            for move in moves:
                if move in visited and move.turns_needed >= visited[move]:
                    continue

                visited[move] = move.turns_needed
                if is_solution(move) and move.turns_needed < min_turns:
                    min_turns = move.turns_needed
                    continue

                moves_to_look.put(move)

        if min_turns == int_max: return 'IMPOSSIBLE'
        
        return min_turns

    if is_solution(coins):
        print(coins.turns_needed)
    else:
        print(find_solution(coins))