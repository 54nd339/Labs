names = [i for i in input("Enter Names: ").split()]
n = len(names)
out = names[0]

for i in range(0, n-1):
    len1 = len(names[i])
    len2 = len(names[i+1])
    temp = ""

    for j in range(0, min(len1, len2)):
        if names[i][-(j+1)] == names[i+1][-(j+1)]:
            print(names[i], names[i][-j])
            temp = names[i][-(j+1)] + temp
        else:
            break

    if(len(out) > len(temp)):
        out = temp

print(out)