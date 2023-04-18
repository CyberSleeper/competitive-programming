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

const int MX=100007, MOD=1e9+7, INF=1e9+7;

int M, A[MX], sz=1;

struct SegTree{
    #define mi      (le+ri)/2
    #define idxl    ST[idx].lc
    #define idxr    ST[idx].rc

    struct Node{
        int sum, lz, lc, rc;
        Node(){
            sum=lz=0;
            lc=rc=-1;
        }
    }id;
    Node ST[128*MX];
    int letar, ritar;

    void ass(int idx){
        if(idxl==-1)
            idxl=sz++;
        if(idxr==-1)
            idxr=sz++;
    }
    void prop(int idx, int le, int ri){
        if(ST[idx].lz){
            ST[idx].sum=(ri-le+1);
            if(le<ri){
                ass(idx);
                ST[idxl].lz=ST[idxr].lz=1;
            }
            ST[idx].lz=0;
        }
    }
    void upd(int idx, int le, int ri){
        prop(idx, le, ri);
        if(ri<letar || ritar<le)
            return;
        if(letar<=le && ri<=ritar){
            ST[idx].lz++;
            prop(idx, le, ri);
            return;
        }
        ass(idx);
        upd(idxl, le, mi); upd(idxr, mi+1, ri);
        ST[idx].sum=ST[idxl].sum+ST[idxr].sum;
    }
    int que(int idx, int le, int ri){
        prop(idx, le, ri);
        if(ri<letar || ritar<le)
            return 0;
        if(letar<=le && ri<=ritar)
            return ST[idx].sum;
        ass(idx);
        return que(idxl, le, mi)+que(idxr, mi+1, ri);
    }

    void update(int le, int ri){
        letar=le, ritar=ri;
        upd(0, 0, INF);
    }
    int query(int le, int ri){
        letar=le, ritar=ri;
        return que(0, 0, INF);
    }
};

int main(){
    fastio;
    cin >> M;
    int C=0;
    SegTree ST;
    for(int ch, l, r; M--;){
        cin >> ch >> l >> r;
        l+=C;
        r+=C;
        if(ch&1){
            C=ST.query(l, r);
            cout << C << nl;
        }else{
            ST.update(l, r);
        }
    }
}
