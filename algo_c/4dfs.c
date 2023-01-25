#include <stdio.h>

int graph[20][20] = {0}, color[20], parent[20], d[20], f[20], n, e, time = 0;
 
void dfs_visit(int v)
{
    //visite v-> node ajecent
    color[v] = 1; //(gray)if visited color is upgraded 0=>1 
    time++;       //if visited time is upgraded 0=>1
    d[v] = time;//?
    printf(" %d -> ", v);

    //visite v node -> u adjecen
    for (int i = 0; i < n; i++)
    {
        //here v is i adjascn white node
        if (graph[v][i] && !color[i])//if (v->i) having a edge AND colour is white(not colour) 
        {
            //i = adjacen white node
            parent[i] = v;
            dfs_visit(i);
        }
        color[v] = 2;
        //printf("color of node %d ot change %d \n ", v, color[v]);
        time++;
        f[v] = time;
    }
}

void dfs()//when a node is white then callig dfs()
{
    for (int i = 0; i < n; i++)
    {
        if (color[i] == i)//==0/
        {
            dfs_visit(i);
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("\n \n enter a node and edge \n");
    scanf("%d %d", &n, &e);
    for (int i = 0; i < n; i++)
    {
        parent[i] = -1; //
        color[i] = 0;
        d[i] = 0; //discover time
        f[i] = 0; //finishing time
    }
    int p, q;
    printf("enter connected node's edge\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d", &p, &q);
        graph[p][q] = 1;
        graph[q][p] = 1;//for drected
    }

    dfs();
    return 0;
}
