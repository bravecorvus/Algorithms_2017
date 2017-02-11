i = []
i.append(0)
i.append(1)
i.append(3)
i.append(4)
i.append(6)

f = []
for z in range(0, 34):
    f.append(z)

for data in f:
    if data < 5:
        continue
    if data%2 == 0:
        i.append(i[data-1]+2)
    elif data%2 != 0:
        i.append(i[data-1]+1)
print(i)

p = 0
for x in i:
    p += x

print(p)