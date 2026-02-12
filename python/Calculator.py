
def add(x,y):
    return x+ y

def substract(x,y):
    return x - y

def multiply(x,y):
    return x * y

def divide(x,y):
    return x / y

print("Choices =")

print("1 = addition")
print("2 = substraction")
print("3 = multiplication")
print("4 = division")

choice = int(input("Enter Choice = "))

x = int(input("Enter 1 element : "))
y = int(input("Enter 2 element : "))

if choice == 1:
    print("Result = ", add(x,y))

elif choice == 2:
    print("Result = ", substraction(x,y))

elif choice == 3:
    print("Result = ", multiply(x,y))

elif choice == 4:
    print("Result = ", divide(x,y))

else:
    print("Invalid option")