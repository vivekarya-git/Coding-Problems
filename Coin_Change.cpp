#include<iostream>

using namespace std;

// Coin change pbm

int main()
{
    int T,i,j;
    cin>>T;
    while(T--)
    {
        int n,B;
        scanf("%d", &n);
        int c[n];
        for(i=0; i<n; i++)
            scanf("%d", &c[i]);
        scanf("%d", &B);
        //cout<<B<<"vjvn"<<endl;
        
        int dp[n+1][B+1]={};
        for(i=0; i<=n; i++)
            dp[i][0]=1;
        
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=B; j++)
            {
                if(j-c[i-1]<0) //if balance become negative then dp[i][j-c[i-1]]=0
                    dp[i][j]= dp[i-1][j];
                else
                    dp[i][j]= dp[i][j-c[i-1]] + dp[i-1][j];
            }
        }
        
        cout<<dp[n][B]<<endl;
    }
    return 0;
}
