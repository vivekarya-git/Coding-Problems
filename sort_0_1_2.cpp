//#include<stdio.h>
#include<iostream>
using namespace std;

//Write a program to sort an array of 0's,1's and 2's in ascending order.(variant of Dutch
// national flag pbm)

void swap(int* a, int* b)
{
    int t= *a;
    *a= *b;
    *b= t;
    //printf("%d %d\n", *a, *b);
    return;
}
int main()
{
    int T,i;
    //scanf("%d", &T);
    cin>>T;
    while(T--)
    {
        int n;
        //scanf("%d", &n);
        cin>>n;
        int a[100];
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
            
        
        int mid=0,l=0,h=n-1;
        while(mid<=h)
        {
            //printf("viv\n" );
            if(a[mid] == 0)
            {
                swap(&a[mid], &a[l]);
                l++;
                mid++;
            }
            else if(a[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(&a[mid], &a[h]);
                h--;
            }
        }
        
        for(i=0; i<n; i++)
            printf("%d ", a[i]);
        //cout<<end;
        printf("\n");
    }
    return 0;
}
