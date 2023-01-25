#include <stdio.h>
#define inf 99
#define max 100

void dij(int g[max][max],int n, int startnode)
{ //g
    int distance[max], pre[max];//pre = previous
    int visited[max] = {0};
    int count, mindistance, nextnode;
    int i, j;
    for (int i = 0; i < n; i++)
    {
        pre[i] = startnode;
        distance[i] = g[startnode][i];
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = inf;
        for (int i = 0; i < n; i++)
        {
            if (distance[i] < mindistance && visited[i] == 0)
            {
                mindistance = distance[i];
                nextnode = i;
            }
        }
        visited[nextnode] = 1;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                if (mindistance + g[nextnode][i] < distance)
                {
                    distance[i] = mindistance + g[nextnode][i];
                    pre[i] = nextnode;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {

            if (i != startnode)
            {
                printf("dictence of node %c= %c", i + 65, distance[i] + 65);
                printf("path = %c \n", i + 65);
                j = i;
                do
                {
                    j = pre[j];
                    printf("<-%c", j + 65);
                } while (j != startnode);
            }
        }

        count++;
        for (int i = 0; i < n; i++)
        {
            /* code */
        }
    }
}

int main(int argc, char const *argv[])
{
    int g[max][max];
   // int i, j;
    int n, start;
    printf("enter num of node\n");
    scanf("%d", &n);
    printf("enter adjacency matrix :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", g[i][j]);
        }
    }
    printf("enter sterting node\n");
    scanf("%d", &start);
   dij(g ,n, start);

    return 0;
}
