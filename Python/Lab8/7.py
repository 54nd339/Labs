# WAP a class to check if an instance belongs to a class or not and a class is subclass of another class or not.

class A:
    def __init__(self):
        a = 1

class B(A):
    pass

def main():
    a = A()
    b = B()
    print(isinstance(a, A))
    print(isinstance(b, A))
    print(issubclass(B, A))

if __name__ == "__main__":
    main()