def mergeSort(alist):
    print("Splitting ", alist)
    if len(alist)>1:
        mid = len(alist)//2
        lefthalf = alist[:mid]
        righthalf = alist[mid:]
        mergeSort(lefthalf)
        mergeSort(righthalf)
        i = 0
        j = 0
        k = 0
        while i < len(lefthalf) and j < len(righthalf):
            if lefthalf[i] < righthalf[j]:
                alist[k] = lefthalf[i]
                i += 1
            else:
                alist[k] = righthalf[j]
                j+=1
            k+=1
        while i < len(lefthalf):
            alist[k]=lefthalf[i]
            i+=1
            k+=1
        while j < len(righthalf):
            alist[k]= righthalf[j]
            j+=1
            k+=1
    print("Merging ", alist)

alist = [89, 113, 295, 98, 93, 55, 122, 25, 87, 209, 
275, 266, 128, 276, 281, 157, 227, 212, 267, 7, 
240, 223, 31, 236, 294, 190, 72, 279, 212, 98, 
198, 206, 195, 267, 105, 58, 256, 74, 169, 159, 
30, 110, 269, 221, 224, 80, 118, 197, 156, 65, 
183, 82, 107, 164, 179, 280, 282, 213, 223, 265, 
101, 269, 65, 168, 130, 88, 203, 10, 146, 62, 
250, 11, 64, 11, 25, 217, 53, 145, 300, 59, 
89, 48, 4, 275, 163, 234, 239, 297, 101, 180, 
190, 92, 91, 138, 70, 126, 165, 299, 20, 65]

mergeSort(alist)
print(alist)