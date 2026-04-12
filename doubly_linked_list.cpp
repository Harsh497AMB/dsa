#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;
    public:
    Node(Node* prev1 , int data1 , Node* next1){
        this->prev = prev1;
        this->data = data1;
        this->next = next1;
    }
};

Node* convertArr2DLL(vector<int> v){
    Node* head = new Node(NULL , v[0] , NULL);
    Node* mover = head;

    for(int i=1 ; i<v.size() ; i++){
        Node* temp = new Node(mover , v[i] , NULL);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* deleteKthEle(Node* head , int k){
    if(head == NULL) return NULL;

    Node* temp = head;
    Node* back = temp->prev;
    Node* front = temp->next;
    
    while(temp != NULL){
        k--;
        if(k==0){
            if(front==NULL && back ==NULL){
                delete temp;
                return NULL;
            }
            else if(front==NULL && back!= NULL){
                back->next = NULL;
                return head;
            }
            else if(front!=NULL && back == NULL){
                front->prev = NULL;
                delete temp;
                return front;
            }
            else{
                back->next = temp->next;
                front->prev = temp->prev;
                delete temp;
                return head;
            }
        }
        temp = temp->next;
        back = temp->prev;
        if(temp!=NULL) front = temp->next;
    }
    return head;
}

// Node* delet(Node* head,int k){
//     Node* temp = head;
//     if(k<0) return NULL;
    
//     while(k!=0){
//         if (k==1){
//             head=head->next;
//             return NULL;
//         }
//         else if(temp->next!=NULL && temp->prev!=NULL){
//             temp->prev->next = temp->next;
//             temp->next->prev=temp->prev;
//             return head;
//         }
//         else{
//             temp->prev->next = NULL;
//             return head;
//         }
//         temp= temp->next;
//         k--;
//     }
//     return head;
// }
int main(){
    vector<int> v = {1,2,3,4,5,6};
    Node* head = convertArr2DLL(v);
    printDLL(head);
    head = deleteKthEle(head ,9);
    printDLL(head);

}