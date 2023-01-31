# repeat q4 by switch case statement

sub1 = int(input("Enter marks of subject 1: "))
sub2 = int(input("Enter marks of subject 2: "))
sub3 = int(input("Enter marks of subject 3: "))
sub4 = int(input("Enter marks of subject 4: "))
sub5 = int(input("Enter marks of subject 5: "))

total = sub1 + sub2 + sub3 + sub4 + sub5
print("Total marks: ", total)

percentage = (total/500)*100
print("Percentage: ", percentage,"%")

per = int(percentage/10)

match per:
    case 9:
        print("Grade: O")
    case 8:
        print("Grade: E")
    case 7:
        print("Grade: A")
    case 6:
        print("Grade: B")
    case 5:
        print("Grade: C")
    case 4:
        print("Grade: D")
    case _:
        print("Grade: F")