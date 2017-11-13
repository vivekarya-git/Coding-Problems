#include<iostream>

using namespace std;

// 0-1 Knapsack pbm

int  main()
{
    int T,i,j;
    cin>>T;
    while(T--)
    {
        int n,W;
        cin>>n>>W;
        int wt[n], v[n];
        for(i=0; i<n; i++)
            scanf("%d", &v[i]);
        for(i=0; i<n; i++)
            scanf("%d", &wt[i]);
        
        int dp[n+1][W+1]={};
        
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=W; j++)
            {
                
                if(wt[i-1] <= j)
                {
                    int t1, t2;
                    t1= dp[i-1][j-wt[i-1]] + v[i-1];
                    t2= dp[i-1][j];
                    if(t1> t2)
                       dp[i][j]=t1; 
                    else
                        dp[i][j]=t2;
                }
                else
                    dp[i][j]= dp[i-1][j] ;
            }
        }
            
        cout<<dp[n][W]<<endl;       
    }
    return 0;
}
