print("enter a length of array")
n = int(input())
print("enter array data ")
a = []

for i in range(0, n):
    print("data [", i, "] = ", end="")
    a.append(int(input()))

print("display ur data .......................")
for i in range(0, n):
    print("data [", i, "] = ", end="")
    print(a[i])
'''
a = 10
b = 20
a, b = b, a
print(a,b)
'''
#5, 4, 3, 2, 1

for i in range(0, n-1):
    for j in range(0, n - i - 1):
        a[j], a[j+1] = a[j+1], a[j]
        '''
        if a[j] > a[j+1]:
            t = a[j]
            a[j] = a[j+1]
            a[j+1] = t
        '''



print("display ur sorting data .......................")
for i in range(0, n):
    print("data [", i, "] = ", end="")
    print(a[i])