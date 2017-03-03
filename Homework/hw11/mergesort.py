#Python code for Regular Merge Sort as described in the book, and mergeremoveduplicates/mergesortremoveduplicates which duplicate most of the functionality, but adds the ability to remove duplicates in nlogn time.
# It will be O(n*log(n)) time because it is using the same branching factor, the same b, and while only multiplying another constant c to the "glueing the recursive parts back together" portion of the recursive equation. Hence, by the Master Theorum, it should share the same "worst case" as regular merge sort.

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

def mergeremoveduplicates(x, y):
    if not isinstance(x, list):
        x = [x]
    if not isinstance(y, list):
        y = [y]
    k, l = len(x), len(y)
    if k == 0:
        return y
    if l == 0:
        return x
    if x[0] < y[0]:
        return [x[0]] + mergeremoveduplicates(x[1:], y)
    elif x[0] > y[0]:
        return [y[0]] + mergeremoveduplicates(x, y[1:])
    elif x[0] == y[0]:
        return mergeremoveduplicates(x, y[1:])


def mergesort(a):
    if len(a) > 1:
        return merge(mergesort(a[:int(len(a)/2)]),
            mergesort(a[int(len(a)/2):]))
    else:
        return a

def mergesortremoveduplicates(a):
    if len(a) > 1:
        return mergeremoveduplicates(mergesortremoveduplicates(a[:int(len(a)/2)]),
            mergesortremoveduplicates(a[int(len(a)/2):]))
    else:
        return a


a = [89, 113, 295, 98, 93, 55, 122, 25, 87, 209, 
275, 266, 128, 276, 281, 157, 227, 212, 267, 7, 
240, 223, 31, 236, 294, 190, 72, 279, 212, 98, 
198, 206, 195, 267, 105, 58, 256, 74, 89, 169, 159, 
30, 110, 269, 221, 224, 80, 118, 197, 156, 65, 
183, 82, 107, 164, 179, 280, 282, 213, 223, 265, 
101, 269, 65, 168, 130, 88, 203, 10, 146, 62, 
250, 11, 64, 11, 25, 217, 53, 145, 300, 59, 
89, 48, 4, 275, 163, 234, 239, 297, 101, 180, 
190, 92, 91, 138, 70, 126, 165, 299, 20, 65]

print(mergesort(a))


print(mergesortremoveduplicates(a))
