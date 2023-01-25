class adj:

    def graph(self,n,a):
        for i in range(n):
            for j in range(n):
                x = int(input(" , "))
                a.append(x)


if __name__ == "__main__":
    print("a for apple ")
    a = []
    matrix = adj()
    matrix.graph(3, a)

    pass