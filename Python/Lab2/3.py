#  enter marks of student in 5 subjects and calculate the total and percentage also calculate grades

numbers = [int(input(f"Enter number {i + 1}: ")) for i in range(5)]

total = sum(numbers)
print("Total marks:", total)

percentage = (total/500)*100
print(f"Percentage: {percentage}%")

if(percentage >= 90):
    print("Grade: O")
elif(percentage >= 80 and percentage<90):
    print("Grade: E")
elif(percentage >= 70 and percentage<80):
    print("Grade: A")
elif(percentage >= 60 and percentage<70):
    print("Grade: B")
elif(percentage >= 50 and percentage<60):
    print("Grade: C")
elif( percentage>= 40 and percentage<50):
    print("Grade: D")
else:
    print("Grade: F")