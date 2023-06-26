while True:
    n = int(input('Enter a 3 digit number: '))
    if n < 100 or n > 999:
        print('Invalid input')
    else:
        break

def reverse(n):
    return int(str(n)[::-1])

res = []
for i in range(3):
    m = reverse(n // 10**(3-i-1))
    res.append(m*10**(3-i-1) + n % 10**(3-i-1))

print(*res)