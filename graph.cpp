#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Node {
public:
    int data;
    vector<Node*> adjNodes;
    bool visited;
    Node(int data) {
        this->data = data;
        this->visited = false;
    }
    ~Node() {}

};

bool comparator(const Node* v1, const Node* v2) {
   return v1->data < v2->data;
}

Node *findNode(Node *node, int target){
    if(!node->visited){
        node->visited = true;
        Node* temp = NULL;
        if(node->data==target) return node;
        for(int i = 0;i<node->adjNodes.size(); i++){
        temp = findNode(node->adjNodes[i], target);
        if(temp!=NULL) return temp;
        }
    return temp;
    }
}
void addVertex(Node *node, int v, int adj){
    Node* newNode = new Node(adj);
    Node *temp  = findNode(node, v);
    if(temp!=NULL) temp->adjNodes.push_back(newNode);
}

void addEdge(Node *v1, Node *v2) {
        v1->adjNodes.push_back(v2);


        v2->adjNodes.push_back(v1);

}


// đệ quy
/*void dfs(Node* node) {
    if (node->visited == false) {
        node->visited = true;
        cout << node->data << " ";
        sort(node->adjNodes.begin(), node->adjNodes.end(), comparator);
        for(int i =0; i<node->adjNodes.size(); i++){
            dfs(node->adjNodes[i]);
        }
    }
}*/
// không dùng đệ quy
void dfs(Node* node){
    stack<Node*> graph;
    graph.push(node);
    while(!graph.empty()){
        // khi không còn đỉnh kề nào chưa duyệt, thì lấy ra khỏi stack
        if(graph.top()->visited) graph.pop();
        if(!graph.empty()){
            if(!graph.top()->visited){
                cout << graph.top()->data << " "; // in đỉnh vừa thăm lần đầu tiên
                graph.top()->visited = true;
            }
            Node *temp = graph.top();
            sort(temp->adjNodes.begin(), temp->adjNodes.end(), comparator);
            // thêm đỉnh kề vào stack
            for(int i = 0; i<temp->adjNodes.size(); i++){
                if(!temp->adjNodes[i]->visited){
                    graph.push(temp->adjNodes[i]);
                    break;
                }
            }
        }
    }
}

void bfs(Node* node) {
    // tạo hàng đợi Q
    queue<Node*> graph;
    // thêm node vào Q
    graph.push(node);
    // lặp while Q chưa rỗng
    while(!graph.empty()){
        // lấy phần tử đầu Q
        // in ra
        Node *temp = graph.front();
        if(!temp->visited){
            temp->visited = true;
            cout << temp->data << " ";
        }
        // thêm tất cả nút liền kề vào Q (tăng dần)
        if(!graph.empty()){
            graph.pop();
            sort(temp->adjNodes.begin(), temp->adjNodes.end(), comparator);
            for(int i = 0; i<temp->adjNodes.size(); i++){
                if(!temp->adjNodes[i]->visited)   graph.push(temp->adjNodes[i]);
            }
        }
    }
}
int main(){
    Node* v0 = new Node(0);
    Node* v1 = new Node(1);
    Node* v2 = new Node(2);
    Node* v3 = new Node(3);
    Node* v4 = new Node(4);
    Node* v5 = new Node(5);
    addEdge(v0,v1);
    addEdge(v0,v5);
    addEdge(v1,v2);
    addEdge(v1,v3);
    addEdge(v2,v3);
    addEdge(v2,v4);

   // cout<< "dfs: ";
    //dfs(v0);
    //cout << endl;
    cout << "bfs: ";
    bfs(v0);




    return 0;
}
