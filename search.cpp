#include <iostream>
#include <algorithm>
using namespace std;
int UCLN(int a, int b){
    if(a==0||b==0) return a+b;
    if(a>b) return UCLN(a%b, b);
    return UCLN(a, b%a);
}
int main(){
    int a, b;
    cin >> a >> b;
    cout << UCLN(a, b);






    return 0;
}
