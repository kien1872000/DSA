 #include <iostream>
#include <math.h>
#include <map>
#include <sstream>
using namespace std;
string toString(int i){
    stringstream ss;
    ss << i;
    return ss.str();
}
int main(){
    map<string, int> myMap;
    string str;
    cin >> str;
    string output;
    for(int i =0; i<str.length(); i++){
        output = str[i];
        myMap[output]++;
        for(int j = i+1; j<str.length(); j++){
            output+=str[j];
            myMap[output] ++;
        }
    }
    cout << myMap.size();
    return 0;
}
