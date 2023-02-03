# Check whether the given String is a Palindrome or not

s = input("Enter a string: ")
print("The string is: ", s)

if s == s[::-1]:
    print("The string is a palindrome")
else:
    print("The string is not a palindrome")