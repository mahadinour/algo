#include <stdio.h>
int stack[100], size = 20, top = -1;
 
void push(int element)
{
    if(top == size-1)
    {
        printf("stack overflowed\n");
    }
    else
    {
        top++;
        stack[top] = element;
    }
}
 
 
int pop()
{
    if(top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int elem = stack[top];
        top--;
        return elem;
    }
}
 
 
 
 
int graph[20][20] = {0}, color[20], parent[20], d[20], f[20], n, e, time=0;
 
 
void dfs_visit(int v)
{
    color[v] = 1;
    time++;
    d[v] = time;
    //printf("%d ",v);
 
    for(int i=0;i<n;i++)
    {
        if(graph[v][i] && !color[i])
        {
            parent[i] = v;
            dfs_visit(i);
        }
    }
 
    color[v] = 2;
    printf("\ncolor of node %d changed to %d\n",v,color[v]);
    time++;
    f[v] = time;
    printf("Node %d is pushed to stack\n",v);
    push(v);
}
 
 
 
void DFS()
{
    dfs_visit(3);
    for(int i=0; i<n; i++)
    {
        if(color[i] == 0)
        {
            dfs_visit(i);
        }
    }
}
 
 
int main()
{
    scanf("%d %d",&n,&e);
    for(int i=0;i<n;i++)
    {
        parent[i] = -1;
        color[i] = 0;
        d[i] = 0;
        f[i] = 0;
    }
 
    int p,q;
    for(int i=0;i<e;i++)
    {
        scanf("%d %d",&p,&q);
        graph[p][q] = 1;
        //graph[q][p] = 1;
    }
 
    DFS();
 
    while(top != -1)
    {
        int elem = pop();
        printf("%d ",elem);
    }
 
 return 0;
}