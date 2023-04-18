#include <bits/stdc++.h>
#define fastio      ios_base::sync_with_stdio(false); cin.tie(NULL)
#define debug(x)    cout << "Line " << __LINE__ << ", " << #x << " is " << x << endl
#define BP(x)       __builtin_popcount(x)
#define fi          first
#define se          second
#define mp          make_pair
#define pb          push_back
#define ll          long long
#define ull         unsigned long long
#define ld          long double
#define pld         pair<ld, ld>
#define pli         pair<ld, ll>
#define pii         pair<ll, ll>
#define pis         pair<ll, string>
#define pl          pair<ll, ll>
#define arri5        array<ll, 5>
#define nl          '\n'
#define sp          ' '
using namespace std;

const ll MX=50007, INF=1e9+7, MOD=998244353;

vector<int> adj[MX], rev[MX], SCCadj[MX], order, group[MX];
int SCC[MX], N, M, cnt=0, low=0, tot=0;
bool vis[MX];
void add(int u, int v){
    adj[u].pb(v);
    rev[v].pb(u);
}
void DFS1(int x){
    for(auto i:adj[x]){
        if(!vis[i]){
            vis[i]=1;
            DFS1(i);
        }
    }
    order.pb(x);
}
void DFS2(int x){
    for(auto i:rev[x]){
        if(!vis[i]){
            vis[i]=1;
            DFS2(i);
        }
    }
    SCC[x]=cnt;
    group[cnt].pb(x);
}
bool DFS3(int par, int x){
    vis[x]=1;
    for(auto i:group[x]){
        low=max(low, i);
        tot++;
    }
    if(low!=tot)
        return 0;
    for(auto i:SCCadj[x]){
        if(par!=i){
            return DFS3(x, i);
        }
    }
    return 1;
}
int main(){
    fastio;
    cin >> N >> M;
    for(int i=0, u, v; i<M; i++){
        cin >> u >> v;
        add(u, v);
    }
    for(int i=1; i<=N; i++){
        if(!vis[i]){
            vis[i]=1;
            DFS1(i);
        }
    }
    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof(vis));
    for(auto i:order){
        if(!vis[i]){
            cnt++;
            vis[i]=1;
            DFS2(i);
        }
    }
    for(int i=1; i<=N; i++){
        for(auto j:adj[i]){
            if(SCC[i]==SCC[j])
                continue;
            SCCadj[SCC[i]].pb(SCC[j]);
        }
    }
    bool ans=1;
    memset(vis, 0, sizeof(vis));
    DFS3(0, SCC[1]);
    for(int i=1; i<=cnt; i++){
        ans&=vis[i];
    }
    cout << (ans?"YES":"NO") << nl;
}
