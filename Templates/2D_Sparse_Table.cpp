#include <bits/stdc++.h>
#define fastio      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x)    cout << "Line " << __LINE__ << ", " << #x << " is " << x << endl
#define fi          first
#define se          second
#define mp          make_pair
#define pb          push_back
#define ll          long long
#define ull         unsigned long long
#define ld          long double
#define pii         pair<short, short>
#define pll         pair<ll, ll>
#define ar3         array<ll, 3>
#define nl          '\n'
#define tb          '\t'
#define sp          ' '
using namespace std;

const ll MX=1007, MOD=1e9+7, BLOCK=327, INF=1e9+7, INFF=1e18+7;
const ld ERR=1e-7, pi=3.14159265358979323846;

short N, M, SPARTA[11][MX][11][MX];
int Q;

short RMQ(short x1, short y1, short x2, short y2){
    short basex=__lg(x2-x1+1), basey=__lg(y2-y1+1);
    return max(max(SPARTA[basex][x1][basey][y1],           SPARTA[basex][x1][basey][y2-(1<<basey)+1]),
               max(SPARTA[basex][x2-(1<<basex)+1][basey][y1], SPARTA[basex][x2-(1<<basex)+1][basey][y2-(1<<basey)+1]));
}

int main(){
    fastio;
    cin >> N >> M;
    for(short i=0; i<=N; i++){
        for(short j=0, tmp; j<=M; j++){
            if(!i || !j)
                SPARTA[0][i][0][j]=0;
            else{
                cin >> tmp;
                if(tmp)
                    SPARTA[0][i][0][j]=1+min(SPARTA[0][i-1][0][j-1], min(SPARTA[0][i][0][j-1], SPARTA[0][i-1][0][j]));
                else
                    SPARTA[0][i][0][j]=0;
            }
        }
    }

    for(short i=1; (1<<i)<=N; i++){
        for(short j=1; j+(1<<i)-1<=N; j++){
            for(short l=1; l<=M; l++){
                SPARTA[i][j][0][l]=max(SPARTA[i-1][j][0][l], SPARTA[i-1][j+(1<<(i-1))][0][l]);
            }
        }
    }
    for(short j=1; j<=N; j++){
        for(short k=1; (1<<k)<=M; k++){
            for(short l=1; l+(1<<k)-1<=M; l++){
                SPARTA[0][j][k][l]=max(SPARTA[0][j][k-1][l], SPARTA[0][j][k-1][l+(1<<(k-1))]);
            }
        }
    }

    for(short i=1; (1<<i)<=N; i++){
        for(short j=1; j+(1<<i)-1<=N; j++){
            for(short k=1; (1<<k)<=M; k++){
                for(short l=1; l+(1<<k)-1<=M; l++){
                    SPARTA[i][j][k][l]=max(max(SPARTA[i-1][j][k-1][l],           SPARTA[i-1][j][k-1][l+(1<<(k-1))]),
                                           max(SPARTA[i-1][j+(1<<(i-1))][k-1][l], SPARTA[i-1][j+(1<<(i-1))][k-1][l+(1<<(k-1))]));
                }
            }
        }
    }

    cin >> Q;
    for(short x1, y1, x2, y2; Q--;){
        cin >> x1 >> y1 >> x2 >> y2;
        short ans=0;
        short le=1, ri=min(x2-x1, y2-y1)+1, mi, tmp;
        while(le<=ri){
            mi=(le+ri)/2;
            tmp=RMQ(x1+mi-1, y1+mi-1, x2, y2);
            ans=max(ans, min(tmp, mi));
            if(tmp>=mi)
                le=mi+1;
            else
                ri=mi-1;
        }
        cout << ans << nl;
    }
}
