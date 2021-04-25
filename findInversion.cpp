/*
Find inversion count of array

Example :
5
8 4 9 2 8
Output : 
5

*/


#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N =  (int)(1 * 1e6 + 10);

void prl(int x) {cout << x << endl;}
//Fenwick - Tree::::::::::::
 ll fen[N]={0};

void update(int i, int x){
    for(; i < N; i += (i&-i))
        fen[i] += x;
}

int sum(int i){
    int ans = 0;
    for(; i > 0; i -= (i&-i))
        ans += fen[i];
    return ans;
}

int main(){
    int n;
    cin >> n;
    ll a[n+10];
    map<ll,int> mp;
    for(int i = 1;i <= n; ++i){
        cin >> a[i];
        mp[a[i]];
    }

    int ptr = 1;
    for(auto &pr : mp){
        pr.second = ptr++;
    }

    for(int i = 1; i <= n; ++i){
        a[i] = mp[a[i]];
    }

    // Finding Inversion count


    int inv_count = 0;
    for(int i = 1; i<= n; ++i){
        inv_count += (sum(N-5) - sum(a[i]));
        update(a[i], 1);
    }

   prl(inv_count);


}
