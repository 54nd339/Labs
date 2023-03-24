# WAP a class to reverse a string word by word.

class String:
    def __init__(self, string):
        self.string = string

    def reverse(self):
        return ' '.join(self.string.split()[::-1])
    
def main():
    s = String(input("Enter string: "))
    print(s.reverse())

if __name__ == "__main__":
    main()