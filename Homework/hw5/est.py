def matrixElementsSum(matrix):
    outeriterator = len(matrix)
    boolarray = []
    for i in range(0, outeriterator):
        boolarray.append([]);
    for i in range(0, outeriterator):
        for x in range(0, len(matrix[0])):
            if i == 0:
                if matrix[i][x] != 0:
                    boolarray[0].append(True)
                else:
                    boolarray[0].append(False)
            else:
                t = True
                for z in range(0, i):
                    if matrix[z][x] == 0:
                        t = False
                boolarray[i].append(t)
    print(boolarray)
    price = 0
    for i in range(0, outeriterator):
        for x in range(0, len(matrix[0])):
            if boolarray[i][x] == True:
                price += matrix[i][x]
    return(price)



matrix = [[0, 1, 1, 2], 
          [0, 5, 0, 0], 
          [2, 0, 3, 3]]

print(matrixElementsSum(matrix))