#include <bits/stdc++.h>
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL)
#define fi      first
#define se      second
#define xx      fi.fi
#define yy      fi.se
#define aa      se
#define mp      make_pair
#define pb      push_back
#define ll      long long
#define ld      long double
#define pii     pair<int, int>
#define pl      pair<ll, ll>
using namespace std;
struct line{
    ll m, c;
    ll eval(ll x){ return m*x+c; }
    ld insecX(line l){ return (ld)(c-l.c)/(l.m-m); } //Perpotongan
};
int main(){
    fastio;
    int N;
    cin >> N;
    pair<pl, ll> A[N+1];
    A[0]=mp(mp(0, 0), 0);
    for(int i=1; i<=N; i++)
        cin >> A[i].xx >> A[i].yy >> A[i].aa;
    sort(A+1, A+N+1);
    ll ans=0, f;
    line now;
    deque<line> take;
    take.push_front({0, 0});
    for(int i=1; i<=N; i++){
        while(take.size()>1 && take.back().eval(A[i].yy)<=take[take.size()-2].eval(A[i].yy)) //PopBack klo ada garis yang di bawah convex di paling kanan
            take.pop_back();
        f=take.back().eval(A[i].yy)+A[i].xx*A[i].yy-A[i].aa;
        ans=max(ans, f);
        now={-A[i].xx, f};
        while(take.size()>1 && now.insecX(take[0])>=take[0].insecX(take[1])) //PopFront klo setelah insert line now ada yang di luar convex
            take.pop_front();
        take.push_front(now);
    }
    cout << ans << endl;
}
