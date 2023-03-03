# WAP to pass a number to a function, then print 1 to that number using recursion.

def print1toN(n):
    if n > 1:
        print1toN(n-1)
    print(n)

n = int(input("Enter number: "))
print1toN(n)