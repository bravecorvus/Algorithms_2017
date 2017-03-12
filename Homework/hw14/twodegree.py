#!/usr/bin/python
def twodegree(arg):
    for count, data in enumerate(arg):
        counter = 0
        for count2, data2 in enumerate(data):
            counter += len(arg[data2])
        print("twodegree[u] where u is", count, "is", counter, "degrees.")


representation = [[1, 2], [0, 2], [0, 1, 3], [2]]
twodegree(representation)