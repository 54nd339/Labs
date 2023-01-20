# WAP to init a 3 digit number and display its reverse

num = int(input("Enter a 3 digit number: "))
print("Reverse: ", num % 10 * 100 + num // 10 % 10 * 10 + num // 100)