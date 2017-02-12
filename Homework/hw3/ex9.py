x = []
for i in range(0, 100):
    x.append(i)
# print(x)

p = []
for i in range(0, 100):
    print(sum(x[0:i]))
    p.append(sum(x[0:i]))

print(sum(p))