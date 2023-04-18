#include <bits/stdc++.h>
#define fastio      ios_base::sync_with_stdio(false); cin.tie(NULL)
#define debug(x)    cout << "Line " << __LINE__ << ", " << #x << " is " << x << endl
#define fi          first
#define se          second
#define mp          make_pair
#define pb          push_back
#define ll          long long
#define ull         unsigned long long
#define ld          long double
#define pii         pair<int, int>
#define nl          '\n'
#define sp          ' '
using namespace std;

const ll MX=100007, MOD=1e6, BLOCK=330, INF=1e9+7;

int N, M, SZ[MX], parCent[MX], best[MX], dep[MX], par[20][MX];
bool dis[MX];
vector<int> adj[MX];

void calcDep(int p, int idx){
    par[0][idx]=p;
    dep[idx]=dep[p]+1;
    for(auto i:adj[idx]){
        if(i!=p)
            calcDep(idx, i);
    }
}
int LCA(int x, int y){
    if(dep[x]>dep[y])
        swap(x, y);
    int diff=dep[y]-dep[x];
    for(int i=0; i<=18; i++){
        if(diff&(1<<i))
            y=par[i][y];
    }
    for(int i=18; i>=0; i--){
        if(par[i][x]!=par[i][y]){
            x=par[i][x];
            y=par[i][y];
        }
    }
    if(x==y)
        return x;
    return par[0][x];
}
int dist(int x, int y){
    if(x==y)
        return 0;
    return dep[x]+dep[y]-2*dep[LCA(x, y)];
}
//Centroid start
int calcSZ(int p, int idx){
    SZ[idx]=1;
    for(auto i:adj[idx]){
        if(i!=p && !dis[i])
            SZ[idx]+=calcSZ(idx, i);
    }
    return SZ[idx];
}
int getCent(int p, int idx, int sz){
    for(auto i:adj[idx]){
        if(i!=p && !dis[i] && SZ[i]*2>sz)
            return getCent(idx, i, sz);
    }
    return idx;
}
int preCent(int x){
    int Cent=getCent(0, x, calcSZ(0, x));
    dis[Cent]=1;
    for(auto i:adj[Cent]){
        if(!dis[i])
            parCent[preCent(i)]=Cent;
    }
    return Cent;
}
//Centroid end
void upd(int x, int y){
    int nxt=parCent[y];
    if(nxt){
        best[nxt]=min(best[nxt], dist(x, nxt));
        upd(x, nxt);
    }
}
int que(int x, int y){
    if(!y)
        return INF;
    return min(dist(x, y)+best[y], que(x, parCent[y]));
}

int main(){
    fastio;
    memset(dis, 0, sizeof(dis));
    cin >> N >> M;
    for(int i=1, u, v; i<N; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dep[0]=0;
    calcDep(0, 1);
    for(int i=1; i<=18; i++)
        for(int j=1; j<=N; j++)
            par[i][j]=par[i-1][par[i-1][j]];
    parCent[preCent(1)]=0;
    for(int i=0; i<=N; i++)
        best[i]=INF;
    best[1]=0;
    upd(1, 1);
    for(int t, v; M--;){
        cin >> t >> v;
        if(t&1){
            best[v]=0;
            upd(v, v);
        }else
            cout << que(v, v) << nl;
    }
}
