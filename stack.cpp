#include <iostream>
using namespace std;
class Stack{
    int N = 100000;
    char st[100000];
    int top = 0;
public:
    bool isEmpty(){
        return top==0;
    }
    bool isFull(){
       return top == 100;
    }
    void push(int i){
         st[top++] = i;
    }
    void pop(){
        top--;
    }
    int peek(){
        return st[top-1];
    }
};
string isValid(string str){
    Stack st = Stack();
        int n = str.length();
        for(int  i =0; i<n; i++){
            if(str[i]=='('||str[i]=='{'||str[i]=='[') st.push(str[i]);
            if(str[i]==')'){
                if(st.isEmpty()||st.peek()!='(') return "no";
                st.pop();
            }
            else if(str[i]==']'){
                if(st.isEmpty()||st.peek()!='[') return "no";
                st.pop();
            }
            else if(str[i]=='}'){
                if(st.isEmpty()||st.peek()!='{') return "no";
                st.pop();
            }
        }
        if(st.isEmpty()) return "yes";
        return "no";
}
int main(){
    int n;
    cin >> n;
    for(int i =0; i<n; i++){
        string str;
        cin >> str;
        cout<<isValid(str) << endl;
    }




    return 0;
}
