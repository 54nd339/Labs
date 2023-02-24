# WAP to convert a dictionary to a list of lists

dictionary = {k: v for k, v in (item.split(':') for item in input("Enter k:v pairs: ").split())}

list_of_lists = [[i, dictionary[i]] for i in dictionary]

print("List of lists:", list_of_lists)