# enter a 3 digit number and check if its a palindrome or not

num = int(input("Enter a 3 digit number: "))

if 100 <= num <= 999:
    if num // 100 == num % 10:
        print(num, "is a palindrome")
    else:
        print(num, "is not a palindrome")
else:
    print("Invalid input, please enter a 3 digit number")