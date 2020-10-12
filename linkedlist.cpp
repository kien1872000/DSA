#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next = NULL;
};
class SinglyLinkedList{
public:
    int size;
    Node *head = NULL;
};
void display(Node* head){
        for(Node *p = head; p!=NULL; p = p->next){
            cout<< p->data << " ";
        }
    }
void add(Node *head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    if(head==NULL) head = newNode;
    else{
       Node *node = head;
       while(node->next!=NULL) node = node->next;
       node->next = newNode;
    }
}
Node* addTail(Node *head, int data){
    Node* newNode = new Node();
    newNode->data = data;
    if(head==NULL){
        head = newNode;
        return head;
    }
    Node *node = head;
    while(node->next!=NULL){
        node = node->next;
    }
    node->next = newNode;
    return head;
}
Node* addPost(Node *head, int index, int data){
    Node *newNode = new Node();
    newNode->data = data;
    Node *node = head;
    if(index==0){
        newNode->next = head;
        head = newNode;
        return head;
    }
    for(int i =0; i<index-1; i++){
        node = node->next;
    }
    if(node->next!=NULL){
        newNode->next = node->next;
        node->next = newNode;
    }
    else node->next = newNode;
    return head;
}
Node* deletePos(Node *head, int index){
    if(index==0) head = head->next;
    else{
            Node *node = head;
        for(int i =0;i < index-1; i++){
            node = node->next;
        }
        if(node->next->next == NULL) node->next = NULL;
        else{
            node->next = node->next->next;
        }
    }
    return head;
}
Node *reverse(Node *head){
    if(head==NULL||head->next==NULL) return head;
    Node *pre, *curr, *temp;
    pre = head;
    curr = head->next;
    temp = curr;
    pre->next = NULL;
    while(temp->next!=NULL){
        temp = curr->next;
        curr->next = pre;
        pre = curr;
        curr = temp;
    }
    curr->next = pre;
    return curr;
}

void printReverse(Node* head, int k){
     if(k==0){
        return;
    }
    printReverse(head->next, k-1);
    cout << head->data << " ";
}
Node* deleteDuplicates(Node* head){
    Node *p1;
    for(Node *p = head; p!=NULL; p=p->next){
        p1 = p;
        while(p1->next!=NULL){
            if(p->data ==p1->next->data){
                p1->next = p1->next->next;
            }
            else{
                p1 = p1->next;
            }
        }
    }
    return head;
}
Node* deleteSingle(Node* head){
    if(head->data!=head->next->data) head = head->next;
    Node *p = head;
    while(p!=NULL&&p->next!=NULL){
        if(p->next->next == NULL){
            if(p->data!=p->next->data){
                p->next = NULL;
                return head;
            }
            else return head;
        }
        if(p->data!=p->next->data&&p->next->data!=p->next->next->data){
            p->next = p->next->next;
        }

        else p = p->next;
    }
    return head;
}
Node* convert(Node* head){
    if(head==NULL) return head;
    int size = 0;
    for(Node *p = head; p!=NULL; p = p->next){
        size++;
    }
    Node *pa = head, *pb;
    int end_a = 0;
    while(end_a<(size-2)/2){
        end_a++;
        pa= pa->next;
    }
    pb = pa->next;
    pa->next = NULL;
    pa = head;

    Node *temp_a = NULL, *temp_b=NULL;
    while(pa!=NULL){
       temp_a = pa;
       pa=pa->next;
       temp_a->next = pb;
       temp_b = pb;
       pb=pb->next;
       temp_b->next = pa;
    }
    return head;
}
Node* insert(Node* head, int value){
    Node *newNode = new Node();
    newNode->data = value;
    if(head==NULL) return newNode;
    if(head->next == NULL){
        if(head->data<newNode->data){
        head->next = newNode;
        return head;
        }
        else{
            newNode->next = head;
            head = newNode;
            return head;
        }
    }
    int check = 0;
    for(Node *p = head; p->next!=NULL; p = p->next){
        if(p->data<p->next->data){
            check = 1;
            break;
        }
    }
    cout << check << endl;
    if(check == 0){
        if(newNode->data>=head->data){
                newNode->next = head;
                head = newNode;
                return head;
            }
        for(Node *p = head; p!=NULL; p= p->next){
            if(p->next == NULL){
                if(newNode->data<=p->data){
                    p->next = newNode;
                    return head;
                }
            }
            if(p->data>=newNode->data&&p->next->data<=newNode->data){
                newNode->next = p->next;
                p->next = newNode;
                return head;
            }
        }
    }
    else{
        if(newNode->data<=head->data){
            newNode->next = head;
            head = newNode;
            return head;
        }
        for(Node *p = head; p!=NULL; p= p->next){
            if(p->next == NULL){
                if(newNode->data>=p->data){
                    p->next = newNode;
                    return head;
                }
            }
            if(p->data<=newNode->data&&newNode->data<=p->next->data){
                newNode->next = p->next;
                p->next = newNode;
                return head;
            }
        }

    }

}
void rotate(Node* head, int k){
    int count  = 0;
    Node *p = head, *p1 = NULL;
    while(count!=k){
        p1 =  p;
        count++;
        p = p->next;
    }
    if(p1!=NULL) p1->next = NULL;
    Node *temp = p;
    while(p!=NULL){
        cout<< p->data << " ";
        p = p ->next;
    }




}
int main(){
    SinglyLinkedList list = SinglyLinkedList();
    list.head = addTail(list.head,0);
    list.head = addTail(list.head,1);
    list.head = addTail(list.head, 2);
   // list.head = addTail(list.head, 3);
   // list.head = addTail(list.head, 4);


    display(list.head);
    cout<< endl;
     list.head = reverse(list.head);
     display(list.head);
  //  display(list.head);
    //list.head = addPost(list.head, 0, 7);
    //display(list.head);




    return 0;
}
