#  enter a number and find the reverse of it

num = int(input("Enter a number: "))
rev = 0

while(num > 0):
    digit = num % 10
    rev = rev * 10 + digit
    num = num // 10

print("The reverse of the number is: ", rev)