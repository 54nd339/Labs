# WAP to delete a particular variable or reference

def show(foo):
    try:
        print("Value: ", foo)
    except NameError:
        print("Variable does not exist")

var = int(input("Enter a value: "))
show(var)
del var
show(var)