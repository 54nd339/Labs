#  check if given number is a perfect number or not

num = int(input("Enter a number: "))
sum = 0

for i in range(1, num):
    if(num % i == 0):
        sum = sum + i


if(sum == num):
    print("The number is a perfect number")
else:
    print("The number is not a perfect number")