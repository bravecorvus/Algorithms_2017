def recursive_exponentiation(x, y):
    """input: x and y each n-bit long
    output: x^y """
    if y == 0:
        return 1
    z = recursive_exponentiation(x, y//2)
    if y%2 == 0:
        return z*z
    else:
        return x*z*z

print(recursive_exponentiation(10, 5))