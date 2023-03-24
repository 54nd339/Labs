# WAP a class to print all unique subsets of a given set.

class Subsets:
    def __init__(self, set):
        self.set = set
        self.n = len(set)

    def print_subsets(self):
        res = set()
        subset = []
        result = []
        res.add(tuple(subset))
    
        for i in range(self.n):
            N = len(res)
            for it in res:
                subset = list(it)
                subset.append(self.set[i])
                result.append(subset)
                N -= 1
                if N == 0:
                    break
            res.update([tuple(x) for x in result])
            result.clear()

        for i in res:
            print("{", end="")
            for (index, j) in enumerate(i):
                print(j, end=(", " if index != len(i)-1 else ""))
            print("}")

def main():
    s = Subsets(list(map(int, input("Enter set: ").split())))
    s.print_subsets()

if __name__ == "__main__":
    main()