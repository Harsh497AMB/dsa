#include<bits/stdc++.h>
using namespace std;

class Stack{
    public:
    int top = -1;
    int arr[10];

    public:
    void push(int num){
        if(top<=10){
        top++;
        arr[top] = num;
    }
    }
    void pop(){
        if(top >-1)top--;
    }
    void top(){
        cout<<arr[top];
    }
};

int main(){

}