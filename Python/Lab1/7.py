# WAP to delete a particular variable or reference

var = int(input("Enter a value: "))
print("Value:", var)
del var
try:
    print("Value:", var)
except NameError:
    print("Variable does not exist")