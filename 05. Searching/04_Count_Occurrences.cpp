#include<bits/stdc++.h>
using namespace std;

int firstOcc(int a[],int n,int key)//time comp. O(logn)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(a[mid]>key)
        {
            high=mid-1;
        }   
        else if(a[mid]<key)
        {
            low=mid+1;
        }     
        else
        {
            if(mid==0 or a[mid-1]!=a[mid])
            {
                return mid;
            }
            else
            {
                high=mid-1;
            }
        }
    }

    return -1;
}


int lastOcc(int a[],int n,int key)//time comp. O(logn)
{
    int low=0;
    int high=n-1;

    while(low<=high)
    {
        int mid=(low+high)/2;

        if(a[mid]>key)
        {
            high=mid-1;
        }   
        else if(a[mid]<key)
        {
            low=mid+1;
        }     
        else
        {
            if(mid==(n-1) or a[mid+1]!=a[mid])
            {
                return mid;
            }
            else
            {
                low=mid+1;
            }
        }
    }

    return -1;
}

int count(int a[],int n,int key)//time comp. O(logn)
{
    int first=firstOcc(a,n,key);

    if(first==-1)
    {
        return 0;
    }
    else
    {
        return (lastOcc(a,n,key)-firstOcc(a,n,key)+1);
    }
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int key;
    cin>>key;

    cout<<count(a,n,key);
    return 0;
}