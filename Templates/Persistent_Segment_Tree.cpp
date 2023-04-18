#include <bits/stdc++.h>
#define fastio      ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define debug(x)    cout << "Line " << __LINE__ << ", " << #x << " is " << x << endl
#define all(x)      x.begin(), x.end()
#define fi          first
#define se          second
#define mp          make_pair
#define pb          push_back
#define ll          long long
#define ull         unsigned long long
#define pll         pair<ll, ll>
#define pii         pair<int, int>
#define ld          long double
#define nl          '\n'
#define tb          '\t'
#define sp          ' '
using namespace std;

const ll MX=200005, MOD=998244353, BLOCK=327, INF=2e9+7;
const ll INFF=1e18+7;
const ld ERR=1e-7, pi=3.14159265358979323846;

ll N, A[MX], Q, K=2;

struct SegTree{
    #define mi      (le+ri)/2
    #define idxl    ST[idx].lc
    #define idxr    ST[idx].rc

    struct Node{
        ll val;
        int lc, rc;
        Node(){
            val=0;
            lc=rc=-1;
        }
    };
    Node ST[16*MX];
    int cnt=1, root[MX], letar, ritar, k, x;

    void build(int idx, int le, int ri){
        if(le==ri){
            ST[idx].val=A[le];
            return;
        }
        idxl=cnt++;
        idxr=cnt++;
        build(idxl, le, mi);
        build(idxr, mi+1, ri);
        ST[idx].val=ST[idxl].val+ST[idxr].val;
    }
    void upd(int idx, int le, int ri){
        if(le==ri && le==letar){
            ST[idx].val=x;
            return;
        }
        if(letar>mi){
            ST[cnt++]=ST[idxr];
            idxr=cnt-1;
            upd(idxr, mi+1, ri);
        }else{
            ST[cnt++]=ST[idxl];
            idxl=cnt-1;
            upd(idxl, le, mi);
        }
        ST[idx].val=ST[idxl].val+ST[idxr].val;

    }
    ll que(int idx, int le, int ri){
        if(ri<letar || ritar<le)
            return 0;
        if(letar<=le && ri<=ritar)
            return ST[idx].val;
        return que(idxl, le, mi)+que(idxr, mi+1, ri);
    }

    void update(int kk, int aa, int xx){
        k=kk, letar=ritar=aa, x=xx;
        upd(root[k], 1, N);
    }
    ll query(int kk, int aa, int bb){
        k=kk, letar=aa, ritar=bb;
        return que(root[k], 1, N);
    }
    void dupl(int x, int y){
        root[x]=cnt++;
        ST[root[x]]=ST[root[y]];
    }

} ST;

int main(){
    fastio;
    cin >> N >> Q;
    for(int i=1; i<=N; i++)
        cin >> A[i];
    ST.build(0, 1, N);
    for(int t, k, a, b; Q--;){
        cin >> t >> k;
        if(t==1){
            cin >> a >> b;
            ST.update(k, a, b);
        }else if(t==2){
            cin >> a >> b;
            cout << ST.query(k, a, b) << nl;
        }else{
            ST.dupl(K++, k);
        }
    }
}
