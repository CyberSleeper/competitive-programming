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
#define dec
using namespace std;

const int MX=200007, INF=1e9+7;

int N, Q;
pii A[MX];
struct FenTree{
    ll BIT[MX];
    void build(int x){
        for(int i=0; i<=x; i++)
            BIT[i]=0;
    }
    void upd(int x, int val){
        for(; x<=N; x+=(x&-x))
            BIT[x]+=val;
    }
    ll que(int x){
        ll ret=0;
        for(; x>0; x-=(x&-x))
            ret+=BIT[x];
        return ret;
    }
};

int main(){
    fastio;
    FenTree BIT;
    int tc;
    cin >> tc;
    for(ll ans; tc--;){
        ans=0;
        cin >> N;
        BIT.build(N);
        for(int i=0; i<N; i++){
            cin >> A[i].fi;
            A[i].se=i+1;
        }
        sort(A, A+N, greater<pii>());
        for(int ii=0; ii<N; ii++){
            auto i=A[ii];
            ans+=BIT.que(i.se);
            BIT.upd(i.se, 1);
        }
        cout << ans << nl;
    }
}
