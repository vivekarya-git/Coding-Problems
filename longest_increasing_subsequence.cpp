#include<iostream>

using namespace std;

/* Given a sequence, find the length of the longest increasing subsequence
from a given sequence. The longest increasing subsequence means to find 
a subsequence of a given sequence in which the subsequence's elements are 
in sorted order, lowest to highest, and in which the subsequence is as long as 
possible. This subsequence is not necessarily contiguous, or unique.
 */
int main()
{
    int T,i,j;
    cin>>T;
    while(T--)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        
        int dp[n+1]={};
        dp[1]=1;
        
        for(i=2; i<=n; i++)
        {
            int max=0;
            for(j=1; j<i; j++)
            {
                if(a[j-1]<a[i-1])
                {
                    if(dp[j]>max)
                        max= dp[j];
                }
            }
            dp[j]=1+ max;
            
        }
        
        int res=0;
        for(i=1; i<=n; i++)
        {
            if(dp[i]>res)
                res=dp[i];
        }
        
        cout<<res<<endl;
        
        
    }
    return 0;
}
