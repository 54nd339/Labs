# take input of 5 integers and print the largest and smallest number

num1 = int(input("Enter a number 1: "))
num2 = int(input("Enter a number 2: "))
num3 = int(input("Enter a number 3: "))
num4 = int(input("Enter a number 4: "))
num5 = int(input("Enter a number 5: "))

# # largest number
# if(num1 > num2 and num1 > num3 and num1 > num4 and num1 > num5):
#     print("The largest number is: ", num1)
# elif(num2 > num1 and num2 > num3 and num2 > num4 and num2 > num5):
#     print("The largest number is: ", num2)
# elif(num3 > num1 and num3 > num2 and num3 > num4 and num3 > num5):
#     print("The largest number is: ", num3)

# elif(num4 > num1 and num4 > num2 and num4 > num3 and num4 > num5):
#     print("The largest number is: ", num4)
# else:    
#     print("The largest number is: ", num5)

# smallest number
if(num1 < num2 and num1 < num3 and num1 < num4 and num1 < num5):
    print("The smallest number is: ", num1)
elif(num2 < num1 and num2 < num3 and num2 < num4 and num2 < num5):
    print("The smallest number is: ", num2)
elif(num3 < num1 and num3 < num2 and num3 < num4 and num3 < num5):
    print("The smallest number is: ", num3)
elif(num4< num1 and num4 < num2 and num4 < num3 and num4 < num5):
    print("The smallest number is: ", num4)
else:   
    print("The smallest number is: ", num5)