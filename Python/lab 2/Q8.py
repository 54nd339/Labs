# generate fibonacci series upto n numbers

num = int(input("Enter a number: "))
a = 0
b = 1
sum = 0


for i in range(1, num):
    print(sum, end=" ")
    a = b
    b = sum
    sum = a + b

print(sum)