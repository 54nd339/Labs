# WAP to calculate SI of the given PTR using function where the function takes the default value for the rate of interest.

def si(p, t, r=10):
    return p*t*r/100

print(si(1000, 2))
print(si(1000, 2, 5))