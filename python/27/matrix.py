import numpy as np

rows = int(input("Enter number of rows for matrix A: "))
cols = int(input("Enter number of cols for matrix A: "))

A = []

for i in range(rows):
    x = []
    for j in range(cols):
        value = int(input("Enter elements :"))
        x.append(value)
    A.append(x)

rows = int(input("Enter number of rows for matrix B: "))
cols = int(input("Enter number of cols for matrix B: "))

B = []

for i in range(rows):
    x = []
    for j in range(cols):
        value = int(input("Enter elements :"))
        x.append(value)
    B.append(x)

A = np.array(A)
B = np.array(B)

result = A.dot(B)

print(A)
print("------")
print(B)
print("------")
print(result)