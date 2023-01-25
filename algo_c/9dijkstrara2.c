#include <stdio.h>
#define max 20
#define inf 99
void dijk(int g[max][max], int n, int start, int end)
{
    int cost[max][max], dist[max], visited[max], pred[max]; 
    int count, mindist, nextnode ;

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
    while (count < n - 1)
    {
        mindist = inf;

        for (int i = 0; i < count; i++)
        {
            if (dist[i] < mindist && !visited[i])
            {
                mindist = dist[i];
                nextnode = i;

                if (nextnode == end)
                {
                    goto level ;
                }
                
            }
        }
         level :
        visited[nextnode] = 1;
        for (int i = 0; i < end; i++)
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
            for (int i = 0; i < end; i++)
            {
                if (i != start )
                {
                    if (i == end-1)
                    {
                printf("\n The minimum distance of node %d from %d = %d\n", start, i+1 , dist[i]);
            printf("\n \t The shortest path is : %d", i);
            int j = i;
            do
            {
                j = pred[j];
                printf("<-%d",j);
            } while (j != start);
                    }
                }
                printf("\n");
            }
            printf("\n \n");

}
int main(int argc, char const *argv[])
{
    int g[max][max], n;

    printf("\n \n \t Wellcome to our PROJECT !! ");
    printf("\n******_______________________________******\n");
    printf("\n\n Please, Enter no of vertices : ");
    scanf("%d", &n);
    printf("\n Enter your favourite graph :: \n \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    int start;
    printf("\n \t Put on your starting node : ");
    scanf("%d", &start);
    int end ;
    printf("\n \t Put on your ending node : ");
    scanf("%d", &end);
    dijk(g, n, start, end);
    return 0;
}

/* 
0 7 9 0 0 14
7 0 10 15 0 0
9 10 0 11 0 2
0 15 11 0 6 0
0 0 0 6 0 9
14 0 2 0 9 0
*/
