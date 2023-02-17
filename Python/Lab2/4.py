# repeat q3 by switch case statement

numbers = [int(input(f"Enter number {i + 1}: ")) for i in range(5)]

total = sum(numbers)
print("Total marks", total)

percentage = (total/500)*100
print(f"Percentage: {percentage}%")

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