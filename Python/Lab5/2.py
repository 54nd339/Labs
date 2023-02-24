#  WAP to perform union, intersection and set difference of two sets

set1 = set(int(i) for i in input("Enter the elements of set1: ").split())
set2 = set(int(i) for i in input("Enter the elements of set2: ").split())

print("Union of the sets is: ", set1 | set2)
print("Intersection of the sets is: ", set1 & set2)
print("Set difference of the sets is: ", set1 - set2)