# To change position of nth element with n+1 element in a list

lst = list(map(int, input("Enter the list: ").split()))
n = int(input("Enter the value of n: "))

print("The list is: ", lst)

if n < len(lst) - 1:
    lst[n], lst[n+1] = lst[n+1], lst[n]
else:
    print("Invalid index")

print("The list after swapping is: ", lst)