import numpy as np

n = int(input("Enter number of elements : "))

elements = []

for i in range(n):
    num = int(input("Enter element : "))
    elements.append(num)

arr = np.array(elements)

meanv = arr.mean()
stdv = arr.std()
minv = arr.min()
maxv = arr.max()

print(meanv)
print(stdv)
print(minv)
print(maxv)

