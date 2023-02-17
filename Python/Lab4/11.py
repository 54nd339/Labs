# CHeck the frequency of a specific element in a tuple

tup = tuple(int(i) for i in input("Enter the tuple: ").split())
print("The tuple is: ", tup)

element = int(input("Enter the element to find: "))
count = 0

for i in tup:
    if i == element:
        count += 1

if count == 0:
    print("Element not found")
else:
    print(f"Element found {count} times")
