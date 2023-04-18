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
        ofstream cout("TC.txt", ios::out);
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        int N=rng()%10+1;
        cout << N << nl;
        for(int i=0; i<N; i++){
            cout << rng()%(N+1) << ' ' << rng()%10001 << nl;
        }
}
