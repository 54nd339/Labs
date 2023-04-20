# WAP a class Inventory with attributes like item_id, item_name, stock_count and price. 
# Define suitable methods and constructor to add items to inventory, update_stock_count and check_item_details.

class Item:
    def __init__(self, item_id, item_name, stock_count, price):
        self.item_id = item_id
        self.item_name = item_name
        self.stock_count = stock_count
        self.price = price

    def update_stock_count(self, operation, count):
        if operation == 1:
            self.stock_count += count
        elif operation == 0:
            self.stock_count -= count
        else:
            print("Invalid Operation")
        print("Stock Count Updated Successfully")

    def check_item_details(self):
        print("\nItem ID:", self.item_id)
        print("Item Name:", self.item_name)
        print("Stock Count:", self.stock_count)
        print("Price:", self.price)

class Inventory:
    def _init_(self):
        self.items = tuple()
    
    def add_item(self, item):
        # check if the item already exists
        for i in self.items:
            if i.item_id == item.item_id:
                print("Item Already Exists")
                return
        self.items.append(item)
        print("Item Added Successfully")
    
    def update_stock_count(self, item_id):
        for item in self.items:
            if item.item_id == item_id:
                operation = input("Enter Operation (1. add, 0. remove): ")
                count = int(input("Enter Count: "))
                item.update_stock_count(operation, count)
                break
        else:
            print("Item Not Found")
    
    def check_item_details(self):
        for item in self.items:
            item.check_item_details()

def main():
    inventory = Inventory()
    while(True):
        print('1. Add new Item')
        print('2. Update Stock Count')
        print('3. Check Item Details')
        print('4. Exit')
        choice = int(input('Enter your choice: '))

        if choice == 1:
            item_id = input("Enter Item ID: ")
            item_name = input("Enter Item Name: ")
            stock_count = int(input("Enter Stock Count: "))
            price = int(input("Enter Price: "))
            item = Item(item_id, item_name, stock_count, price)
            inventory.add_item(item)
        elif choice == 2:
            item_id = input("Enter Item ID: ")
            inventory.update_stock_count(item_id)
        elif choice == 3:
            inventory.check_item_details()
        elif choice == 4:
            break

if __name__ == "__main__":
    main()