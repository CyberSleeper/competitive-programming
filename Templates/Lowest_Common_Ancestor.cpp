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
#define sp          ' '
using namespace std;

const int MX=200007, INF=1e9+7, MOD=1e9+7;

int N, Q, dep[MX], par[MX][20];
vector<int> adj[MX];
void DFS(int x, int y){
    dep[x]=y;
    for(auto i:adj[x])
        if(dep[i]==-1)
            DFS(i, y+1);
}
int ask(int x, int y){
    if(dep[x]!=dep[y]){
        if(dep[x]<dep[y])
            swap(x, y);
        int r=abs(dep[x]-dep[y]);
        for(int i=18; i>=0; i--){
            if(r&(1<<i))
                x=par[x][i];
        }
    }
    if(x==y)
        return x;
    for(int i=18; i>=0; i--){
        if(par[x][i]!=par[y][i])
            x=par[x][i], y=par[y][i];
    }
    return par[x][0];
}
int main(){
    fastio;
    memset(dep, -1, sizeof(dep));
    cin >> N >> Q;
    for(int i=2, j; i<=N; i++){
        cin >> j;
        par[i][0]=j;
        adj[i].pb(j);
        adj[j].pb(i);
    }
    par[1][0]=par[0][0]=1;
    for(int j=1; j<18; j++){
        for(int i=0; i<=N; i++){
            par[i][j]=par[par[i][j-1]][j-1];
        }
    }
    DFS(1, 1);
    for(int a, b; Q--;){
        cin >> a >> b;
        cout << ask(a, b) << nl;
    }
}
