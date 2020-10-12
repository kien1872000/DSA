#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Node{
public:
    int data;
    vector<Node*> children;
    Node* parent;
    Node(int data) {
        this->data = data;
        this->parent = NULL;
    }
    ~Node() {}
};

void addEdge(Node* root, int parent, int child);
bool isBinary(Node* root);
int height(Node* root);
void postOrder(Node* root);
void preOrder(Node* root);
void inOrder(Node* root);
Node *findNode(Node *root, int value);
bool isFullBinary(Node *root);
bool isPerfect(Node *root);
int main()
{

    Node* treeRoot = new Node(0);
    int N;
    cin >> N;
    for (int i = 1; i< N; ++i) {
        int x , y =0;
        cin >> x >> y;
        addEdge(treeRoot, x, y);
    }

    if(isPerfect(treeRoot)) cout << "yes";
    else cout << "no";

    return 0;
}

void addEdge(Node* root, int parent, int child) {
    if(child!=0){
        Node* newNode = new Node(child);
    Node *temp  = findNode(root, parent);
    if(temp!=NULL) temp->children.push_back(newNode);
    }
    // your code goes here
}
Node *findNode(Node *root, int value){
    if(root==NULL) return NULL;
    Node* temp = NULL;
    if(root->data==value) return root;
    for(int i = 0;i<root->children.size(); i++){
        temp = findNode(root->children[i], value);
        if(temp!=NULL) return temp;
    }
    return temp;
}
bool isBinary(Node* root) {
    if(root==NULL||root->children.size()==0) return true;
    if(root->children.size()>2) return false;
    if(root->children.size()==1) return isBinary(root->children[0]);
    return isBinary(root->children[0])&&isBinary(root->children[1]);
}

int height(Node* root) {
    if(root->children.size()==0) return 0;
    int max = height(root->children[0]);
    for(int i = 1; i<root->children.size(); i++){
        if(max<height(root->children[i])) max = height(root->children[i]);
    }
    return max + 1;

}

void postOrder(Node* root) {
    for(int i  = 0; i<root->children.size(); i++){
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
    if(root->children.size()==0) return;

}

void preOrder(Node* root) {
     cout << root->data << " ";
     for(int i  = 0; i<root->children.size(); i++){
        preOrder(root->children[i]);
    }
    if(root->children.size()==0) return;
}

void inOrder(Node* root) {
    if(root->children.size()==0){
        cout << root->data << " ";
        return;
    }
    if(root->children.size()==1){
         inOrder(root->children[0]);
         cout<< root->data << " ";
    }
    else {
        inOrder(root->children[0]);
        cout<<root->data<<" ";
        inOrder(root->children[1]);
    }
}
int depth(Node *root){

}
bool isFullBinary(Node*root){
    if(!isBinary(root)) return false;
    if(root->children.size()==0) return true;
    if(root->children.size()==1) return false;
    return isFullBinary(root->children[0])&&isFullBinary(root->children[1]);
}
bool isPerfect(Node *root){
    if(!isFullBinary(root)) return false;
    if(root->children.size()==0) return true;
    return isPerfect(root->children[0])&&isPerfect(root->children[1]);

}

