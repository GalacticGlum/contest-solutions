import math

class Vector(object):
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z

        self.count = 0

    def __add__(self, other):
        return Vector(
            self.x + other.x,
            self.y + other.y,
            self.z + other.z
        )

    def __mul__(self, other):
        return Vector(
            self.x * other,
            self.y * other,
            self.z * other
        )

    def __truediv__(self, other):
        return Vector(
            self.x / other,
            self.y / other,
            self.z / other
        )

    def __neg__(self):
        return self * -1

    def dot(self, other):
        return self.x * other.x + self.y * other.y + self.z * other.z

    def cross(self, other):
        return Vector(
            self.y * other.z - self.z * other.y,
            self.y * other.x - self.x * other.z,
            self.x * other.y - self.y * other.x      
        )

    def __iter__(self):
        return self
    
    def __next__(self):
        self.count += 1
        if self.count > 3:
            raise StopIteration

        if self.count == 1:
            return self.x
        elif self.count == 2:
            return self.y
        elif self.count == 3:
            return self.z

    def __str__(self):
        return '{0} {1} {2}'.format(round(self.x, 6), round(self.y, 6), round(self.z, 6))
        

class Matrix3(object):
    def __init__(self, ax, ay, az, bx, by, bz, cx, cy, cz):
        self.a = Vector(ax, ay, az)
        self.b = Vector(bx, by, bz)
        self.c = Vector(cx, cy, cz) 

    def dot(self, other):
        return Vector(
            self.a.dot(other),
            self.b.dot(other),
            self.c.dot(other)
        )

def compute_rotation_matrix(axis, theta):
    axis = axis / math.sqrt(axis.dot(axis))
    a = math.cos(theta / 2.0)
    b, c, d = -axis * math.sin(theta / 2.0)
    aa, bb, cc, dd = a*a, b*b, c*c, d*d
    bc, ad, ac, ab, bd, cd = b*c, a*d, a*c, a*b, b*d, c*d
    return Matrix3(aa+bb-cc-dd, 2*(bc+ad), 2*(bd-ac),
                   2*(bc-ad), aa+cc-bb-dd, 2*(cd+ab),
                   2*(bd+ac), 2*(cd-ab), aa+dd-bb-cc)

test_cases = int(input())
for i in range(test_cases):
    components = [float(i) for i in input().split()]

    v = Vector(*components[:3])
    a = Vector(*components[3:len(components)-1])
    theta = components[len(components) - 1]

    r = compute_rotation_matrix(a, theta).dot(v)
    print(r)