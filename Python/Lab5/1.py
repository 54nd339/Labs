# WAP to check a common program is present in both the sets

set1 = set(int(i) for i in input("Enter the elements of set1: ").split())
set2 = set(int(i) for i in input("Enter the elements of set2: ").split())

print("Common elements in both the sets are: ", set1 & set2)