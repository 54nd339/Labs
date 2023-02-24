# WAP to sort a dictionary by key

dictionary = {k: v for k, v in (item.split(':') for item in input("Enter k:v pairs: ").split())}

sorted_dictionary = {i: dictionary[i] for i in sorted(dictionary)}

print("Sorted dictionary:", sorted_dictionary)