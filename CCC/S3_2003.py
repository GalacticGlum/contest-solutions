from queue import Queue

class Room(object):
    def __init__(self):
        self.tiles = []
    
    def size(self): return len(self.tiles)

    def add_tile(self, tile):
        if tile in self.tiles: return
        if tile.room != None:
            tile.room.tiles.remove(tile)

        tile.room = self
        self.tiles.append(tile)

class Tile(object):
    def __init__(self, is_wall, x, y):
        self.is_wall = is_wall
        self.x = x
        self.y = y
        self.room = None
    
    def __str__(self): return 'I' if self.is_wall else '.'
    def __repr__(self): return '({0}, {1}) = {2}'.format(self.x, self.y, self.__str__())

class Grid(object):
    def __init__(self, width, height):
        self.data = []
        for i in range(height):
            self.data.append([None] * width)
            values = input()
            for j in range(min(width, len(values))):
                self.data[i][j] = Tile(values[j] == 'I', j, i)

        self.width = width
        self.height = height
        self.rooms = None

    def get(self, x, y): 
        if x >= self.width or x < 0 or y >= self.height or y < 0: return None
        return self.data[y][x]

    def __to_str_list(self): return [''.join([str(j) for j in i]) for i in self.data]
    def get_neighbours(self, tile):
        return (
            self.get(tile.x, tile.y + 1),
            self.get(tile.x + 1, tile.y),
            self.get(tile.x, tile.y - 1),
            self.get(tile.x - 1, tile.y)
        )

    def find_rooms(self):
        self.rooms = []
        for x in range(self.width):
            for y in range(self.height):
                tile = self.get(x, y)
                if tile.is_wall: continue

                old_room = tile.room     
                self.flood_fill(tile, old_room)

        return self.rooms
    
    def flood_fill(self, source_tile, old_room):
        room = old_room if old_room != None else Room()
        tile_queue = Queue()
        tile_queue.put(source_tile)

        connected_to_end = False
        while not tile_queue.empty():
            current_tile = tile_queue.get()

            if current_tile.room == room: continue
            room.add_tile(current_tile)

            for neighbour in self.get_neighbours(current_tile):
                if neighbour != None and not neighbour.is_wall:
                    tile_queue.put(neighbour)
        
        if connected_to_end:
            room.tiles.clear()
            return

        if old_room == None:
            self.rooms.append(room)

    def __str__(self): return '\n'.join(self.__to_str_list())
    def __repr__(self): return self.__str__()

total_flooring = int(input())
height = int(input())
width = int(input())

grid = Grid(width, height)
grid.find_rooms()

rooms_by_largest = sorted(grid.rooms, key=lambda room: room.size(), reverse=True)

current_flooring = total_flooring
room_count = 0

for room in rooms_by_largest:
    size = room.size()
    if current_flooring < size: break
    current_flooring -= size
    room_count += 1

if room_count == 1:
    print('{0} room, {1} square metre(s) left over'.format(room_count, current_flooring))
else:
    print('{0} rooms, {1} square metre(s) left over'.format(room_count, current_flooring))