A = [int(i) for i in input('Enter A vals: ').split()]
B = [int(i) for i in input('Enter B vals: ').split()]

len_res = min(len(A), len(B))
res = []

for i in range(len_res):
    res.append(A[i]**B[i])

def check_prime(n):
    if n == 1:
        return False
    for i in range(2, n//2 + 1):
        if n % i == 0:
            return False
    return True

for i in range(len_res-1):
    if check_prime(res[i]) and check_prime(res[i+1]):
        res[i], res[i+1] = res[i+1], res[i]

print(*res)