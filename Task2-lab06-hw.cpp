#include <iostream>
using namespace std;

class Node{
    public:
    Node* next;
    string data;
    Node(string task){
        data = task;
        next = nullptr;
    }
};

class Stack{
    Node* top;
    public:
    Stack(){
        top = nullptr;
    }
    ~Stack(){
        Node*temp1 = top, *temp2;
        while(temp1){
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
    }
    void push(string url){
        Node* newnode = new Node(url);
        if(isEmpty()){
            top = newnode;
        }
        else{
            newnode->next = top;
            top = newnode;
        }
    }
    void pop(){
        if(isEmpty()) return;
        Node* temp = top;
        top = top->next;
        delete temp;
    }
    string seekTop(){
        return top->data;
    }

    bool isEmpty(){
        return top==nullptr;
    }

};
int main(){
    Stack webBrowsingHistory;
    webBrowsingHistory.push("Google");
    webBrowsingHistory.push("Facebook");
    webBrowsingHistory.push("Twitter");
    webBrowsingHistory.push("LinkedIn");
    webBrowsingHistory.push("Instagram");

    webBrowsingHistory.pop();
    webBrowsingHistory.pop();
    webBrowsingHistory.pop();

    cout<<"Current web page: "<<webBrowsingHistory.seekTop();

    return 0;
}
