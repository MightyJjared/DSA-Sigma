import pandas as pd

n = int(input("Enter the number of rows : "))

names = []
ages = []
street = []

for i in range(n):
    name = input("Enter name :")
    age = int(input("Enter age : "))
    city = input("Enter city ; ")

    names.append(name)
    ages.append(age)
    street.append(city)

data = {
    "name" : names,
    "age" : ages,
    "city" : street
}

db = pd.DataFrame(data)

print(db)