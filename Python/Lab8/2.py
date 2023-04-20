# WAP having 3 classes Factory, Wholesale and Retailer where Retailer is derived from Wholesale and Wholesale is derived from Factory.

class Factory:
    def __init__(self, name, address, phone):
        self.name = name
        self.address = address
        self.phone = phone

    def display(self):
        print("Factory Name:", self.name)
        print("Factory Address:", self.address)
        print("Factory Phone:", self.phone)

class Wholesale(Factory):
    def __init__(self, name, address, phone, discount):
        Factory.__init__(self, name, address, phone)
        self.discount = discount

    def display(self):
        Factory.display(self)
        print("Discount:", self.discount)

class Retailer(Wholesale):
    def __init__(self, name, address, phone, discount, quantity):
        Wholesale.__init__(self, name, address, phone, discount)
        self.quantity = quantity

    def display(self):
        Wholesale.display(self)
        print("Quantity:", self.quantity)

def main():
    name = input("Enter Factory Name: ")
    address = input("Enter Factory Address: ")
    phone = input("Enter Factory Phone: ")
    discount = int(input("Enter Discount: "))
    quantity = int(input("Enter Quantity: "))
    r = Retailer(name, address, phone, discount, quantity)
    r.display()

if __name__ == "__main__":
    main()