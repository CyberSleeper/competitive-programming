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
#define pli         pair<ld, int>
#define pii         pair<int, int>
#define pis         pair<int, string>
#define pl          pair<ll, ll>
#define nl          '\n'
using namespace std;
int N, M, cnt=1, vis[50007];
bool aman=1;
vector<int> adj[50007];
void DFS(int x){
    vis[x]=cnt;
    for(auto i:adj[x]){
        if(!vis[i])
            DFS(i);
    }
    vis[x]=cnt++;
    for(auto i:adj[x]){
        if(vis[i]>=vis[x])
            aman=0;
    }
}
int main(){
    fastio;
    memset(vis, 0, sizeof(vis));
    cin >> N >> M;
    for(int i=0, u, v; i<M; i++){
        cin >> u >> v;
        adj[u].pb(v);
    }
    for(int i=1; i<=N; i++){
        if(!vis[i])
            DFS(i);
        //debug(vis[i]);
    }
    cout << (aman?"aman":"konflik") << nl;
}
