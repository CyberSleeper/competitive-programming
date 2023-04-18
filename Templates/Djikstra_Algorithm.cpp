#include <iostream>
using namespace std;
int V, E, A, B, X, Y, Z, w[2600][2600], dist[2600], pred[2600], u, minDist;
bool visited[2600];
int main(){
    cin >> V >> E >> A >> B;
    for(int i=0; i<=V; i++){
        visited[i]=false;
        dist[i]=100000007;
        pred[i]=-1;
        for(int j=0; j<=V; j++){
            w[i][j]=-1;
        }
    }
    for(int i=0; i<E; i++){
        cin >> X >> Y >> Z;
        w[X][Y]=Z;
        w[Y][X]=Z;
    }
    dist[A]=0;
    while(1){
        u=-1;
        minDist=100000007;
        for(int i=1; i<=V; i++){
            if(!visited[i] && dist[i]<minDist){
                u=i;
                minDist=dist[i];
            }
        }

        if(u==-1){
            break;
        }

        visited[u]=true;
        for(int i=1; i<=V; i++){
            if(w[u][i]>=0){
                if(dist[i]>dist[u]+w[u][i]){
                    dist[i]=dist[u]+w[u][i];
                    pred[i]=u;
                }
            }
        }
    }
    cout << dist[B] << endl;
}
