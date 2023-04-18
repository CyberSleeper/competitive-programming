#include <bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL)
#define fi      first
#define se      second
#define mp      make_pair
#define pb      push_back
#define ll      long long
#define ull     unsigned long long
#define ld      long double
#define pii     pair<int, int>
#define pl      pair<ll, ll>
using namespace std;

ll N, K;
vector<int> tmp;
vector<vector<int>> A;
bool udh[57];
void permutation(int le){
    if(le==N){
        A.pb(tmp);
        return;
    }
    for(int i=1; i<=N; i++){
        if(!udh[i]){
            udh[i]=1;
            tmp[le]=i;
            permutation(le+1);
            udh[i]=0;
        }

    }
}
int main(){
    fastio;
    memset(udh, 0, sizeof(udh));
    N=8;
    tmp.resize(N);
    permutation(0);
    for(int i=0; i<A.size(); i++){
        for(int j=0; j<N; j++){
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
}