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
ll MOD=1e9+7;
struct Matrix{
    int N, M;
    vector<vector<ll>> val;
    Matrix(int n, int m, ll id=0ll){
        N=n, M=m;
        val.assign(N, vector<ll>(M, 0ll));
        for(int i=0; i<min(N, M); i++)
            val[i][i]=id;
    }
    Matrix operator * (Matrix b){
        Matrix ret{N, b.M};
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                for(int k=0; k<b.M; k++){
                    (ret.val[i][k]+=val[i][j]*b.val[j][k])%=(MOD-1);
                }
            }
        }
        return ret;
    }
};
Matrix Mpou(Matrix x, ll y){
    Matrix simp(3, 3, 1);
    if(!y)
        return simp;
    while(y>1){
        if(y&1)
            simp=simp*x;
        x=x*x;
        y/=2;
    }
    return x*simp;
}
ll pou(ll x, ll y){
    ll simp=1;
    if(!y)
        return 1;
    while(y>1){
        if(y&1)
            simp=(simp*x)%MOD;
        x=(x*x)%MOD;
        y/=2;
    }
    return (x*simp)%MOD;
}
int main(){
    fastio;
    ll N, C, F[3];
    Matrix base(3, 3);
    cin >> N >> F[0] >> F[1] >> F[2] >> C;
    F[0]=(F[0]*pou(C, 1))%MOD;
    F[1]=(F[1]*pou(C, 2))%MOD;
    F[2]=(F[2]*pou(C, 3))%MOD;
    base.val[0][1]=base.val[0][2]=base.val[0][0]=base.val[1][0]=base.val[2][1]=1;
    base=Mpou(base, N-3);
    C=pou(pou(C, N), MOD-2);
    for(int i=0; i<3; i++){
        Matrix tmp{3, 1};
        tmp.val[2-i][0]=1;
        ll pangkat=(base*tmp).val[0][0];
        C=C*pou(F[i], pangkat)%MOD;
    }
    cout << C << nl;
}
