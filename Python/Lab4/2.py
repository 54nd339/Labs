# Remove duplicates from the list

lst = [int(i) for i in input("Enter the list: ").split()]
n = len(lst)
print("The list is: ", lst)

for i in range(n):
    for j in range(i+1, n):
        if lst[i] == lst[j]:
            lst.pop(j)

print("The list after removing duplicates is: ", lst)