# Remove the kth element and print the updated list

lst = list(int(i) for i in input("Enter the list: ").split())
k = int(input("Enter the value of k: "))

print("The list is: ", lst)

if k < len(lst):
    lst.pop(k)
else:
    print("Invalid index")

print("The list after removing kth element is: ", lst)