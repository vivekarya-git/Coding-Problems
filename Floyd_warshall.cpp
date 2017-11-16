#include<iostream>

using namespace std;

//Floyd Warshall- The problem is to find shortest distances between every pair
//of vertices in a given edge weighted directed Graph.

int min(int a, int b)
{
    return (a<b)?a:b ;
}
int main()
{
    int T,i,j,k;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d", &n);
        int a[n][n];
        
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                scanf("%d", &a[i][j]);
        }
        
        //  for(i=0; i<n; i++)
        // {
        //     for(j=0; j<n; j++)
        //         printf("%d ", a[i][j]);
        //     cout<<endl;
        // }
        
        
        
        for(k=0; k<n; k++)
        {
            // int dp[n][n]={};   
            for(i=0; i<n; i++)
            {
                for(j=0; j<n; j++)
                {
                    a[i][j]=min(a[i][j], a[i][k]+a[k][j]);
                }
            }
            // for(i=0; i<n; i++)
            // {
            //     for(j=0; j<n; j++)
            //     {
            //         a[i][j]= dp[i][j];
            //     }
            // }
        }
        
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                cout<<a[i][j]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
