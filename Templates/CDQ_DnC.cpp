//https://robert1003.github.io/2020/01/31/cdq-divide-and-conquer.html
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
#define pii         pair<ll, ll>
#define nl          '\n'
#define sp          ' '
using namespace std;

const ll MX=500007, MOD=1e9+7, line=1001;

ll N, tmp;
ll ans[MX];
vector<array<ll, 3>> A;
struct FenTree{
    ll BIT[MX];
    void build(){
        for(ll i=0; i<MX; i++)
            BIT[i]=0;
    }
    void upd(ll x, ll val){
        for(; x<MX; x+=(x&-x))
            BIT[x]+=val;
    }
    ll que(ll x){
        ll ret=0;
        for(; x>0; x-=(x&-x))
            ret+=BIT[x];
        return ret;
    }
}BIT;

void CDQ1(ll le, ll ri){
    if(le==ri)
        return;
    ll mi=(le+ri)/2, a=le, b=mi+1;
    CDQ1(le, mi); CDQ1(mi+1, ri);
    vector<ll> rec;
    vector<array<ll, 3>> tmp;
    while(a<=mi || b<=ri){
        if(a<=mi && (b>ri || A[a][1]>A[b][1])){
            BIT.upd(A[a][2], 1);
            rec.pb(A[a][2]);
            tmp.pb(A[a]);
            a++;
        }else{
            ans[A[b][0]]+=BIT.que(A[b][2]-1);
            tmp.pb(A[b]);
            b++;
        }
    }
    for(ll i=le; i<=ri; i++){
        A[i]=tmp[i-le];
    }
    for(auto i:rec)
        BIT.upd(i, -1);
    rec.clear();
    tmp.clear();
}
void CDQ2(ll le, ll ri){
    if(le==ri)
        return;
    ll mi=(le+ri)/2, a=le, b=mi+1, cnt=0;
    CDQ2(le, mi); CDQ2(mi+1, ri);
    vector<ll> rec;
    vector<array<ll, 3>> tmp;
    while(a<=mi || b<=ri){
        if(a<=mi && (b>ri || A[a][1]<A[b][1])){
            BIT.upd(A[a][2], 1);
            rec.pb(A[a][2]);
            cnt++;
            tmp.pb(A[a]);
            a++;
        }else{
            ans[A[b][0]]+=cnt-BIT.que(A[b][2]);
            tmp.pb(A[b]);
            b++;
        }
    }
    for(ll i=le; i<=ri; i++){
        A[i]=tmp[i-le];
    }
    for(auto i:rec)
        BIT.upd(i, -1);
    rec.clear();
    tmp.clear();
}

int main(){
    fastio;
    memset(ans, 0, sizeof(ans));
    cin >> N;
    A.resize(N+1);
    BIT.build();
    int X[N+1];
    for(ll i=1; i<=N; i++)
        cin >> X[i];
    for(ll i=1; i<=N; i++){
        cin >> A[i][1];
        A[i][2]=X[A[i][1]];
        A[i][0]=i;
    }
    sort(A.begin()+1, A.end());
    vector<array<ll, 3>> base(A);
    CDQ1(1, N);
    A=base;
    CDQ2(1, N);
    ll cnt=0;
    for(ll i=1; i<=N; i++){
        cnt+=ans[i];
        cout << cnt << nl;
    }
}
