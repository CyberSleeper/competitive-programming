#include <iostream>
using namespace std;
string total(string A, string B){
    string ret="", hasil;
    int simpan;
    if(A.size()<B.size()){
        swap(A, B);
    }
    simpan=0;
    for(int i=1; i<=A.size(); i++){
        simpan+=A[A.size()-i]-'0';
        if(i<=B.size()){
            simpan+=B[B.size()-i]-'0';
        }
        ret+='0'+(simpan%10);
        simpan/=10;
    }
    if(simpan>0){
        ret+='0'+simpan;
    }
    hasil="";
    for(int i=1; i<=ret.size(); i++){
        hasil+=ret[ret.size()-i];
    }
    return hasil;
}
string kurang(string A, string B){
    string ret="", hasil;
    char now;
    int pinjam=0;
    for(int i=1; i<=A.size(); i++){
        now=A[A.size()-i];
        if(B.size()>=i){
            now=now-(B[B.size()-i]-'0');
        }
        now=now-pinjam;
        pinjam=0;
        if(now<'0'){
            pinjam=1;
            now=now+('K'-'A');
        }
        A[A.size()-i]=now;
    }
    if(A[0]<='0'){
        A.erase(0, 1);
    }
    return A;
}
int main(){
    long long N, Q, AQ, BQ;
    string tot, tmp, ans;
    cin >> N;
    string T[N];
    cin >> T[0];
    tot=T[0];
    for(int i=1; i<N; i++){
        cin >> tmp;
        tot=total(tot, tmp);
        T[i]=tot;
    }
    cin >> Q;
    ans="0";
    for(int i=0; i<Q; i++){
        cin >> AQ >> BQ;
        if(AQ>0){
            ans=total(ans, kurang(T[BQ], T[AQ-1]));
        }else{
            ans=total(T[BQ], ans);
        }
    }
    cout << ans << endl;
}
