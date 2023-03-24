# WAP a class named bank account with attributes account number, account holder name, balance and
# methods to deposit, withdraw and display account details.

class BankAccount:
    def __init__(self, account_number, account_holder_name, balance):
        self.account_number = account_number
        self.account_holder_name = account_holder_name
        self.balance = float(balance)

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if amount > self.balance:
            print("Insufficient balance")
        else:
            self.balance -= amount

    def display(self):
        print(f"Account Number: {self.account_number}")
        print(f"Account Holder Name: {self.account_holder_name}")
        print(f"Balance: {self.balance}")

    def __str__(self):
        return f"Bank Account with account number {self.account_number}"
    
def main():
    details = input("Enter account number, account holder name and balance: ").split()
    ba = BankAccount(details[0], details[1], details[2])

    while True:
        print("1. Deposit")
        print("2. Withdraw")
        print("3. Display")
        print("4. Exit")
        choice = int(input("Enter choice: "))
        if choice == 1:
            amount = float(input("Enter amount to deposit: "))
            ba.deposit(amount)
        elif choice == 2:
            amount = float(input("Enter amount to withdraw: "))
            ba.withdraw(amount)
        elif choice == 3:
            ba.display()
        elif choice == 4:
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()