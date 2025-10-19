#include <iostream>
using namespace std;
#include <string>
#define maxSize 50

class Stack{
    char *arr;
    int top;

    public:
    Stack(){
        arr = new char[maxSize];
        top = -1;
    }
    ~Stack(){
        delete[] arr;
    }
    void push(char a){
        if(isFull()) return;
        arr[++top] = a;
    }
    char pop(){
        if(isEmpty()) return 0;
        top--;
        return arr[top+1];
    }
    char peek(){
        return arr[top];
    }

    bool isFull(){
        return top+1==maxSize;
    }
    bool isEmpty(){
        return top==-1;
    }
};

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string infixToPostfix(const string &expr){
    Stack opStack; //stores operations
    string postfix = "";

    for (int i = 0; i < expr.size(); i++){
        char c = expr[i];
        if (isdigit(c) || c =='.'||c ==' '){
            postfix += c;}  
        else if (c =='('){
            opStack.push(c); //add to operations
        } 
        else if (c ==')'){
            postfix += ' '; //number ends
            while ( !opStack.isEmpty() && opStack.peek() != '(') { //till the bracket had started
                postfix += opStack.pop();
                postfix += ' ';
            }
            opStack.pop();  //remove (
        }
        else if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
            postfix += ' '; //number ends
            while (!opStack.isEmpty() &&
            ((precedence(opStack.peek()) > precedence(c)) ||
            (precedence(opStack.peek()) == precedence(c) && c != '^'))){
                postfix += opStack.pop();
                postfix += ' ';
            }
            opStack.push(c);
        }
    }
    while(!opStack.isEmpty()){
        postfix+= ' ';
        postfix+=opStack.pop();
    }
    return postfix;
}

int main(){
    string equation = "1+2*(3^4-5)^(6+7*8)-9";
    string in = infixToPostfix(equation);
    cout<<in;
    
    return 0;
}
