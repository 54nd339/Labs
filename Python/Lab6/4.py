# WAP to generate a multiplication table of a given number using lambda function.

n = int(input("Enter number: "))

print("\nMultiplication table of", n, "is:")
table = lambda x: x*n
for i in range(1, 11):
    print(f"{n} x {i} = {table(i)}")