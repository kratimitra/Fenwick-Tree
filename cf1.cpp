/*
You are given a multiset consisting of n integers. You have to process queries of two types:

add integer k into the multiset;
find the k-th order statistics in the multiset and remove it.
k-th order statistics in the multiset is the k-th element in the sorted list of all elements of the multiset. For example, if the multiset contains elements 1, 4, 2, 1, 4, 5, 7, and k=3, then you have to find the 3-rd element in [1,1,2,4,4,5,7], which is 2. If you try to delete an element which occurs multiple times in the multiset, only one occurence is removed.

After processing all queries, print any number belonging to the multiset, or say that it is empty.

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =  (int)(1 * 1e6 + 10);
void prl(int x) {cout << x << endl;}
//Fenwick - Tree::::::::::::
 ll fen[N]={0};
// Update Operation to update the fenwick tree basically adding a value 'add' and keep on adding it untill we reach to all its children
    void update(ll i,ll add)
    {
        while(i<N)
        {
            fen[i] += add;
            i += (i & (-i));
        }
    }
    ll sum(ll i)
    {
        ll s=0;
        while(i>0)
        {
            s += fen[i];
            i = i - (i & (-i));
        }
        return s;
    }
    int rangeSum(int l,int r)
    { 
        return sum(r)-sum(l-1);
    }
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--){
        int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        update(x,1);
    }
 
    while(q--)
    {
        int x;
        cin>>x;
        if(x>0)
        {
            update(x,1);
        }
        else
        {
            x=abs(x);
            int low=0,high=N;
            while(low<high)
            {
                int mid=low+(high-low)/2;
                int val=sum(mid);
                if(x<=val)
                    high=mid;
                else
                    low=mid+1;
            }
            update(low,-1);
        }
    }
 
    int ans=sum(N);
    if(ans==0){
        prl(0);
        continue;
    }
    int low=0;
    int high=N;
    while(low<high)
    {
        int mid=low+(high-low)/2;
        int val=sum(mid);
                if(ans<=val)
                    high=mid;
                else
                    low=mid+1;
 
    }
    prl(low);
 

    }
}
