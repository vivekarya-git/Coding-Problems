#include<iostream>

using namespace std;

//Given an array of integers where each element represents the max number 
//of steps that can be made forward from that element. Write a function to 
//return the minimum number of jumps to reach the end of the array (starting 
//from the first element). If an element is 0, then cannot move through that element.

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
        
        int jump[n]= {};
        for(i=1; i<n; i++)
        {
            int flag=0;
            for(j=0; j<i; j++)
            {
                if(i <= j+a[j])
                {
                    if(jump[j]!= -1)
                    {
                        jump[i] = jump[j]+1;
                        flag=1;
                        break;
                    }
                        
                }
                
            }
            if(flag==0)
                jump[i]=-1;
        }
        
        cout<<jump[n-1]<<endl;
    }
    return 0;
}
