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
int main(){
    fastio;
    int N;
    cin >> N;
    int A[N+1][20];
    for(int i=1; i<=N; i++)
        cin >> A[i][0];
    for(int j=1; (1<<j)<=N; j++){
        for(int i=1; (i+(1<<j)-1)<=N; i++){
            A[i][j]=max(A[i][j-1], A[i+(1<<(j-1))][j-1]);
        }
    }
    cin >> N;
    while(N--){
        int le, ri, r;
        cin >> le >> ri;
        r=log2(ri-le+1);
        if(A[le][0]==A[ri][0] && max(A[le][r], A[ri-(1<<r)+1][r])<=A[ri][0])
            cout << "YA\n";
        else
            cout << "TIDAK\n";
    }
}
