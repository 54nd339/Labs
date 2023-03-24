# WAP a class named Student with 2 instances students1 and students2.
# Declare suitable attributes and methods to display the details of the students.

class Student:
    def __init__(self, name, roll, marks):
        self.name = name
        self.roll = roll
        self.marks = marks

    def display(self):
        print(f"Name: {self.name}")
        print(f"Roll: {self.roll}")
        print(f"Marks: {self.marks}")

    def __str__(self):
        return f"Student with name {self.name}"

def main():
    s1in = input("Enter name, roll and marks of student 1: ").split()
    s2in = input("Enter name, roll and marks of student 2: ").split()
    s1 = Student(s1in[0], s1in[1], s1in[2])
    s2 = Student(s2in[0], s2in[1], s2in[2])
    print(s1)
    s1.display()
    print(s2)
    s2.display()

if __name__ == "__main__":
    main()