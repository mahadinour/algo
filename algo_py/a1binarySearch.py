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
first = 0
last = n + 1
mid = (first + last)//2

# 1 3 5 7 9
# FIND 7

for i in range(last <=last):
    if find == a[mid]:
        print("find = ", mid)
        break
    elif a[mid] < find:
        last = mid + 1
    elif  a[mid] > find:
        first = mid - 1
    else:
        print("item is not find ")