# Program 30: Count frequency of tuple elements

n = int(input("How many elements in tuple? "))

temp_list = []
for i in range(n):
    value = int(input("Enter element: "))
    temp_list.append(value)

t = tuple(temp_list)

frequency = {}

for item in t:
    if item in frequency:
        frequency[item] += 1
    else:
        frequency[item] = 1

print("Frequency of elements:")
for key in frequency:
    print(key, ":", frequency[key])
