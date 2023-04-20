# WAP where Student derives Exam. Exam and Co-curricular_Activity derives Result.

class Student:
    def __init__(self, name, rollno):
        self.name = name
        self.rollno = rollno

    def display(self):
        print("Name:", self.name)
        print("Roll No:", self.rollno)

class Exam(Student):
    def __init__(self, name, rollno, marks):
        Student.__init__(self, name, rollno)
        self.marks = marks

    def display(self):
        Student.display(self)
        print("Marks:", self.marks)

class Co_curricular_Activity(Student):
    def __init__(self, name, rollno, activity):
        Student.__init__(self, name, rollno)
        self.activity = activity

    def display(self):
        Student.display(self)
        print("Activity:", self.activity)

class Result(Exam, Co_curricular_Activity):
    def __init__(self, name, rollno, marks, activity):
        Exam.__init__(self, name, rollno, marks)
        Co_curricular_Activity.__init__(self, name, rollno, activity)

    def display(self):
        Exam.display(self)
        Co_curricular_Activity.display(self)

def main():
    name = input("Enter Name: ")
    rollno = input("Enter Roll No: ")
    marks = int(input("Enter Marks: "))
    activity = input("Enter Activity: ")
    r = Result(name, rollno, marks, activity)
    r.display()

if __name__ == "__main__":
    main()