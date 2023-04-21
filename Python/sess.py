# Swap a String's vowels with next vowel like 1 with 2, 3 with 4, 5 with 6 and so on.

string = input("Enter a string: ")
vowels = ['a', 'e', 'i', 'o', 'u']
ind = []

print('Original String: ', string)

newString = ''
for i in range(len(string)):
    if string[i] in vowels:
        ind.append(i)

for i in range(0, len(ind), 2):
    if i == len(ind)-1:
        ind[i] = '@'
    else:
        ind[i], ind[i+1] = ind[i+1], ind[i]

c = 0
for i in range(len(string)):
    if string[i] in vowels:
        if ind[c] == '@':
            newString += '@'
        else:
            newString += string[ind[c]]
        c += 1
    else:
        newString += string[i]

print('New String: ', newString)
print('No. of swaps: ', len(ind)//2)