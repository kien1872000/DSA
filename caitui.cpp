#include <iostream>
using namespace std;
// quy hoach dong
int max_value_d(int n, int M, int w[], int V[]){
    int k[n+1][M+1];
    for(int i  = 0; i<=M; i++) k[0][i] = 0;
    for(int i = 1; i<=n; i++){
        for(int j = 0; j<=M; j++){
            k[i][j] = k[i-1][j];
            if(j>=w[i]){
                if(k[i-1][j]<(k[i-1][j-w[i]]+V[i])) k[i][j] = k[i-1][j-w[i]] + V[i];
            }
        }
    }
    return k[n][M];
}
// đệ quy
int max_value_r(int n, int M, int w[], int V[]){
    if(M==0||n==0) return 0;
    if(M>=w[n]&&((max_value_r(n-1, M-w[n],w, V) + V[n])>max_value_r(n-1,M, w, V))) return  max_value_r(n-1, M-w[n], w, V) + V[n];
    return max_value_r(n-1,M, w, V);
}
int main(){
    int n, M;
    cin >> n >> M;
    int w[n+1],V[n+1];
    w[0] = 0;
    V[0] = 0;
    for(int  i =1; i<=n; i++){
        cin >> w[i] >> V[i];
    }
    cout << max_value_r(n, M, w, V);

    return 0;
}
