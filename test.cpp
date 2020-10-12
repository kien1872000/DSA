#include <iostream>
using namespace std;
int f(int n){
    if(n==1) return 1;
    if(n==0) return 0;
    return f(n-1) + 2*f(n-2);
}
int main(){
    int n;
    cin >> n;
    cout << f(n);



    return 0;
}
