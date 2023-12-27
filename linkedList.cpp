#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node<T> *pNext;
    Node<T> *pPerv;
    Node<T>()
    {
        data = T();
        pNext = nullptr;
        pPerv = nullptr;
    }
    Node<T>(T _data)
    {
        data = _data;
        pNext = nullptr;
        pPerv = nullptr;
    }
    ~Node<T>()
    {
    }
};
template <class T>
class LinkedList
{
    Node<T> *tail;
    Node<T> *head;
    int count;

public:
    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    LinkedList(LinkedList &list)
    {
        tail = nullptr;
        head = nullptr;
        count = 0;
        Node<T> *copyNode = list.head;
        while (copyNode != nullptr)
        {
            add(copyNode->data);
            copyNode = copyNode->pNext;
        }
    }
    void add(T data)
    {
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            tail->pNext = newNode;
            newNode->pPerv = tail;
        }
        tail = newNode;
        count++;
    }
    void display()
    {
        Node<T> *current = head;
        while (current != nullptr)
        {
            cout << current->data << "  ";
            current = current->pNext;
        }
        cout << endl;
    }
    ~LinkedList()
    {
        claerList();
    }
    void claerList(){
                Node<T> *deleteNode = head;
        while (deleteNode != nullptr)
        {
            head = head->pNext;
            delete deleteNode;
            deleteNode = head;
        }

    }
    Node<T>* search(T data)
    {
        Node<T> *searchNode = head;
        while (searchNode != nullptr && searchNode->data != data)
        {
            searchNode = searchNode->pNext;
        }
        return searchNode;
    }
    void isExist(T data)
    {
        Node<T> *node = search(data);
        if (node != 0)
        {
            cout << "this element is exist" << endl;
        }
        else
        {
            cout << "this element is not exist" << endl;
        }
    }
    void deleteElement(T data)
    {
        Node<T> *deleteNode = search(data);
        if (deleteNode == nullptr)
        {
            cout << "Not found"<<endl;
        }
        else
        {
            if (deleteNode == head)
            {
                if (deleteNode == tail)
                {
                    delete deleteNode;
                    head = nullptr;
                    tail = nullptr;
                }
                else
                {
                    head = head->pNext;
                    head->pPerv = nullptr;
                    delete deleteNode;
                }
            }
            else
            {
                if (deleteNode == tail)
                {
                    tail = tail->pPerv;
                    tail->pNext = nullptr;
                    delete deleteNode;
                }
                else
                {
                    deleteNode->pPerv->pNext = deleteNode->pNext;
                    deleteNode->pNext->pPerv = deleteNode->pPerv;
                    delete deleteNode;
                }
            }
            count--;
        }
    }
    void insertAfter(T AfterData, T newData)
    {
        Node<T> *node = search(AfterData);
        if (node == nullptr)
        {
            cout << "Not found "<<endl;
        }
        else
        {
            if (node == tail)
            {
                add(newData);
            }
            else
            {
                Node<T>* newNode =new Node(newData);
                newNode->pNext = node->pNext;
                newNode->pPerv = node;
                node->pNext->pPerv=newNode;
                node->pNext=newNode;
            }
            count++;
        }
    }
    void addByIndex(T data, int index){
        if(index<0 || index>count-1){
            cout<<"Out of range"<<endl;
        }
        else if(index==count-1){
            add(data);
        }

        else{
            Node<T>* newNode= new Node(data);
            if(index==0){
                head->pPerv=newNode;
                newNode->pNext=head;
                head=newNode;
            }
            else{
            Node<T>* current=head;    
            for(int i=0;i<index-1;i++){
                
                current=current->pNext;

            }
            newNode->pPerv=current;
            newNode->pNext=current->pNext;
            current->pNext->pPerv=newNode;
            current->pNext=newNode;
            }
            count++;
        }

    }
void reverseList(){
    Node<T>* current=head;
    Node<T>* temp=nullptr;
    while (current!=nullptr)
    {
        temp=current->pPerv;
        current->pPerv=current->pNext;
        current->pNext=temp;
        current=current->pPerv;
    }
    if(temp!=nullptr){
        head=temp->pPerv;
    }
}
};
int main()
{
    LinkedList<int> lsit1;
    /*--------------------------Insert---------------------*/
    lsit1.add(5);
    lsit1.add(7);
    lsit1.add(9);
    lsit1.add(11);
    lsit1.add(2);
    lsit1.add(8);
    /*--------------------------Display---------------------*/
    cout << "--------------------------Display---------------------" << endl;
    lsit1.display();
    cout << "--------------------------search---------------------" << endl;
    lsit1.isExist(11);
    lsit1.isExist(20);
    /* "--------------------------Delete---------------------" */
    lsit1.deleteElement(11);
    lsit1.deleteElement(5);

    cout << "--------------------------Display After Delete---------------------" << endl;
    lsit1.display();
     /*--------------------------Insert After---------------------*/
     lsit1.insertAfter(20,1);
     lsit1.insertAfter(9,1);
     cout << "--------------------------Display After Insert After---------------------" << endl;
    lsit1.display();
    /*--------------------------Insert By Index---------------------*/
    lsit1.addByIndex(55,4);
    lsit1.addByIndex(77,7);
    lsit1.addByIndex(100,0);
    lsit1.addByIndex(77,2);


     cout << "--------------------------Display After Insert By Index---------------------" << endl;

    lsit1.display();
    /*--------------------------Insert By Index---------------------*/
    lsit1.reverseList();
     cout << "--------------------------Display After Reverse---------------------" << endl;
     lsit1.display();
    

    return 0;
}