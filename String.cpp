#include <iostream>
#include <string.h>
using namespace std;
void balance(string &str1, string &str2){
    while(str1.length()<str2.length()){
        str1 = '0'+str1;
    }
    while(str2.length()<str1.length()){
        str2 = '0' +str2;
    }
}
string subtract(string s1, string s2){
    balance(s1, s2);
    string result;
    int n = s1.length();
    int difference;
    for(int i = n-1; i>=0; i--){
        if(s1[i]>=s2[i]) {
            difference = s1[i]-s2[i];
            if(i==0&&difference==0) break;
            result = (char)(difference+48) + result;

        }
        else {
            difference = s1[i]-s2[i]+10;
            if(i==0&&difference==0) break;
            result = (char)(difference+48) + result;
            s1[i-1] = s1[i-1]-1;
        }
    }
    return result;
}
string addition(string s1, string s2){
    balance(s1, s2);
    string result;
    int n = s1.length();
    for(int i = n-1; i>=0; i--){
        int sum = s1[i]-48 + s2[i]-48;
        if(sum<10) result =(char)(sum+48)+result;
        else {
            if(i==0){
                result = (char)(sum+48-10)+result;
                result = '1' +result;
            }
            else{
                 result = (char)(sum+48-10)+result;
                s1[i-1] = s1[i-1]+1;
            }
        }
    }
    return result;
}

int main(){
   string str, str1, str2;
   cin >> str;
   int check = 0;
   int op = 0;
   for(int i = 0; i<str.length(); i++){
        if(check==1) str2 =  str2 + str[i];
        if(str[i]=='+'){
            check = 1;
            op=0;
        }
         if(str[i]=='-'){
            check = 1;
            op=1;
        }
        if(check==0)str1 = str1 + str[i];
   }

   if(op==0) cout << addition(str1, str2);
   else cout << subtract(str1, str2);

}
