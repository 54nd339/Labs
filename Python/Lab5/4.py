# WAP that finds all pairs of elements in a given list whose sum is equal to a given number

list = [int(i) for i in input("Enter the elements of the list: ").split()]
sum = int(input("Enter the sum: "))

unique_nums = set()

for i in list:
    if sum - i in unique_nums:
        print("(", i, ",", sum - i, ")")
    unique_nums.add(i)