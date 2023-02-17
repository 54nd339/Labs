# Check whether a particular substring is present in the given string or not, also print the given string

s = input("Enter a string: ")
print("The string is", s)

sub = input("Enter a substring: ")
print("The substring is", sub)

if sub in s:
    print("The substring is present in the string")