#include <stdio.h>
int que[100], front = -1, rear = -1, size = 50;
//this is graph part
int graph[20][20] = {0}, color[20], parent[20], n, e, d[20] = {0};

int isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return 1; //return true
    }
    else
    {
        return 0;
    }
}
int isFull()
{
    if (front == (rear + 1) % size)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//at first chake queue is full or not
void enQue(int element)
{
    if (isFull())
    {
        printf("queue is full");
        return;
    }
    else if (isEmpty())
    {
        // if queue is empty set front and rear index is 0 ,And push a elememt in queue
        front = 0;
        rear = 0;
        que[rear] = element;
    }
    else
    {
        rear = (rear + 1) % size; //circular queue
        que[rear] = element;
    }
}
//at first chake queue is not full
int deQue()
{
    if (isEmpty() ==1)
    {
        printf("queue is empty");
        //return ;
    }
    else if (front == rear)
    {
        int element = que[front];
        front = -1;
        rear = -1;
        return element;
    }
    else
    {
        int element = que[front];
        front = (front + 1) % size;
        return element;
    }
}

void bfs(int v)
{
    //enqueue the source node

    enQue(v);     //enque start with sterting
    color[v] = 1; //if visited ==gray(1)
    printf("visited : %d \n", v);

    //visited all child
    while (!isEmpty())
    {
        int x = deQue(); // x is for dequeue the element
        printf("\n X(dequed element)=visited node = %d ------------ \n", x);
        for (int i = 0; i < n; i++)
        {
            if (graph[x][i] && !color[i]) //adjacen node
            {
                d[i] = d[x] + 1;

                printf("distance(label) = %d \n", d[i]);

                color[i] = 1; //if visited ==gray(1)
                parent[i] = x;

                printf("node = %d \n", x);
                printf("i->connecterd node(child node) = %d \n", i);

                enQue(i);
            }
        }
        color[x] = 2;
    }
}

int main(int argc, char const *argv[])
{
    printf("\n \n \n \n");
    printf("enter node(n) and edge(e) \n");
    scanf("%d %d", &n, &e);

    // set node_parent -1(nill AND color 0(white)
    for (int i = 0; i < n; i++) //n
    {
        parent[1] = -1;
        color[i] = 0;
    }
    // input the un directed edge(relation)
    int p, q;
    for (int i = 0; i < e; i++) //e
    {
        scanf("%d %d", &p, &q); // p = x , q = y
        graph[p][q] = 1;        //set p,q position 1
        graph[q][p] = 1;
    }
    printf("enter a source node=0 \n");
    bfs(0); //here 0 is source node
    return 0;
}
