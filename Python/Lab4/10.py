# Convert a tuple of string to integers

tup = tuple(input("Enter the tuple: ").split())
print("The tuple is: ", tup)

tup2 = tuple(int(i) for i in tup)
print("The tuple after conversion is: ", tup2)