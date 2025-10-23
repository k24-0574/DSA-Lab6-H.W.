#include <iostream>
#include <string>
using namespace std;

class Queue {
    string *arr;
    int size, front, rear;
    public:
    Queue(int s){
        size = s;
        arr = new string[size];
        front = rear = -1;
    }
    ~Queue(){
        delete[] arr;
    }
    bool isEmpty(){
        return front == -1;
    }
    bool isFull(){
        return rear == size-1;
    }

    void enqueue(string name){
        if (isFull()){
            cout<<"queue is full."<<endl;
            return;
        }
        if (isEmpty()) front = rear = 0;
        else rear++;
        
        arr[rear] = name;
        cout<<name<<" has entered the queue."<<endl;
    }

    void dequeue(){
        if (isEmpty()){
            cout<<"No patrons to service."<<endl;
            return;
        }
        cout<<arr[front]<<"'s book transaction completed."<<endl;

        if (front==rear) front=rear=-1;//one element left
        else front++;
    }

    void display(){
        if (isEmpty()){
            cout<<"The queue is empty."<<endl;
            return;
        }

        cout<<"Current patrons waiting: "<<endl;
        for (int i=front; i<=rear; i++){
            cout<<arr[i];
            if (i!=rear) cout<<" -> ";
        }
        cout<<endl;
    }
};

int main(){
    Queue libraryQueue(5); //max 5
    int choice;
    string name;

    do {
        cout<<"***************************"<<endl;
        cout<<"1. Add Patron to Queue"<<endl;
        cout<<"2. Process Patron (Dequeue)"<<endl;
        cout<<"3. Display Queue"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                cout<<"Enter patron name: ";
                getline(cin, name);
                libraryQueue.enqueue(name);
                break;
            case 2:
                libraryQueue.dequeue();
                break;
            case 3:
                libraryQueue.display();
                break;
            case 4:
                cout<<"Exiting system"<<endl;
                break;
            default:
                cout<<"Invalid choice."<<endl;
        }

    }while(choice!=4);

    return 0;
}
