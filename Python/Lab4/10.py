# Convert a tuple of string to integers

tup = tuple(map(str, input("Enter the tuple: ").split()))
print("The tuple is: ", tup)

for i in range(len(tup)):
    tup[i] = int(tup[i])

print("The tuple after conversion is: ", tup)