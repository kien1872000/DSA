#include <iostream>
#include <math.h>
using namespace std;
// de quy
int lcs_r(string x, string y, int m, int n){
    if(m==0||n==0) return 0;
    if(x[m-1]==y[n-1]) return 1+lcs_r(x,y,m-1,n-1);
    return max(lcs_r(x,y,m-1,n), lcs_r(x,y,m,n-1));
}
int lcs_d(string x, string y, int m, int n){
    int l[m+1][n+1];
    for(int i =0; i<=m; i++) l[i][0] = 0;
    for(int i =0; i<=n; i++) l[0][i] = 0;
    for(int  i =1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(x[i-1]==y[j-1]) l[i][j] = 1 + l[i-1][j-1];
            else{
                l[i][j] = max(l[i-1][j], l[i][j-1]);
            }
        }
    }
    return l[m][n];


}
int main(){
    string x, y;
    cin >> x >> y;
    int m = x.length(), n = y.length();
    cout << lcs_d(x,y,m,n);








    return 0;
}
