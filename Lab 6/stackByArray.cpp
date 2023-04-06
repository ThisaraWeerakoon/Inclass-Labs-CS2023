#include<iostream>
using namespace std;

#include <chrono>
using namespace std::chrono;

class Stack{
private:
    int top;// position of last inserted element of stack
    int* arr;//maximum size of array
    int maximumSize;

public:
    Stack(int size){
        top=-1;//initialize empty stack
        maximumSize=size; 
        arr=new int[size];
    }

    bool isEmpty(){
        if(top <0){
            return true; // stack is empty
        }
        else{
            return false; 
        }
    }
    bool isFull(){
        if(top>=maximumSize-1){
            return true; // stack is full
        }
        else{
            return false;
        }
    }

    void push(int element){ // insert element
        if (isFull()){
            cout<<"Stack is full"<<endl;
            return;
        }
        top++; // increment top 
        arr[top]=element;


    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        int temp=arr[top]; // value at the top
        top--; // decrement top  since the array length decreased by 1
        return temp;
    }

    void stackTop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Top elemet: "<<arr[top]<<endl; // top most element of stack
    }

    void display(){
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
            cout << arr[i] << " ";
        cout << endl;
    }


    



};



int main(){
    
    auto start = high_resolution_clock::now(); //start execution

    

    Stack stack1(100);// maximum size is 100
    stack1.push(8);
    stack1.push(10);
    stack1.push(5);
    stack1.push(11);
    stack1.push(15);
    stack1.push(23);
    stack1.push(6);
    stack1.push(18);
    stack1.push(20);
    stack1.push(17);

    stack1.display();

    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();
    stack1.pop();

    stack1.display();

    stack1.push(4);
    stack1.push(30);
    stack1.push(3);
    stack1.push(1);

    stack1.display();

    auto stop = high_resolution_clock::now(); // stop execution
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "time taken in micro seconds for Array Stack "<<duration.count() << endl;





     

}
