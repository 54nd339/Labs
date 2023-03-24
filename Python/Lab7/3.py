# WAP a python class to find 3 elements in a list or set of n numbers which sum to 0.

class SumToZero:
    def __init__(self, numbers):
        self.numbers = numbers
        self.n = len(numbers)

    def sum_to_zero(self):
        found = False
        self.numbers.sort()
    
        for i in range(0, self.n-2):
            l = i + 1
            r = self.n - 1
            x = self.numbers[i]
            while (l < r):
                if (x + self.numbers[l] + self.numbers[r] == 0):
                    print(x, self.numbers[l], self.numbers[r])
                    l += 1
                    r -= 1
                    found = True
                elif (x + self.numbers[l] + self.numbers[r] < 0):
                    l += 1
                else:
                    r -= 1

        if not found:
            print("No triplets found")

def main():
    numbers = list(map(int, input("Enter numbers: ").split()))
    s = SumToZero(numbers)
    s.sum_to_zero()

if __name__ == "__main__":
    main()