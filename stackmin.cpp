    #include <iostream>
    #include <stack>
    using namespace std;
    int main(){
        stack<int> st;
        bool check = false;
        int min = 0;
        int min_pre = 0;
        int n;
        cin >> n;
        for(int i = 0; i<n; i++){
            int op;
            cin >> op;
            switch(op){
            case 1:
                int x;
                cin >> x;
                st.push(x);
                if(check == false){
                    min = x;
                    check = true;
                }
                min_pre = min;
                if(min >x) min = x;
                break;
            case 2:
                st.pop();
                min = min_pre;
                break;
            case 3:{
                cout << min << endl;
                break;
            }
            default:
                break;
            }

        }

        return 0;

    }

