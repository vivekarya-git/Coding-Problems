#include <iostream>

using namespace std;

/*
Given an array of positive numbers, find the maximum sum of a subsequence
with the constraint that no 2 numbers in the sequence should be adjacent in the array.
So 3 2 7 10 should return 13 (sum of 3 and 10) or 3 2 5 10 7 should return 15 (sum of 
3, 5 and 7).
*/
int main()
{
    int T,i;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int a[n], dp[n+1]={};
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        
        dp[1]=a[0];
        for(i=1; i<n+1; i++)
        {
            if(dp[i-2]+a[i-1] > dp[i-1])
                dp[i] = dp[i-2]+a[i-1];
            else
            dp[i] = dp[i-1];
        }
        
        cout<<dp[n]<<endl;
    }
    return 0;
}
