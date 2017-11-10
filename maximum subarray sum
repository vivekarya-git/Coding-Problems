#include <iostream>
#include <climits>

using namespace std;

//finding maximum subarray sum of given array 

int main()
{
    int T,i,n;
    cin>>T;
    while(T--)
    {
        
        cin>>n;
        int a[n];
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        
        int dp[n+1] = {};
        dp[0] = INT_MIN;
        int si=0;
        for(i=1; i<n+1; i++)
        {
            if(si+a[i-1]  > a[i-1])
                si = si + a[i-1];
            else
                si = a[i-1];
                
            if(si > dp[i-1])
                dp[i] = si;
            else
                dp[i] = dp[i-1];
            
        }
        
        cout<<dp[n]<<endl;
    }
    return 0;
}
