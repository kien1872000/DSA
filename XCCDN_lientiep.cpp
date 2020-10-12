#include <iostream>
#include <math.h>
using namespace std;
int lcs_r(int count, int m, int n,string x, string y){
    if(m==0||n==0)
        return count;
    if(x[m-1]==y[n-1])
        count = lcs_r(count+1, m-1, n-1, x, y);
    count = max(count, max(lcs_r(0,m,n-1,x,y), lcs_r(0,m-1,n,x,y)));
    return count;
}
int lcs_d(string x, string y, int m, int n){
    int max_length = 0;
    int L[m+1][n+1];
    for(int i = 0; i<=m; i++) L[i][0] = 0;
    for(int j = 0; j<=n; j++) L[0][j] = 0;
    for(int i = 1; i<=m; i++){
        for(int j = 1; j<=n; j++){
            if(x[i-1]==y[j-1]){
                L[i][j] = 1 + L[i-1][j-1];
                if(max_length < L[i][j]) max_length = L[i][j];
            }
            else L[i][j] = 0;
        }
    }
    return max_length;

}
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    int m = str1.length();
    int n = str2.length();
    cout << lcs_d(str1,str2,m,n);







    return 0;
}
