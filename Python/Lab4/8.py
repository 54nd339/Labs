# COnvert a list to a tuple

lst = [int(i) for i in input("Enter the list: ").split()]
print("The list is: ", lst)

tup = tuple(lst)
print("The tuple is: ", tup)