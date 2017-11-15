#include<iostream>

using namespace std;

/*Given a N X N  matrix Matrix[N][N] of positive integers.  There are only 
three possible moves from a cell Matrix[r][c].
1. Matrix[r+1][c]

2. Matrix[r+1][c-1]

3. Matrix[r+1][c+1]
Starting from any column in row 0, return the largest sum of any of the paths 
up to row N-1(that is, any end point in last row).
*/

int max(int a, int b)
{
    return (a>b)?a:b ;
}

int main()
{
    int T,i,j,k;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n][n];
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
                scanf("%d", &a[i][j]);
        }
        
        int res=0;
        
        for(k=1; k<=n; k++)
        {
            int dp[n][n+2]={};
            
            dp[0][k]=a[0][k-1];
            for(i=1; i<n; i++)
            {
                for(j=1; j<=n; j++)
                {
                    int t1= max(dp[i-1][j-1], dp[i-1][j]);
                    dp[i][j]=max(t1, dp[i-1][j+1]);
                    
                    dp[i][j]+= a[i][j-1];
                }
            }
            
            for(i=1; i<=n; i++)
            {
                if(dp[n-1][i]>res)
                    res= dp[n-1][i];
            }
        }
        
        cout<<res<<endl;   
        
    }
    return 0;
}
