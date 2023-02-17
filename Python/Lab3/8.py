# Input 3 Strings and try to delete one of the string, also check the type of the string and the address of the string

s1 = input("Enter a string: ")
s2 = input("Enter a string: ")
s3 = input("Enter a string: ")

del s3

print(f"String: {s1}, Type: {type(s1)}, Address: {id(s1)}")
print(f"String: {s2}, Type: {type(s2)}, Address: {id(s2)}")

try:
    print(f"String: {s3}, Type: {type(s3)}, Address: {id(s3)}")
except:
    print("String s3 not found")