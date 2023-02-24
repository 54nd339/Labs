# Print a specified list after removing 2nd and 5th index elements

lst = [int(i) for i in input("Enter the list: ").split()]
n = len(lst)
print("The list is: ", lst)

if n > 2:
    lst.pop(2)
if n > 5:
    lst.pop(5)

print("The list after removing 2nd and 5th index elements is: ", lst)