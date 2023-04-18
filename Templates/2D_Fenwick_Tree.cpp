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
#define pli         pair<ld, ll>
#define pii         pair<ll, ll>
#define pis         pair<ll, string>
#define pl          pair<ll, ll>
#define arri5        array<ll, 5>
#define nl          '\n'
#define sp          ' '
using namespace std;

const int MX=1007, MOD=1e9+7, INF=1e9+7;

int N;
string S[MX];
struct FenTree2D{
    int BIT[MX][MX];
    void upd(int v, int x, int y){
        for(; x<=N; x+=(x&-x))
            for(int j=y; j<=N; j+=(j&-j))
                BIT[x][j]+=v;
    }
    int pref(int x, int y){
        int ret=0;
        for(; x>0; x-=(x&-x))
            for(int j=y; j>0; j-=(j&-j))
                ret+=BIT[x][j];
        return ret;
    }
    int que(int x1, int y1, int x2, int y2){
        return pref(x2, y2)-pref(x1-1, y2)-pref(x2, y1-1)+pref(x1-1, y1-1);
    }
};

int main(){
    fastio;
    int Q;
    FenTree2D BIT;
    cin >> N >> Q;
    for(int i=1; i<=N; i++){
        cin >> S[i];
        S[i]=" "+S[i];
        for(int j=1; j<=N; j++){
            if(S[i][j]=='*')
                BIT.upd(1, i, j);
        }
    }
    for(int ch, x1, y1, x2, y2; Q--;){
        cin >> ch >> x1 >> y1;
        if(ch&1){
            if(S[x1][y1]=='.'){
                S[x1][y1]='*';
                BIT.upd(1, x1, y1);
            }else{
                S[x1][y1]='.';
                BIT.upd(-1, x1, y1);
            }
        }else{
            cin >> x2 >> y2;
            cout << BIT.que(x1, y1, x2, y2) << nl;
        }
    }
}
