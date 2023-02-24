# WAP to multiply all values in a dictionary

dictonary = {k: v for k, v in (item.split(':') for item in input("Enter k:v pairs: ").split())}

product = 1
for i in dictonary:
    product *= int(dictonary[i])

print("Product:", product)