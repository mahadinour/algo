#include <stdio.h>
#define max 20
#define inf 99
void dijk(int g[max][max], int n, int start)
{
    int cost[max][max], dist[max], visited[max], pred[max];//pred = predecessor(previous
    int count, mindist, nextnode;

    //cost of the graph
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 0)
            {
                cost[i][j] = inf;
            }
            else
            {
                cost[i][j] = g[i][j];   
            }
            
        }
    }

    for (int i = 0; i < n; i++)
    {
        dist[i] = cost[start][i];
        pred[i] = start;
        visited[i] = 0;
    }

    dist[start] = 0;
    visited[start] = 0;
    count = 1;

    //finding next node
    while (count < n-1)
    {
        mindist = inf;

        for (int   i = 0; i < count; i++)
        {
            if (dist[i] < mindist && !visited[i])
            {
                mindist = dist[i];
                nextnode = i;
            }
            
        }
        visited[nextnode] = 1;
        for (int i = 0; i <n ; i++)
        {
            if (!visited[i])
            {
                if ((mindist + cost[nextnode][i]) < dist[i])
                {
                    dist[i] = mindist + cost[nextnode][i];
                    pred[i] = nextnode;
                }
                
            }
            
        }
        count++;
        
    }
    for (int i = 0; i < n; i++)
    {
        if (i != start)
        {
            printf("the distance of node %d is %d\n", i, dist[i]);
            printf("the path is %d", i);
            int j = i;
            do
            {
                j = pred[j];
                printf("<-%d",j);
            } while (j != start);
            
        }
        printf("\n");
        
    }
    
    

}
int main(int argc, char const *argv[])
{
    int g[max][max], n;
    printf("enter no of vertices \n");
    scanf("%d", &n);
    printf("enter graph \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    printf("display graph \n");
   // for (int i = 0; i < n; i++)
   // {
    //    for (int j = 0; j < n; j++)
    //    {
    //        printf("%d", &g[i][j]);
     //   }
    //}
    int start;
    printf("enter the starting node \n");
    scanf("%d", &start);
    dijk(g, n, start);
    return 0;
}
