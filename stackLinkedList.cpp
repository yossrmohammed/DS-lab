#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    
    
  


    Node<T>()
    {
        data = T();
        next = NULL;
        

    }
    Node<T>(T _data)
    {
        data = _data;
        
        next = NULL;
    }
    ~Node<T>()
    {
    }
};
template <class T>
class StackLinkedList{
    private:
    Node<T>* top;
    int count;
    public:
    StackLinkedList(){
        count=0;
        top=NULL;
    }
    void push(T data){
        Node<T>* newNode= new Node(data);
        newNode->next=top;
        top=newNode;
        count++;
    }
    StackLinkedList(StackLinkedList& stack){
        
        count=stack.count;
        Node<T>* oldPtr= stack.top;
        Node<T>* newPtr=NULL;
        Node<T>* newNode= new Node(oldPtr->data);
        top=newNode;
        oldPtr=oldPtr->next;
        newPtr=top;
        while(oldPtr!=NULL){
       newNode= new Node(oldPtr->data);
       newPtr->next=newNode;
       newPtr=newPtr->next;
        oldPtr=oldPtr->next;

        }   
  
        
    }
    T pop(){
        if(top==NULL){
            return T();
        }
        else{
            T data= top->data;
            Node<T>* temp= top;
            top=top->next;
            delete temp;
            count--;
            return data;
        }
    }
    void displayAllElements(){
        Node<T>* current= top;
        while(current!=NULL){
            cout<<current->data<<endl;
            current=current->next;
        }
    }

};



int main(){
    StackLinkedList<int> stack1;
    /*-------------------------------push in satck --------------------------------*/
    stack1.push(5);
    stack1.push(7);
    stack1.push(9);
    stack1.push(10);
    stack1.push(88);
    stack1.push(55);
    stack1.push(77);
    stack1.push(50);
    stack1.push(90);
    stack1.push(100);
    /*-------------------------------pop--------------------------------*/
cout<<"-------------------------------pop--------------------------------"<<endl;

    cout<<stack1.pop()<<endl;
    cout<<stack1.pop()<<endl;
    cout<<stack1.pop()<<endl;
    cout<<stack1.pop()<<endl;
    cout<<stack1.pop()<<endl;

cout<<"-------------------------------Display All Elements--------------------------------"<<endl;
    stack1.displayAllElements();
cout<<"-------------------------------copy constructor--------------------------------"<<endl;
    StackLinkedList<int> stack2(stack1);

    stack2.displayAllElements();



    return 0;
}