#include <bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL)
#define fi      first.first
#define se      first.second
#define th      second
#define mp      make_pair
#define pb      push_back
#define ll      long long
#define ull     unsigned long long
#define ld      long double
#define pii     pair<int, int>
#define pl      pair<ll, ll>
using namespace std;
bool cmp(pair<pii, int> a, pair<pii, int> b){
    if(a.fi/320==b.fi/320)
        return a.se<b.se;
    return a<b;
}
int N, M, K, A[100007], pref[100007], cnt[2000007];
ll now=0;
void add(int x){
    now+=cnt[K^x];
    cnt[x]++;
}
void del(int x){
    cnt[x]--;
    now-=cnt[K^x];
}
int main(){
    fastio;
    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        cin >> A[i];
        pref[i]=pref[i-1]^A[i];
    }
    int le, ri, L=1, R=0;
    ll query[M];
    pair<pii, int> Q[M];
    for(int i=0; i<M; i++){
        cin >> le >> ri;
        Q[i]=mp(mp(le-1, ri), i);
    }
    sort(Q, Q+M, cmp);
    for(int i=0; i<M; i++){
        le=Q[i].fi, ri=Q[i].se;
        while(L<le)
            del(pref[L++]);
        while(le<L)
            add(pref[--L]);
        while(R<ri)
            add(pref[++R]);
        while(ri<R)
            del(pref[R--]);
        query[Q[i].th]=now;
    }

    for(int i=0; i<M; i++)
        cout << query[i] << endl;
}
//https://codeforces.com/contest/617/problem/E
