#!/usr/bin/python
from sys import exit

def findkey(dictionary, stack):
    returnlist = []
    if len(stack) == 0:
        newmin = 100000
        for i in dictionary.keys():
            newmin = min(newmin, i)
        returnlist.append(newmin)
    else:
        for i in stack:
            returnlist.append(i)
    return returnlist

def findMinimumSemesters(dictionary, totalstack = [], stack = [], steps = 0):
    if len(stack) == len(dictionary):
        print("Taking all classes will take at minimum", steps, "semesters.")
        exit();
    keys = findkey(dictionary, stack)
    for i in keys:
        for p in dictionary[i]:
            stack.append(p)
    for i in stack:
        if i not in totalstack:
            totalstack.append(i)
        else:
            stack.remove(i)
    steps+=1
    findMinimumSemesters(dictionary, totalstack, stack, steps)



    


dictionary = {121:[241, 251],
241:[273, 276],
251:[259, 263, 273, 276, 284, 300, 315, 333, 336, 350, 390],
259:[390],
263:[390],
273:[390],
276:[390],
284:[390],
300:[390],
315:[390],
333:[390],
336:[390],
350:[390],
390:[]}

findMinimumSemesters(dictionary)