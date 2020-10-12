#include <iostream>
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
Node *find(Node *root, int value);
int count(Node* root);
int main()
{
   int n;
    cin >> n;

    Node* treeRoot = new Node(1);
    int p, c;
    for (int i = 0; i < n; ++i) {
        cin >> p >> c;
        addEdge(treeRoot, p, c);
    }

    cout << count(treeRoot) << endl;

    return 0;

    return 0;
}

void addEdge(Node* root, int parent, int child) {
    Node* newNode = new Node(child);
    Node *temp  = find(root, parent);
    temp->children.push_back(newNode);
    // your code goes here
}
Node *find(Node *root, int value){
    if(root==NULL) return NULL;
    if(root->data==value) return root;
    for(int i = 0;i<root->children.size(); i++){
        if(value != root->children[i]->data()) return find(root->children[i], value);
    }
}
bool isBinary(Node* root) {
    if(root==NULL) return true;
    if(root->children.size()>2) return false;
    return root->children[0]&&root->children[1];
}

int height(Node* root) {
    if(root->children.size()==0) return 0;
    int max = height(root->children[0]);
    for(int i = 1; i<root->children.size(); i++){
        if(max<height(root->children[i])) max = root->children[i];
    }
    return max + 1;

}

void postOrder(Node* root) {
    for(int i  = 0; i<root->children.size(); i++){
        postOrder(root->children[i]->data);
    }
    cout << root->data << " ";
    if(root->children.size()==0) return;

}

void preOrder(Node* root) {
     cout << root->data << " ";
     for(int i  = 0; i<root->children.size(); i++){
        postOrder(root->children[i]->data);
    }
    if(root->children.size()==0) return;
}

void inOrder(Node* root) {
   if(root->children.size()==0){
    return;
   }
}
