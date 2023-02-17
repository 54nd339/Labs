# Enter a String and display it, also find the length of the string without using len() function

s = input("Enter a string: ")
print("The string is", s)

length = 0
for i in s:
    length += 1

print("The length of the string is", length)