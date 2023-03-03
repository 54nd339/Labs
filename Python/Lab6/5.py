# WAP to define a function with an argument which can take any number of arguments.

def any(*args):
    print(args)

num = [int(i) for i in input("Enter numbers: ").split()]
any(*num)
any(num)