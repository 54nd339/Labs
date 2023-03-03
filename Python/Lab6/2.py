# WAP to pass a list to a function, now function adds 3 to each element of the list and returns the new list.

def add3(l):
    return [i+3 for i in l]

lst = [int(i) for i in input("Enter list: ").split()]
print(add3(lst))