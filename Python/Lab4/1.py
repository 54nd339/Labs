# WAP to find the second largest and second smallest element in the list.

lst = list(map(int, input("Enter the list: ").split()))
print("The list is: ", lst)

# lst.sort()
# print("The second largest element is: ", lst[-2])
# print("The second smallest element is: ", lst[1])

# Without using sort() function
smallest = lst[0]
second_smallest = lst[0]
largest = lst[0]
second_largest = lst[0]

for i in range(len(lst)):
    if lst[i] < smallest:
        second_smallest = smallest
        smallest = lst[i]
    elif lst[i] < second_smallest:
        second_smallest = lst[i]

    if lst[i] > largest:
        second_largest = largest
        largest = lst[i]
    elif lst[i] > second_largest:
        second_largest = lst[i]

print("The second largest element is: ", second_largest)
print("The second smallest element is: ", second_smallest)