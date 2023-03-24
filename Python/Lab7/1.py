# WAP a class named Circle with atttributes radius and 2 methods area and perimeter.

class Circle:
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14 * self.radius * self.radius

    def perimeter(self):
        return 2 * 3.14 * self.radius
    
    def __str__(self):
        return f"Circle with radius {self.radius}"

def main():
    r = int(input("Enter radius: "))
    c = Circle(r)
    print(c)
    print(f"Area: {c.area():.2f}")
    print(f"Perimeter: {c.perimeter():.2f}")

if __name__ == "__main__":
    main()