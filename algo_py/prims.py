
#user input graph
n = int(input("enter adj length"))

graph = [[int(input()) for x in range(n)] for y in range(n)]

visited = []
min = 999
u = 0 # source node
v = 0# distance
total = 0

for i in range(7):
    for i in range(0, n):
        visited[i] = 0
        #minimum


