#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int size;
    int * items;
public:
    Stack (int size){
        this->size = size;
        top = -1;
        items = new int [size];
    }
    int push (int data){
        if (top == size -1){ 
            return 0;
        }
        top++;
        items[top] = data;
        return 1;
    }
    int pop (){
        if (top == -1) {
            cout << "Stack is empty"<<endl;
            return -1; 
        }
        return items[top--];
    }

    void display (){
        int dis =top;
        if (dis == -1){
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i=dis; i>=0; i--){
            cout << items[i] << " "<<endl;
        }
    }
    int peek(){
         if (top == -1) { 
        cout << "Stack is empty"<<endl;
        return -1; 
    }
    return items[top];
    }
    ~Stack(){
         delete[] items;
    }
};
void print (){
    cout<<"----------------------------------------------------------"<<endl;
}
int main() {
Stack stack(5); 

stack.push(90) ? cout << "Success Push\n" : cout << "Failure Push\n";
stack.push(30) ? cout << "Success Push\n" : cout << "Failure Push\n";
stack.push(20) ? cout << "Success Push\n" : cout << "Failure Push\n";
stack.push(70) ? cout << "Success Push\n" : cout << "Failure Push\n";
stack.push(50) ? cout << "Success Push\n" : cout << "Failure Push\n";
stack.push(10) ? cout << "Failure Push\n" : cout << "Stack is full\n";
print();

// Display stack elements
cout << "Current stack:" << endl;
stack.display();
print();

cout << "Popped value = " << stack.pop() << endl;
cout << "Popped value = " << stack.pop() << endl;
cout << "Popped value = " << stack.pop() << endl;
print();

cout << "Top element (peek): " << stack.peek() << endl;
print();

cout << "Popped value = " << stack.pop() << endl;
cout << "Popped value = " << stack.pop() << endl;
cout << "Popped value = " << stack.pop() << endl; // should show "Stack is empty"
print();

return 0;
}
