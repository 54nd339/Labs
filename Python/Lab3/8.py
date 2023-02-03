# Input 3 Strings and try to delete one of the string, also check the type of the string and the address of the string

s1 = input("Enter a string: ")
s2 = input("Enter a string: ")
s3 = input("Enter a string: ")

print("The string is: ", s1)
print("The string is: ", s2)
print("The string is: ", s3)

print("The type of the string is: ", type(s1))
print("The type of the string is: ", type(s2))
print("The type of the string is: ", type(s3))

print("The address of the string is: ", id(s1))
print("The address of the string is: ", id(s2))
print("The address of the string is: ", id(s3))

del s1
try:
    print("The string is: ", s1)
except:
    print("The string is deleted")