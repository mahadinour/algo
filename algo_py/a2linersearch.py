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

find = int(input("enter ur search item \n"))

for i in range(0, n):
    if a[i] == find:
        print("found = ", i)
        break