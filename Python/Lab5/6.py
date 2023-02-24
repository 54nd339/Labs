# WAP to merge 2 dictionaries

dict1 = {k: v for k, v in (item.split(':') for item in input("Enter k:v pairs: ").split())}
dict2 = {k: v for k, v in (item.split(':') for item in input("Enter k:v pairs: ").split())}
print("First dictionary:", dict1)
print("Second dictionary:", dict2)

dict1.update(dict2)

print("Merged dictionary:", dict1)