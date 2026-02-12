import pandas as pd
import matplotlib.pyplot as plt

filename = input("Enter csv filename : ")
csvfiles = pd.read_csv(filename)
filename.close()

print("Csv file : ")
print(csvfiles)


print("Drawing line plot...")
csvfiles.plot(kind = "line")
plt.show()

print("drawing box plot...")
csvfiles.plot(kind = "box")
plt.show()

print("drawing histogram plot...")
csvfiles.plot(kind = "hist")
plt.show()

print("drawing bar plot...")
csvfiles.plot(kind = "bar")
plt.show()