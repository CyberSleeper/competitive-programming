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
#define sp          ' '
using namespace std;

const int MX=100007, INF=1e9+7;

int N, Q, A[MX];
struct SegTree{
    #define idxl        (idx*2+1)
    #define idxr        (idx*2+2)
    #define mi          (le+ri)/2
    struct Node{
        ll v, lz;
        Node(ll V=0, ll Lz=0){
            v=V, lz=Lz;
        }
    }id;
    Node ST[4*MX];
    ll val;
    int letar, ritar;
    Node combin(Node x, Node y){
        Node ret(x.v+y.v);
        return ret;
    }
    void prop(int idx, int le, int ri){
        if(ST[idx].lz){
            ST[idx].v+=ST[idx].lz*(ri-le+1);
            if(le<ri)
                ST[idxl].lz+=ST[idx].lz, ST[idxr].lz+=ST[idx].lz;
            ST[idx].lz=0;
        }
    }
    void build(int idx, int le, int ri){
        if(le==ri){
            ST[idx].v=0;
            return;
        }
        build(idxl, le, mi); build(idxr, mi+1, ri);
        ST[idx]=combin(ST[idxl], ST[idxr]);
    }
    void upd(int idx, int le, int ri){
        prop(idx, le, ri);
        if(ri<letar || ritar<le)
            return;
        if(letar<=le && ri<=ritar){
            ST[idx].lz+=val;
            prop(idx, le, ri);
            return;
        }
        upd(idxl, le, mi); upd(idxr, mi+1, ri);
        ST[idx]=combin(ST[idxl], ST[idxr]);
    }
    Node que(int idx, int le, int ri){
        prop(idx, le, ri);
        if(ri<letar || ritar<le)
            return id;
        if(letar<=le && ri<=ritar)
            return ST[idx];
        return combin(que(idxl, le, mi), que(idxr, mi+1, ri));
    }

    void update(int le, int ri, int v){
        letar=le, ritar=ri, val=v;
        upd(0, 0, N-1);
    }
    ll query(int le, int ri){
        letar=le, ritar=ri;
        return que(0, 0, N-1).v;
    }
};
int main(){
    fastio;
    SegTree ST;
    int tc;
    cin >> tc;
    while(tc--){
        SegTree ST;
        int C;
        cin >> N >> C;
        for(int ch, l, r, v; C--; ){
            cin >> ch >> l >> r;
            l--, r--;
            if(ch){
                cout << ST.query(l, r) << nl;
            }else{
                cin >> v;
                ST.update(l, r, v);
            }
        }
    }
}
