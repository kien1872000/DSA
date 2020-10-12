#include <iostream>
using namespace std;
class queue{
    int size = 100;
    int q[100];
    int front = 0;
    int rear = 0;
public:
    bool isEmpty(){
        if(front == 0 && rear ==0) return true;
        return false;
    }
    bool isFull(){
        return rear==size;
    }
    void enqueue(int i){
        if(!isFull()) q[rear++] = i;
        else cout << "queue is full";
    }
    void dequeue(){
        if(!isEmpty()){
            front++;
        }
        else cout << "queue is empty";
        if(front>=rear){
            front = 0;
            rear = 0;
        }
    }
    int peek(){
        if(!isEmpty()) return q[front];
        else{
            cout << "queue is empty";
        }
    }

};
int main(){
        queue q = queue();
        int n;
        cin >> n;
        for(int i = 0; i<n; i++){
            int op;
            cin >> op;
            switch(op){
            case 1:
                int x;
                cin >> x;
                q.enqueue(x);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << q.peek() << endl;
                break;
            default:
                break;
            }

        }










    return 0;
}
