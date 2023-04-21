# 2) wap with oop concept to implement a user defined queue data structure then demonstrate insert and remove method with a set of elements.

class Queue:
    def _init_(self):
        self.items = []

    def insert(self, item):
        self.items.append(item)

    def remove(self):
        return self.items.remove(self.items[0])
    
    def display(self):
        print(self.items)
        
c = Queue()
while True:
    print('1. Insert')
    print('2. Remove')
    print('3. Display')
    print('4. Exit')
    choice = int(input('Enter your choice: '))
    if choice == 1:
        item = input("Enter Item: ")
        c.insert(item)
    elif choice == 2:
        c.remove()
    elif choice == 3:
        c.display()
    elif choice == 4:
        break