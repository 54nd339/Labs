#  Create a tuple with nested tuple or list and access and print the elements of nested tuple and list

tup = tuple()

while True:
    print("\n1. Add a list to the tuple")
    print("2. Add a tuple to the tuple")
    print("0. Exit")

    choice = int(input("\nEnter your choice: "))
    if choice == 1:
        lst = list(int(i) for i in input("Enter the list: ").split())
        tup += (lst,)
    elif choice == 2:
        tup2 = tuple(int(i) for i in input("Enter the tuple: ").split())
        tup += (tup2,)
    else:
        break

for i in tup:
    print(i)