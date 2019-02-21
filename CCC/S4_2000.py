tee_to_hole_distance = int(input())
n_clubs = int(input())
distances = [int(input()) for i in range(n_clubs)]

distances.sort()

strokes = 0

cache = [5280 for i in range(tee_to_hole_distance+1)]
cache[0] = 0

for i in range(tee_to_hole_distance+1):
    for j in range(n_clubs):
        nd = distances[j] + i    
        if nd <= tee_to_hole_distance:
            cache[nd] = min(cache[nd], cache[i] + 1)

if cache[tee_to_hole_distance] == 5280:
    print('Roberta acknowledges defeat.')
else:
    print('Roberta wins in {0} strokes.'.format(cache[tee_to_hole_distance]))
