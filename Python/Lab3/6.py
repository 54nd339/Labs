# Input 2 Strings and concatenate them, also repeat the particular string n times

s1 = input("Enter a string: ")
s2 = input("Enter a string: ")

print("The string is", s1)
print("The string is", s2)

print("The concatenated string is", s1 + s2)

n = int(input("\nEnter a number: "))
print(f"The string is repeated {n} times: {(s1 + s2) * n}")