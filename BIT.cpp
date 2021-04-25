const int N =  (int)(1 * 1e6 + 10);

//Fenwick - Tree::::::::::::
 ll fen[N]={0};
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
    ll find(ll k)
    {
        ll sum = 0;
    ll pos = 0;
    
    for(ll i=log(N); i>=0; i--)
    {
        if(pos + (1 << i) < N and sum + fen[pos + (1 << i)] < k)
        {
            sum += fen[pos + (1 << i)];
            pos += (1 << i);
        }
    }

    return pos + 1;
    }
    ll rangeSum(int l,int r)
    { 
        return sum(r)-sum(l-1);
    }