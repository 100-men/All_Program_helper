#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define fast ios::sync_with_stdio(0) , cin.tie(0) , cout.tie(0) ;
 
const int nax = 1e5+10;
int par[nax] , sz[nax];
 
int fp(int v)
{
    if( v==par[v] ) return v;
    return par[v] = fp(par[v]);
}
signed main()
{
    fast;
    int n , m;
    cin >> n >> m;
    for(int i=1 ; i<=n ; i++ )
    {
        par[i] = i;
        sz[i] = 1;
    }
    int mx_sz = 1;
    int grp_cnt = n;
    for(int i=1 ; i<=m ; i++ )
    {
        int u ,v;
        cin >> u >> v;
        int pu = fp(u);
        int pv = fp(v);
        if( pu != pv )
        {
            grp_cnt--;
            if( sz[pu] > sz[pv] ) swap(pu,pv);
            par[pu] = pv;
            sz[pv] += sz[pu];
            sz[pu] = 0;
            mx_sz =  max( mx_sz, sz[pv] );
        }
        cout << grp_cnt << " " << mx_sz << "\n";
    }
}
