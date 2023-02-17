# COnvert a list to a tuple

lst = list(map(int, input("Enter the list: ").split()))
print("The list is: ", lst)

tup = tuple(lst)
print("The tuple is: ", tup)