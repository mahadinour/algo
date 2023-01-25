n = int(input("enter array length :\n"))

print("enter ur data")
a = []

for i in range(0, n):
    print("data [", i+1, "] = ")
    data = int(input("......"))
    a.append(data)

for i in range(0, n):
    print("data [", i+1, "] = ")
    print(a[i])

def quicksort(a, left, right):
    if left < right:
        q = partition(a, left, right)
        quicksort(a, left, q-1)
        quicksort(a, q+1, right)

def partition(a, left, right):
    x = a[right]
    i = left - 1
    for j in range(left, right-1):
        if a[j] <= x:
            i = i+1
            a[i] ,a[j] = a[j] ,a[i]
    a[i+1], a[right] = a[right], a[i+1]
    return (i+1)

left =0
right = n - 1

quicksort(a , left , right)

print("after sorting")
print(a)

