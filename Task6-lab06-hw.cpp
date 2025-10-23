#include <iostream>
using namespace std;

struct Node{
    Node* next;
    string msg;
    Node(string m){
        next = nullptr;
        msg = m;
    }
};

class Queue{
    Node* rear, *front;
    public:

    Queue(){
        rear = front = nullptr;
    }
    ~Queue(){
        Node *temp1 = front, *temp2;
        while(temp1){
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
    }

    void enqueue(string msg){
        Node*newnode = new Node(msg);
        if(isEmpty()){
            front = rear = newnode;
        }
        else{
            rear->next = newnode;
            rear = newnode;
        }
        cout<<"Message added: "<<msg<<endl;
    }

    void Dequeue(){
        if(isEmpty()) return;
        cout<<"Message processed: "<<front->msg<<endl;
        Node*temp = front;
        front = front ->next;
        delete temp;
    }

    bool isEmpty(){
        return (front==nullptr);
    }
};

int main(){
    Queue msgs;
    msgs.enqueue("Hello");
    msgs.enqueue("How are you");
    msgs.enqueue("Goodbye!");
    cout<<endl;
    for(int i=0;i<3;i++) msgs.Dequeue();

    return 0;
}
