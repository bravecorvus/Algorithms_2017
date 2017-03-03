def multiply(x, y):
    n = len(x)
    if n == 1:
        xjoined = ''.join(x)
        yjoined = ''.join(y)
        print(xjoined)
        print(yjoined)
        
    xL = x[0:int(len(x)/2)]
    xR = x[int(len(x)/2):len(x)-1]
    yL = y[0:int(len(y)/2)]
    yR = y[int(len(y)/2):len(y)-1]
    p1 = multiply(xL, yL)
    p2 = multiply(xR, yR)
    p3 = multiply(xL + xR, yL + yR)
    return P1 * 2^n + (p3 - p1 - p2) * 2 ^ (n/2) + p2


(arg1, arg2) = (21, 20)
list1 = list(bin(arg1))[2:]
list2 = list(bin(arg2))[2:]
for count, data in enumerate(list1):
    list1[count] = int(data)
for count, data in enumerate(list2):
    list2[count] = int(data)
print(list1)
if len(list1) == len(list2):
    print(multiply(list1, list2))
elif len(list1) != len(list2):
    print("Pick values that give the same binary values")
