# WAP a class named resturant with attributes menu items, book table, customer order and
# design suitable methods to add items to menu, book table for reservation, take order and display all.
# (use dictionary and list to store data)

class Resturant:
    def __init__(self, menu, table, order):
        self.menu = menu
        self.table = table

    def add_item(self, item, price):
        self.menu[item] = price

    def book_table(self, table):
        start, end = input("Enter start and end time: ").split()
        if(self.table[table]["booking"]["status"]):
            for i in self.table[table]["booking"]["time"]:
                if start >= i[0] and start <= i[1] or end >= i[0] and end <= i[1]:
                    print("Table not available")
                    return
            self.table[table]["booking"]["time"].append([start, end])
        else:
            self.table[table]["booking"]["status"] = True
            self.table[table]["booking"]["time"].append([start, end])

    def take_order(self, table):
        bill = 0
        if not self.table[table]["booking"]:
            print("Table not booked")
        else:
            while(True):
                item = input("Enter item: ")
                if item == "done":
                    break
                if item not in self.menu:
                    print("Item not available")
                else:
                    quantity = int(input("Enter quantity: "))
                    self.table[table]["order"][item] = quantity
                    bill += self.menu[item] * quantity
            self.table[table]["bill"] = bill

    def display_menu(self):
        print("Menu:")
        for i in self.menu:
            print(f"{i} - Rs. {self.menu[i]}")

    def display_table(self):
        print("Table:")
        for i in self.table:
            print(f"Table {i}:")
            print(f"Booking: {self.table[i]['booking']['status']}")
            print(f"Time: {self.table[i]['booking']['time']}")
            print(f"Order: {self.table[i]['order']}")
            print(f"Bill: {self.table[i]['bill']} Rs.")

def main():
    menu = {}
    notable = int(input("Enter number of tables: "))
    table = {i: {"booking": {"status": False, "time": [] },
                 "order": {}, "bill": 0} for i in range(1, notable+1)}
    order = {}
    r = Resturant(menu, table, order)
    while(True):
        print("\n1. Display Menu")
        print("2. Add Item to Menu")
        print("3. Book Table")
        print("4. Take Order")
        print("5. Display Table")
        print("6. Exit")
        choice = int(input("\nEnter choice: "))
        print()
        if choice == 1:
            r.display_menu()
        elif choice == 2:
            item = input("Enter item: ")
            price = int(input("Enter price: "))
            r.add_item(item, price)
        elif choice == 3:
            table = int(input("Enter table: "))
            r.book_table(table)
        elif choice == 4:
            table = int(input("Enter table: "))
            r.take_order(table)
        elif choice == 5:
            r.display_table()
        elif choice == 6:
            break
        else:
            print("Invalid choice")

if __name__ == "__main__":
    main()