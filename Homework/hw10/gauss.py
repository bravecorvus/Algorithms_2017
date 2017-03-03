a = 10 
b = 20 
c = 20
d = 30
i = 100

product1 = a*c - b*d + (b*c*i + a*d*i)
product2 = (a + b*i)*(c + d*i)
print(product1 == product2)