def binsearch(arg, val):
    if len(arg) == 1:
        if (arg[0] == val):
            return True
    if arg[len(arg)/2-1] > val:
        retbool = binsearch(arg[0:len(arg)/2-1], val)
    elif arg[len(arg)/2-1] < val:
        retbool = binsearch(arg[len(arg)/2-1:], val)
    elif arg[len(arg)/2-1] == val:
        retbool = True
    else:
        retbool = False
    return(retbool)