# WAP 2 classes namely University and School derives Student. University attribute reg no., school attributes roll no.

class University:
    def __init__(self, name, regno):
        self.name = name
        self.regno = regno

    def display(self):
        print("Name:", self.name)
        print("Reg No:", self.regno)

class School:
    def __init__(self, name, rollno):
        self.name = name
        self.rollno = rollno

    def display(self):
        print("Name:", self.name)
        print("Roll No:", self.rollno)

class Student(University, School):
    def __init__(self, name, regno, rollno):
        University.__init__(self, name, regno)
        School.__init__(self, name, rollno)

    def display(self):
        University.display(self)
        School.display(self)

def main():
    name = input("Enter Name: ")
    regno = input("Enter Reg No: ")
    rollno = input("Enter Roll No: ")
    s = Student(name, regno, rollno)
    s.display()

if __name__ == "__main__":
    main()