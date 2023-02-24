# Find the index of an element in a list

lst = [int(i) for i in input("Enter the list: ").split()]
print("The list is: ", lst)

element = int(input("Enter the element to find: "))
index = -1

for i in range(len(lst)):
    if lst[i] == element:
        index = i
        break

if index == -1:
    print("Element not found")
else:
    print(f"Element found at index {index}")