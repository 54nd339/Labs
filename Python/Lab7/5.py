# WAP a class to implement power function.

class Power:
    def __init__(self, base, power):
        self.base = base
        self.power = power

    def calculate(self):
        return self.base ** self.power
    
def main():
    b, p = int(input("Enter base, power: ").split())
    p = Power(b, p)
    print(p.calculate())

if __name__ == "__main__":
    main()