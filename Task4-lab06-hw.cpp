#include <iostream>
using namespace std;
#include <string>
#include <cmath>

template <typename T>
class Stack{
    struct Node{
    Node* next;
    T data;
    Node(T d){
        data = d;
        next = nullptr;
    }
};
    Node* top;
    public:
    Stack(){
        top = nullptr;
    }
    ~Stack(){
        Node *temp1 = top, *temp2;
        while(temp1){
            temp2 = temp1->next;
            delete temp1;
            temp1 = temp2;
        }
    }
    void push(T a){
        Node* newnode = new Node(a);
        if(isEmpty()){
            top = newnode;
        }
        else{
            newnode->next = top;
            top = newnode;
        }
    }
    T pop(){
        if(isEmpty()) return 0;
        T a = top->data;
        Node*temp = top;
        top = top->next;
        delete temp;
        return a;
    }
    T peek(){
        return top->data;
    }

    bool isEmpty(){
        return top==nullptr;
    }
};

int precedence(char op) {
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string ImplicitMultiplication(string eq) {
    string newEq = "";
    for (int i=0; i<eq.size(); i++){
        newEq += eq[i];
        if (isdigit(eq[i]) && i+1<eq.size() && eq[i+1]=='(') newEq += '*';
    }
    return newEq;
}

string infixToPostfix(string eq){
    Stack<char> opStack; //stores operations
    string postfix = "";

    for (int i = 0; i < eq.size(); i++){
        char c = eq[i];
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

double evalPostfix(string postfix){
    Stack<double> st;
    string token = "";

    for(int i=0;i<postfix.length();i++){
        char c = postfix[i];
        if(isdigit(c) || c == '.'){
            token += c;} 
        else if(c == ' '){
            if(!token.empty()){
                st.push(stod(token)); //string to double
                token.clear();
            }
        } 
        else if(c=='+' || c == '-' || c=='*' || c=='/'|| c=='^'){
            double b = st.pop();
            double a = st.pop();
            double res = 0;
            if (c=='+') res = a+b;
            else if (c=='-') res = a-b;
            else if (c=='*') res = a*b;
            else if (c=='/') res = a/b;
            else if (c=='^') res = pow(a, b);
            st.push(res);
        }
    }

    if (!token.empty())  st.push(stod(token)); //string to double
    return st.pop();
}

void solve(string equation){
    equation = ImplicitMultiplication(equation);
    cout<<equation<<endl;
    string var, eq;
    for(int i=0;i<equation.length();i++){
        if(equation[i]=='='){
            var = equation.substr(0, i);
            eq = equation.substr(i+1);
            break;
        }
    }

    string postFix = infixToPostfix(eq);
    cout<<"Post Fix: "<<postFix<<endl;
    double answer = evalPostfix(postFix);
    cout<<"Answer: "<<answer;
}

int main(){
    string equation = "x=12+13-5(0.5+0.5)+1";
    solve(equation);
    
    return 0;
}
