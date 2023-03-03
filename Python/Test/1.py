list = [int(i) for i in input("Enter List: ").split()]
n = len(list)

for i in range(0, n):
    for j in range(0, n-1):
        if list[i] > list[j]:
            list[i], list[j] = list[j], list[i]

for i in list:
    print(i)