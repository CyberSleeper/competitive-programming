#include <bits/stdc++.h>
#define fastio      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x)    cout << "Line " << __LINE__ << ", " << #x << " is " << x << endl
#define fi          first
#define se          second
#define mp          make_pair
#define pb          push_back
#define ll          long long
#define ld          long double
#define pii         pair<ll, ll>
#define pll         pair<ll, ll>
#define nl          '\n'
#define tb          '\t'
#define sp          ' '
using namespace std;

const ll MX=200005, MOD=1e9+7, BLOCK=327, INF=2e9+7;
const ll INFF=1e18+7;
const ld ERR=1e-7, pi=3.14159265358979323846;

ll N;
pii base;

ll cross(pii x, pii y, pii z){
    y.fi-=x.fi, z.fi-=x.fi;
    y.se-=x.se, z.se-=x.se;
    return (y.fi*z.se)-(y.se*z.fi);
}
ll dist(pii x, pii y){
    y.fi-=x.fi;
    y.se-=x.se;
    return (y.fi*y.fi)+(y.se*y.se);
}
bool cmp(pii x, pii y){
    ll t=cross(base, x, y);
    return (t?t>0:dist(base, x)<dist(base, y));
}

int main(){
    fastio;
    while(1){
        cin >> N;
        if(!N)
            break;
        vector<pii> A(N), B, CH;
        for(ll i=0, x, y; i<N; i++){
            cin >> x >> y;
            A[i]={x, y};
        }

        base=A[min_element(A.begin(), A.end())-A.begin()];
        for(auto i:A){
            if(i!=base)
                B.pb(i);
        }
        sort(B.begin(), B.end(), cmp);
        CH.pb(base);
        for(auto i:B){
            while(CH.size()>1 && cross(CH[CH.size()-2], CH.back(), i)<=0)
                CH.pop_back();
            CH.pb(i);
        }
        cout << CH.size() << nl;
        for(auto i:CH)
            cout << i.fi << sp << i.se << nl;
    }
}
