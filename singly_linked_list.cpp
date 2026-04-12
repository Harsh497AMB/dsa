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

    public:
    Node(int data1 , Node* next1){
        data = data1;
        next = next1;
    }
};


Node* convertArratToLL(vector<int> v){
        Node* head = new Node(v[0]);
        Node* mover = head;

        for(int i=1 ; i<v.size() ; i++){
            Node* temp = new Node(v[i]);
            mover->next =  temp;
            mover = temp;
        }
        return head;
    }

void printLL(Node* head){
        Node* mover = head;
        
        while(mover != nullptr){
            cout<<mover->data<< " ";
            mover = mover->next;
        }
        cout<<endl;
    }

int lengthOfLL(Node* head){
    Node* mover = head;
    int cnt=0;
    while(mover != nullptr){
        cnt++;
        mover = mover->next;
    }
    return cnt;
}

int searchEle(Node* head , int val){
    Node* mover = head;
    while(mover != nullptr){
        if(mover->data == val) return 1;
        mover = mover->next;
    }
    return 0;
}

Node* insertEleAtHead(Node* head , int k){
    Node* temp = new Node(k);
    temp->next = head;
    return temp;
}

Node* insertAtTail(Node* head ,  int val){
    if(head == NULL) return new Node(val);

    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(val);
    return head;
}

Node* insertAtKth(Node* head , int k , int val){
    if(head == NULL) return new Node(val);

    if(k==1){
        Node* newNode = new Node(val);
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        k--;
        if(k==0){
            Node* newNode = new Node(val);
            prev->next = newNode;
            newNode->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* insertB4K(Node* head ,int val){
    Node* temp = head;
    if(head == NULL) return new Node(val);
    if(val <= head->data){
        return new Node(val , head);
    }
        else return NULL;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp ->data > val){
            Node* newNode = new Node(val);
            prev->next = newNode;
            newNode->next = temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteHeadOfLL(Node* head){
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* deleteTailOfLL(Node* head){
    if(head == nullptr) return nullptr;
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* deleteKthEle(Node* head , int k){
    if(head == nullptr || head->next == nullptr) return nullptr;
    
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;

    while(temp != nullptr){
        cnt++;
        if(cnt==k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteVal(Node* head , int val){
    if(head == nullptr) return nullptr;

    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(temp->data == val){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}
int main(){
    vector<int> v = {1,4,6,7,8,34};
    Node* head = convertArratToLL(v);
    // cout<<head<<endl;
    // printLL(head);
    // cout<<lengthOfLL(head)<<endl;
    // cout<<searchEle(head , 6)<<endl;
    // head = insertEleAtHead(head , 7);
    // printLL(head);
    // head = deleteHeadOfLL(head);
    // printLL(head);
    // head = deleteKthEle(head , 3);
    // printLL(head);
    // head = deleteKthEle(head , 6);
    // printLL(head);
    // head = deleteVal(head , 9);
    // printLL(head);
    // head = insertAtTail(head , 9);
    // printLL(head);
    // head = insertAtKth(head , 1 ,69);
    // printLL(head);
    head = insertB4K(head , 0);
    printLL(head);
}