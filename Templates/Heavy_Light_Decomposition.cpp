// prob: Path Queries II, https://cses.fi/problemset/task/2134
#include <bits/stdc++.h>
#define fastio      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x)    cout << "Line " << __LINE__ << ", " << #x << " is " << x << endl
#define all(x)      x.begin(), x.end()
#define fi          first
#define se          second
#define mp          make_pair
#define pb          push_back
#define ll          long long
#define ull         unsigned long long
#define pll         pair<ll, ll>
#define pii         pair<int, int>
#define ld          long double
#define nl          '\n'
#define tb          '\t'
#define sp          ' '
#define sqr(x)      (x)*(x)
#define arr3        array<int, 3>
#define arr4        array<ll, 4>
using namespace std;
 
const int MX=200005, MOD=998244353, BLOCK=160, INF=1e9+7, LG=62, key1=177013, key2=353707;
const ll INFF=1000000000000000007;
const ld ERR=1e-6, pi=3.14159265358979323846;
 
int N, Q, A[MX], sz[MX], root[MX], loc[MX], dep[MX], par[MX];
vector<int> adj[MX], order;
 
struct SegTree{
 
    #define idxl        (idx*2+1)
    #define idxr        (idx*2+2)
    #define mi          (le+ri)/2
 
    int ST[8*MX], letar, ritar, val;
 
    void build(int idx, int le, int ri){
        if(le==ri){
            ST[idx]=A[order[le]];
            return;
        }
        build(idxl, le, mi);
        build(idxr, mi+1, ri);
        ST[idx]=max(ST[idxl], ST[idxr]);
    }
    void upd(int idx, int le, int ri){
        if(ritar<le || ri<letar)
            return;
        if(letar<=le && ri<=ritar){
            ST[idx]=val;
            return;
        }
        upd(idxl, le, mi);
        upd(idxr, mi+1, ri);
        ST[idx]=max(ST[idxl], ST[idxr]);
    }
    int que(int idx, int le, int ri){
        if(ritar<le || ri<letar)
            return -INF;
        if(letar<=le && ri<=ritar){
            return ST[idx];
        }
        return max(que(idxl, le, mi), que(idxr, mi+1, ri));
    }
 
    void update(int x, int v){
        letar=ritar=x;
        val=v;
        upd(0, 0, N-1);
    }
    int query(int le, int ri){   
        letar=le, ritar=ri;
        return que(0, 0, N-1);
    }
}ST;
 
void DFS_sz(int p, int x){
    par[x]=p;
    sz[x]=1;
    for(int &i:adj[x]){
        if(i==p)
            continue;
        dep[i]=dep[x]+1;
        DFS_sz(x, i);
        sz[x]+=sz[i];
        if(adj[x][0]==p || sz[i]>sz[adj[x][0]])
            swap(i, adj[x][0]);
    }
}
void DFS_hld(int p, int x){
    loc[x]=order.size();
    order.pb(x);
    root[x]=((adj[p].size() && adj[p][0]==x) ? root[p] : x);
    for(int i:adj[x]){
        if(i==p)
            continue;
        DFS_hld(x, i);
    }
}
 
int main() {
    fastio;
    cin >> N >> Q;
    for(int i=1; i<=N; i++)
        cin >> A[i];
    for(int i=1, u, v; i<N; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    DFS_sz(1, 1);
    DFS_hld(1, 1);
    ST.build(0, 0, N-1);
    for(int t, x, y; Q--;){
        cin >> t >> x >> y;
        if(t&1){
            ST.update(loc[x], y);
        }else{
            int ans=-1;
            while(root[x]!=root[y]){
                if(dep[root[x]]>dep[root[y]])
                    swap(x, y);
                ans=max(ans, ST.query(loc[root[y]], loc[y]));
                y=par[root[y]];
            }
            if(dep[x]>dep[y])
                swap(x, y);
            ans=max(ans, ST.query(loc[x], loc[y]));
            cout << ans << sp;
        }
    }
}