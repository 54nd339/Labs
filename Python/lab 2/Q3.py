#  enter marks of student in 5 subjects and calculate the total and percentage also calculate grades


sub1 = int(input("Enter marks of subject 1: "))
sub2 = int(input("Enter marks of subject 2: "))
sub3 = int(input("Enter marks of subject 3: "))
sub4 = int(input("Enter marks of subject 4: "))
sub5 = int(input("Enter marks of subject 5: "))

total = sub1 + sub2 + sub3 + sub4 + sub5
print("Total marks: ", total)

percentage = (total/500)*100
print("Percentage: ", percentage,"%")

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