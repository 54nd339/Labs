# take input of 5 integers and print the largest and smallest number

numbers = [int(input(f"Enter number {i + 1}: ")) for i in range(5)]

largest = numbers[0]
smallest = numbers[0]

for num in numbers:
    if num > largest:
        largest = num
    if num < smallest:
        smallest = num

print(f"The largest number is {largest}")
print(f"The smallest number is {smallest}")