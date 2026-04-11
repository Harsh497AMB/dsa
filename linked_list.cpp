#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* convertArrToLL(vector<int> v){
    Node* head = new Node(v[0]);
    Node* mover = head;
    
    for(int i=1 ; i<v.size() ; i++){
        Node* temp = new Node(v[i]); 
        mover->next = temp;
        mover = temp;
    }
    return head;
}

/*
1. Node* temp = new Node();
   → temp stores address of new node

2. mover->next = temp;
   → link current node to new node

3. mover = temp;
   → move mover to new node
*/

void traverseLinkedList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int lengthOfLL(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int checkIfElePresentInLL(Node* head , int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;
        temp = temp->next;
    }
    return 0;
}

int main(){
    vector<int> arr = {9,1,2,3,4};
    Node* head = convertArrToLL(arr);
    Node* temp = head;
    traverseLinkedList(head);
    cout<<endl<<lengthOfLL(head);
    cout<<endl<<checkIfElePresentInLL(head , 8);
}