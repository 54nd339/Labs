# print pattern
# 1
# 12
# 123
# 1234

num = int(input("Enter a number: "))
for i in range(1, num+1):
    for j in range(1, i+1):
        print(j, end="")
    print()

