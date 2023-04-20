# WAP to use simple inheritence of class Bank and Customer where Customer is derived from Bank.

class Bank:
    def __init__(self, name, account, balance):
        self.name = name
        self.account = account
        self.balance = balance

    def deposit(self, amount):
        self.balance += amount
        print("Deposit Successful!")

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            print("Withdrawal Successful!")
        else:
            print("Insufficient Balance!")

    def display(self):
        print("Name:", self.name)
        print("Account Number:", self.account)
        print("Balance:", self.balance)

class Customer(Bank):
    def __init__(self, name, account, balance, type):
        Bank.__init__(self, name, account, balance)
        self.type = type

    def display(self):
        Bank.display(self)
        print("Type:", self.type)

def main():
    name = input("Enter Name: ")
    account = input("Enter Account Number: ")
    balance = int(input("Enter Balance: "))
    type = input("Enter Type: ")
    c = Customer(name, account, balance, type)
    c.display()

if __name__ == "__main__":
    main()