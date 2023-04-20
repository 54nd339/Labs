# WAP 3 classes namely Employee which has attribute emp_id, name, age. Regular_Employee is derived from employee and Daily_Worker is derived
# from Employee. Regular_Employee has attribute basic_salary, da, hra and Daily_Worker has attribute rate per day and no of days.

class Employee:
    def __init__(self, emp_id, name, age):
        self.emp_id = emp_id
        self.name = name
        self.age = age

    def display(self):
        print("Employee ID:", self.emp_id)
        print("Employee Name:", self.name)
        print("Employee Age:", self.age)

class Regular_Employee(Employee):
    def __init__(self, emp_id, name, age, basic_salary, da, hra):
        Employee.__init__(self, emp_id, name, age)
        self.basic_salary = basic_salary
        self.da = da
        self.hra = hra

    def display(self):
        Employee.display(self)
        print("Basic Salary:", self.basic_salary)
        print("DA:", self.da)
        print("HRA:", self.hra)
        print("Gross Salary:", self.basic_salary + self.da + self.hra)

class Daily_Worker(Employee):
    def __init__(self, emp_id, name, age, rate_per_day, no_of_days):
        Employee.__init__(self, emp_id, name, age)
        self.rate_per_day = rate_per_day
        self.no_of_days = no_of_days

    def display(self):
        Employee.display(self)
        print("Rate Per Day:", self.rate_per_day)
        print("No Of Days:", self.no_of_days)
        print("Gross Salary:", self.rate_per_day * self.no_of_days)

def main():
    emp_id = input("Enter Employee ID: ")
    name = input("Enter Employee Name: ")
    age = int(input("Enter Employee Age: "))
    basic_salary = int(input("Enter Basic Salary: "))
    da = int(input("Enter DA: "))
    hra = int(input("Enter HRA: "))
    rate_per_day = int(input("Enter Rate Per Day: "))
    no_of_days = int(input("Enter No Of Days: "))
    r = Regular_Employee(emp_id, name, age, basic_salary, da, hra)
    r.display()
    d = Daily_Worker(emp_id, name, age, rate_per_day, no_of_days)
    d.display()

if __name__ == "__main__":
    main()