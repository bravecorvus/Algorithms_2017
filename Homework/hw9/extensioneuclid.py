from math import floor

def extendedEuclid(a, b):
    if b == 0:
        return(1, 0, a)
    (x1, y1, d) = extendedEuclid(b, a%b)
    return(y1, x1-floor(a/b)*y1, d)
print(extendedEuclid(300, 100)[2])