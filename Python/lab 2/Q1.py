# // enter a 3 digit number and check if its a palindrome or not

num = (input("Enter a 3 digit number: "))
rev = num[::-1]

if(num == rev):
    print("The number is a palindrome")

else:
    print("The number is not a palindrome")
