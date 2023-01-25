#include<stdio.h> 

int a[20][20] , visited[20] , v,size = 50;
int q[20] , f = -1 , r = -1 ;
int i,j,n;//find the number of element of graph

void bfs(int v ){
    for (int i = 0; i < n ; i++)
    {
        if (a[v][i] && !visited[i] ){
        q[++r] = i;//pushing value in queue
        }
        if (f <=r)
        {
        visited[q[f]] = 1;
        }
    }
    
}
int main(int argc, char const *argv[])
{
    printf("number of virteces ");
    scanf("%d",&n);
    printf("enter the adjency metrix");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }   
    }
    printf("enter a starting vertex");
    scanf("%d", &v);
    for (int i = 0; i < n ; i++)
    {
        q[i] = 0;
        visited[i] = 0;
    }
    
    bfs(v);
    printf("the reachable nodes are ");
    for (int i = 0; i < n; i++){
        if (visited[i])
        {
            printf("%d\t" , i);
        }
        
    }
    
    return 0;
}
