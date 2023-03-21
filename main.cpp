#include <iostream>
#include <new>

using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x, Node *n){
        data=x;
        next=n;
    }
};

class Queue{
    Node *front=NULL;
    Node *back=NULL;

public:
    void enqueue(int x){
       Node *tempNode=new Node(x, nullptr);

        if (front==NULL && back==NULL){
            front=tempNode;
            back=tempNode;
        }
        else{
            back->next=tempNode;
            back=tempNode;
        }
        cout<<tempNode->data<<" was added on queue."<<endl;
    }

    void dequeue() {
        if (isEmpty())
            cout << "Queue is already empty!" << endl;
        else {
            Node *temp = front;
            front = front->next;
            cout << temp->data << " was removed from queue." << endl;
            delete temp;
        }

        if (front == NULL)
            back = NULL;
    }

    bool isEmpty(){
        if (front == NULL)
            return true;
        else
            return false;
    }

    void top(){
        if (isEmpty())
            cout<<"Queue is empty!"<<endl;
        else
            cout<<"Top element of the queue is:"<<front->data<<endl;
    }

    int size(){
        int counter=0;
        Node *current=front;
        while (current!=NULL){
            counter++;
            current=current->next;
        }
        return counter;
    }
};


int main() {
    Queue myQueue;

    myQueue.enqueue(15);
    myQueue.enqueue(25);
    myQueue.enqueue(40);
    myQueue.enqueue(60);
    myQueue.top();
    myQueue.dequeue();
    myQueue.top();
    cout<<"Size of the queue is:"<<myQueue.size();

    return 0;
}
