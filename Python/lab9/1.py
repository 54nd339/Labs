# 1) wap with oop concept to implement a user defined stack data structure then demonstrate push and pop method with the set of elements.

class stack:
    def _init_(self):
        self.items = []

    def push(self, item):
        self.items.insert(0,item)

    def pop(self):
        return self.items.remove(self.items[0])
    
    def display(self):
        print(self.items)


c=stack()
while True:
    print('1. Push')
    print('2. Pop')
    print('3. Display')
    print('4. Exit')
    choice = int(input('Enter your choice: '))
    if choice == 1:
        item = input("Enter Item: ")
        c.push(item)
    elif choice == 2:
        c.pop()
    elif choice == 3:
        c.display()
    elif choice == 4:
        break