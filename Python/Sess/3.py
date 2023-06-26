class Vehicle():
    def __init__(self, max_speed, mileage):
        self.max_speed = max_speed
        self.mileage = mileage
    def display(self):
        print("Max speed:", self.max_speed)
        print("Mileage:", self.mileage)

class Traveller(Vehicle):
    def __init__(self, max_speed, mileage, capacity):
        super().__init__(max_speed, mileage)
        self.capacity = capacity
    def calculate_fare(self):
        return self.capacity * 120
    def display(self):
        super().display()
        print("Capacity:", self.capacity)

class Bus(Traveller):
    def __init__(self, max_speed, mileage, capacity, is_traveller):
        super().__init__(max_speed, mileage, capacity)
        self.is_traveller = is_traveller
    def calculate_fare(self):
        if self.is_traveller:
            return super().calculate_fare()*1.1
        else:
            return super().calculate_fare()
    def display(self):
        super().display()
        print("Is traveller:", self.is_traveller)

b = Bus(100, 20, 50, True)
b.display()
print("Fare:", b.calculate_fare())

t = Traveller(100, 20, 50)
t.display()

v = Vehicle(100, 20)
v.display()