# WAP to print all distinct elements in a dictionary

dictionary = {k: v for k, v in (item.split(':') for item in input("Enter k:v pairs: ").split())}

distinct_elements = set(i for i in dictionary.values())

print("Distinct elements:", distinct_elements)