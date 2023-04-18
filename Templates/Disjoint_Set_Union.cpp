#include <bits/stdc++.h>
#define fastio      ios_base::sync_with_stdio(false); cin.tie(NULL)
#define debug(x)    cout << "Line " << __LINE__ << ", " << #x << " is " << x << endl
#define fi          first
#define se          second
#define mp          make_pair
#define pb          push_back
#define ll          long long
#define pll         pair<ll, ll>
#define ull         unsigned long long
#define ld          long double
#define pii         pair<ll, ll>
#define nl          '\n'
#define tb          '\t'
#define sp          ' '
using namespace std;

const ll MX=1000007, MOD=1e9+7, BLOCK=330, INF=1e9+7;
const ld ERR=1e-7, pi=3.14159265358979323846;

int N, Q, H[MX], Y[MX];

struct DSU{
    int par[MX];
    DSU(){
        for(int i=0; i<MX; i++){
            par[i]=i;
        }
    }
    int f(int u){
        if(par[u]!=u)
            par[u]=f(par[u]);
        return par[u];
    }
    void join(int u, int v){
        u=f(u);
        v=f(v);
        if(u==v)
            return;
        par[u]=v;
    }
};

int main(){
    fastio;
    cin >> N >> Q;
    for(int i=0; i<N; i++)
        cin >> H[i];
    for(int i=0; i<Q; i++)
        cin >> Y[i];
}
