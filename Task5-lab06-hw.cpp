#include <iostream>
using namespace std;

class Queue{
    int rear, front, capacity;
    int *arr;
    public:

    Queue(int c){
        rear = front = -1;
        capacity = c;
        arr = new int[capacity];
    }
    ~Queue(){
        delete[] arr;
    }

    void enqueue(int ID){
        cout<<"Customer "<<ID<<" added to queue"<<endl;
        if(isEmpty()){
            front = rear = 0;
            arr[0] = ID;
            return;
        }
        else if(isFull()) return;
        
        rear = (rear+1)%capacity;
        arr[rear] = ID;
    }

    void Dequeue(){
        if(isEmpty()) return;
        cout<<"Customer "<<arr[front]<<" checked out."<<endl;
        if (front == rear){ //one element in queue
            front = rear = -1;
            return;
        }
        front = (front+1)%capacity;
    }

    bool isEmpty(){
        return (front==-1);
    }
    bool isFull(){
        return (rear+1)%capacity == front;
    }
};

int main(){
    Queue checkOutLine(7);
    cout<<"ADDING TO QUEUE"<<endl;
    checkOutLine.enqueue(13);
    checkOutLine.enqueue(7);
    checkOutLine.enqueue(4);
    checkOutLine.enqueue(1);
    checkOutLine.enqueue(6);
    checkOutLine.enqueue(8);
    checkOutLine.enqueue(10);
    cout<<endl<<"CHECKING OUT"<<endl;
    for(int i=0;i<7;i++) checkOutLine.Dequeue();
}
