from math import floor
def multiply(x, y):
    if y == 0:
        return 0
    z = multiply(x, floor(y/2))
    if y % 2 == 0:
        return 2 * z
    else:
        return x + 2 * z

print(multiply(5, 10))