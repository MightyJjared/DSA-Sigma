
file = open("data.txt", "r")

word = file.read().split()
file.close()
unique_word = sorted(set(word))

print(unique_word)