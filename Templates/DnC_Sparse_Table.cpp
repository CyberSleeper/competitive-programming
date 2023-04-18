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

const ll MX=1000007, MOD=1e9+7, line=1001;

ll N, P, Q, B[400007], A[MX], dat[22][MX];
ll combin(ll x, ll y){
    return x*y%P;
}
void DC(ll le, ll ri, ll dep){
    if(le==ri)
        return;
    ll mi=(le+ri)/2;

    dat[dep][mi]=A[mi];
    for(ll i=mi-1; i>=le; i--)
        dat[dep][i]=combin(A[i], dat[dep][i+1]);
    dat[dep][mi+1]=A[mi+1];
    for(ll i=mi+2; i<=ri; i++)
        dat[dep][i]=combin(A[i], dat[dep][i-1]);
    DC(le, mi, dep+1); DC(mi+1, ri, dep+1);
}
ll que(int le, int ri){
    int L=0, R=N-1, M, dep=0;
    while(1){
        M=(L+R)/2;
        if(le<=M && M<ri)
            return combin(dat[dep][le], dat[dep][ri]);
        dep++;
        if(ri<=M)
            R=M;
        else
            L=M+1;
    }
}
int main(){
    fastio;
    ll tc;
    cin >> tc;
    while(tc--){
        cin >> N >> P >> Q;
        for(ll i=0; i<N; i++){
            cin >> A[i];
        }
        DC(0, N-1, 0);
        for(ll i=0; i<Q/64+2; i++)
            cin >> B[i];
        ll X=0ll, L, R;
        for(ll i=0; i<Q; i++){
            if(i%64){
                L=(L+X)%N;
                R=(R+X)%N;
            }else{
                int j=i/64;
                L=(B[j]+X)%N;
                R=(B[j+1]+X)%N;
            }
            if(L>R)
                swap(L, R);
            if(L<R){
                X=que(L, R);
                X=(X+1)%P;
            }else{
                X=A[L]%P;
                X=(X+1)%P;
            }
        }
        cout << X << nl;
    }
}
