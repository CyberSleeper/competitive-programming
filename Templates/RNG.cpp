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
#define pii         pair<ll, ll>
#define ld          long double
#define calc(x, y)  (sqr(X[x]-X[y])+sqr(Y[x]-Y[y]))
#define nl          '\n'
#define sqr(x)      (x)*(x)
#define tb          '\t'
#define sp          ' '
using namespace std;

const ll MX=150005, MOD=1000000007, BLOCK=395, INF=2e9+7;
const ll INFF=1000000000000000007;
const ld ERR=1e-6, pi=3.14159265358979323846;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

ll N;
int main(){
    fastio;
    ofstream cout("inputf.in");
    cin >> N;
    cout << N << nl;
    for(int i=1; i<=N; i++){
        ll le, ri;
        ri=rng()%10;
        ri=ri*ri%10;
        le=rng()%(ri+1);
        le=le*le%(ri+1);
        cout << le << sp << ri << nl;
    }
}
