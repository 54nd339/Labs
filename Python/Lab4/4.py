# Append a list to  another list

lst1 = [int(i) for i in input("Enter the list 1: ").split()]
lst2 = [int(i) for i in input("Enter the list 2: ").split()]

lst1.extend(lst2)
print("The list after appending is: ", lst1)

# Without using extend() function
for i in lst2:
    lst1.append(i)

print("The list after appending is: ", lst1)