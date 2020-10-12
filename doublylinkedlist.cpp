#include <iostream>
using namespace std;
struct Node{
   private:
        int value;
   public:
    int getValue(){
        return this->value;
    }
    void setValue(int value){
        this->value = value;
    }
    Node *next = NULL;
    Node *prev = NULL;
};
class DoublyLinkedList{
public:
    int size;
    Node *head = NULL;
};
void display(Node* head){
        for(Node *p = head; p!=NULL; p = p->next){
            cout<< p->getValue() << " ";
        }
}
Node* addTail(Node *head, int value){
    Node *newNode = new Node();
    newNode->setValue(value);
    if(head==NULL) return newNode;
    Node *p = head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next = newNode;
    newNode->prev= p;
    return head;

}
Node* sort(Node* head){
    if(head==NULL) return NULL;
    if(head->next == NULL) return head;
    for(Node *p = head->next; p!=NULL; p=p->next){
        Node *p1= p->prev;
        while(p->getValue()<p1->getValue()&&p1->prev!=NULL){
            p1 = p1->prev;
        }
        Node *temp1 = p->prev;
        Node *temp2 = p->next;
        if(head->getValue()>p->getValue()){
            p->next = head;
            head->prev = p;
            p->prev = NULL;
            head = p;
            temp1->next = temp2;
            if(temp2!=NULL) temp2->prev = temp1;
        }
        else{
            if(p1->next!=p){
                p->next = p1->next;
                p1->next->prev = p;
                p1->next = p;
                p->prev = p1;
                temp1->next = temp2;
                if(temp2!=NULL) temp2->prev = temp1;
            }
        }

    }
    return head;

}
int main(){
    DoublyLinkedList list = DoublyLinkedList();
    int n;
    cin >> n;
    for (int i =0; i<n; i++){
        int a;
        cin >> a;
        list.head = addTail(list.head, a);
    }
    display(list.head);
    cout << endl;
    list.head = sort(list.head);
    display(list.head);





}
