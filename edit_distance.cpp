#include<iostream>

using namespace std;

// Edit Distance Pbm

int min(int a, int b)
{
    return (a<b)?a:b ;
}

int main()
{
    int T, i,j;
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>m>>n;
        string str1, str2;
        cin>>str1>>str2;
        
        int dp[m+1][n+1]={};
        
        for(i=1; i<=n; i++)
            dp[0][i]=i;
        for(i=1; i<=m; i++)
            dp[i][0]=i;
            
        for(i=1; i<=m; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j]= dp[i-1][j-1];
                else
                {
                    int t1=min(dp[i-1][j]+1, dp[i][j-1]+1);
                    dp[i][j]=min(t1, dp[i-1][j-1]+1);
                }
            }
        
        }
        
        cout<<dp[m][n]<<endl;
    }
    return 0;
}
