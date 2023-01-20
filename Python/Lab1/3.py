# WAP to assign 2 integer values to 2 references and check whether the object is same or not

val1 = input("Enter first value: ")
val2 = input("Enter second value: ")

if id(val1) is id(val2):
    print("Same")
else:
    print("Not Same")