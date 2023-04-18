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
int N, K, cnt=0;
string S[100007];
int Trie[100007][27];
void Tin(string s){
    int u=0, j;
    for(auto i:s){
        j=i-'a';
        if(!Trie[u][j])
            Trie[u][j]=++cnt;
        u=Trie[u][j];
    }
}
pii DFS(int u){
    bool leaf=1;
    pii now, ret=mp(0, 0);
    for(int i=0; i<26; i++){
        if(!Trie[u][i])
            continue;
        leaf=0;
        now=DFS(Trie[u][i]);
        if(!now.fi)
            ret.fi=1;
        if(!now.se)
            ret.se=1;
    }
    if(leaf)
        return mp(0, 1);
    return ret;
}
int main(){
    //fastio;
    bool F;
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> S[i];
        Tin(S[i]);
    }
    cout << cnt << endl;
    pii ans=DFS(0);
    if((ans.fi && ans.se) || (ans.fi && !ans.se && K&1))
        F=1;
    else
        F=0;
    if(F)
            cout << "First\n";
    else
        cout << "Second\n";
}
