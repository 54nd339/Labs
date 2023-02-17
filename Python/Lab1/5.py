# WAP to init a 3 digit number and perform addition of its first and last digit

num = int(input("Enter a 3 digit number: "))
res = num % 10 + num // 100
print("Result:", res)