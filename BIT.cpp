/*
Basic Template for Fenwick Tree a.k.a Binary Indexed Tree
*/

const int N =  (int)(1 * 1e6 + 10);

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
// We have to find the prefix sum from 0 to i. 
//So we will start with i and keep on moving to its parent till it is not zero and keep on 
// adding the value stored in the fenwick tree
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
// If you need the prefix sum between l and r
    ll rangeSum(int l,int r)
    { 
        return sum(r)-sum(l-1);
    }
