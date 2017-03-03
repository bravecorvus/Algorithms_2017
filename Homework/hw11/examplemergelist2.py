def mergesort(lst):
    """Input a list of numbers, return a sorted version."""
    n = len(lst)
    if n > 1:
        return merge(mergesort(lst[:int(n/2)]), mergesort(lst[int(n/2):]))
    else:
        return lst

def merge(x, y):
    if not isinstance(x, list):
        x = [x]
    if not isinstance(y, list):
        y = [y]
    k, l = len(x), len(y)
    if k == 0:
        return y
    if l == 0:
        return x
    if x[0] <= y[0]:
        return [x[0]] + merge(x[1:], y)
    else:
        return [y[0]] + merge(x, y[1:])

a = [89, 113, 295, 98, 93, 55, 122, 25, 87, 209, 
275, 266, 128, 276, 281, 157, 227, 212, 267, 7, 
240, 223, 31, 236, 294, 190, 72, 279, 212, 98, 
198, 206, 195, 267, 105, 58, 256, 74, 169, 159, 
30, 110, 269, 221, 224, 80, 118, 197, 156, 65, 
183, 82, 107, 164, 179, 280, 282, 213, 223, 265, 
101, 269, 65, 168, 130, 88, 203, 10, 146, 62, 
250, 11, 64, 11, 25, 217, 53, 145, 300, 59, 
89, 48, 4, 275, 163, 234, 239, 297, 101, 180, 
190, 92, 91, 138, 70, 126, 165, 299, 20, 65]

print(mergesort(a))