filename = input("Enter filename : ")

file = open(filename, "r")
text = file.read()
file.close()

word = text.split()

unique_words = set(word)

order = sorted(unique_words)

for w in order:
    print(w)