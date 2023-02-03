# retrieve the particular substring from the given string

s = input("Enter a string: ")
print("The string is: ", s)

index = int(input("Enter the index: "))
length = int(input("Enter the length: "))

if index + length <= len(s):
    print("The substring is: ", s[index:index + length])
else:
    print("Invalid index and length")