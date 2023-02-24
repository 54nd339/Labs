# WAP to check an entered value is present in the set or not

set1 = set(int(i) for i in input("Enter the elements of set1: ").split())
value = int(input("Enter the value to be checked: "))

if value in set1:
    print("The value is present in the set")
else:
    print("The value is not present in the set")