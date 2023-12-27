#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;


    Node<T>()
    {
        data = T();
        next = nullptr;
        prev=nullptr;
       
    }
    Node<T>(T _data)
    {
        data = _data;
        next = nullptr;
        
    }
    ~Node<T>()
    {
    }
};
template <class T>
class queueLinkedList{
    Node<T>* front;
    Node<T>* rear;
    int count;
    public:
    queueLinkedList(){
        front=nullptr;
        rear=nullptr;
        count=0;
    }
    queueLinkedList(queueLinkedList& queue){
        front=nullptr;
        rear=nullptr;
        count=0;
        Node<T> *copyNode = queue.front;
        while (copyNode!=nullptr)
        {
            enqueue(copyNode->data);
            copyNode=copyNode->next;
            
        }
        
    }
    void enqueue(T data){
        Node<T>* newNode=new Node(data);
        if(count==0){
            front=newNode;
            rear=front;
            
        }
        else{
            newNode->prev=rear;
            rear->next=newNode;
            rear=newNode;
        }
        count++;

    }
    T dequeue(){
        if(front==nullptr){
            cout<<"empty queue"<<endl;
            return T();
        }
        else{
            T data=front->data;
            Node<T>* temp=front;
            front=front->next;
            delete temp;
            count--;
            return data;

        }
    }
    void displayAllElements(){
        Node<T>* current= front;
        while(current!=nullptr){
            cout<<current->data<<endl;
            current=current->next;
        }
    }

};


int main(){

    queueLinkedList<int> queue1;
    /*-------------------------------Enqueue--------------------------------*/
    queue1.enqueue(10);
    queue1.enqueue(12);
    queue1.enqueue(18);
    queue1.enqueue(15);
    queue1.enqueue(14);
    queue1.enqueue(1);
    queue1.enqueue(2);
    queue1.enqueue(8);
    queue1.enqueue(5);
    queue1.enqueue(4);
    /*-------------------------------Dequeue--------------------------------*/
    cout<<"-------------------------------Dequeue--------------------------------"<<endl;
    cout<<queue1.dequeue()<<endl;
    cout<<queue1.dequeue()<<endl;
    cout<<queue1.dequeue()<<endl;
    cout<<"-------------------------------Display All Elements--------------------------------"<<endl;
    queue1.displayAllElements();
    cout<<"-------------------------------copy constructor--------------------------------"<<endl;
    queueLinkedList<int> queue2(queue1);
    queue2.displayAllElements();





    

    return 0;
}