
#include <iostream>
using namespace std;

#include <chrono>
using namespace std::chrono;

//Node of the linked list
class Node {
public:
	int value; // data of node
	Node* pointer; // pointer to next node
	
	
	Node(int value)
	{
		this->value = value;
		this->pointer = NULL;
	}
};

class Stack {
	Node* top;

public:

	Stack() { 
        top = NULL; 
    }

	void push(int element)
	{
		Node* x = new Node(element);		
		x->value = element;
		x->pointer = top;
		top = x;
	}

    // check whether it is empty
	bool isEmpty()
	{
		return top == NULL;
	}

	void stackTop()
	{
		
		if (isEmpty()){
			cout<<"Stack is empty"<<endl;
            return;
        }
        cout<<"Top elemet: "<<top->value<<endl; // top most element of stack
	}


	void pop()
	{
		Node* temporaryNode;

		
		if (isEmpty()) {
            cout<<"Stack is empty"<<endl;
		}
		else {
			temporaryNode = top;
			top = temporaryNode->pointer; 
		}
	}

	void display()
	{
		Node* temporaryNode;

		if (isEmpty()) {
            cout<<"Stack is empty"<<endl;
		}
		else {
            cout << "Stack elements: ";
			temporaryNode = top;
			while (temporaryNode != NULL) {

				cout << temporaryNode->value<<" ";

				temporaryNode = temporaryNode->pointer;

			}
            cout<<endl;
		}
	}
};


int main()
{
	auto start = high_resolution_clock::now(); //start execution

    

    Stack stackLinkedList;// maximum size is 100
    stackLinkedList.push(8);
    stackLinkedList.push(10);
    stackLinkedList.push(5);
    stackLinkedList.push(11);
    stackLinkedList.push(15);
    stackLinkedList.push(23);
    stackLinkedList.push(6);
    stackLinkedList.push(18);
    stackLinkedList.push(20);
    stackLinkedList.push(17);

    stackLinkedList.display();

    stackLinkedList.pop();
    stackLinkedList.pop();
    stackLinkedList.pop();
    stackLinkedList.pop();
    stackLinkedList.pop();

    stackLinkedList.display();

    stackLinkedList.push(4);
    stackLinkedList.push(30);
    stackLinkedList.push(3);
    stackLinkedList.push(1);

    stackLinkedList.display();

    auto stop = high_resolution_clock::now(); // stop execution
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "time taken in micro seconds for Linked List Stack "<<duration.count() << endl;
	
}
