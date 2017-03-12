#!/usr/bin/python
def reverseGraph(arg):
    edges = []
    for count, data in enumerate(arg):
        for count2, data2 in enumerate(data):
            edges.append([data2, count])
    print(edges)

representation = [[1, 2], [0, 2], [0, 1, 3], [2]]
reverseGraph(representation)