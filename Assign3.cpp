#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node *previous;
    
    Node(int data){
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }
};

class headTail{
public:
    Node*head;
    Node*tail;
    
    headTail(Node *head,Node *tail)
    {
        this->head = head;
        this->tail = tail;
    }
};

headTail* addElements()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1)
    {
        Node *newNode = new Node(data);
        
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            Node * temp = tail;
            tail = newNode;
            temp->next = tail;
            newNode->previous = temp;
        }
        cin >> data;
        
    }
    headTail *newHeadTail = new headTail(head,tail);
    if(head == NULL) // If the linked List is empty
    {
        return newHeadTail;
    }
    
    head->previous = tail;
    tail->next = head;
    
    
    
    return newHeadTail;
}

void display(Node *head)
{
    cout << "P D N "<< endl;
    Node *temp = head;
    cout << temp->previous->data <<" " << temp->data <<" "<<temp->next->data << endl;
    temp=temp->next;
    while(temp != head)
    {
        if(temp->previous){
            cout << temp -> previous->data <<" ";
        }else{
            cout << "NULL ";
        }
        
        if(temp->data){
            cout << temp ->data << " ";
        }else{
            cout << "NULL ";
        }
        
        if(temp->next){
            cout << temp -> next->data <<" ";
        }else{
            cout << "NULL ";
        }
        temp = temp->next;
        
        cout << endl;
    }
}

headTail * addAtBeg(Node * head,Node *tail)
{
    int data;
    cin >> data;
    
    Node *newNode = new Node(data);
    newNode -> next = head;
    newNode->previous = tail;
    tail->next = newNode;
    head = newNode;
    
    headTail *newHeadTail = new headTail(head,tail);
    return newHeadTail;
}

headTail * addAnyWhere(Node *head,Node *tail,int key)
{
    int data;
    cin >> data;
    
    Node *temp = head;
    if(temp->data == key)//adding to the head
    {
        Node *newNode = new Node(data);
        newNode -> next = head;
        newNode->previous = tail;
        tail->next = newNode;
        head = newNode;
        
        headTail *newHeadTail = new headTail(head,tail);
        return newHeadTail;
    }else if( tail->data == key) // adding after tail
    {
        Node *newNode = new Node(data);
        newNode -> next = head;
        newNode->previous = tail;
        tail->next = newNode;
        tail = newNode;
        
        headTail *newHeadTail = new headTail(head,tail);
        return newHeadTail;
    }
    
    temp = temp->next;
    while(temp != head) // adding anywhere between by checking the for the key and then inserting to the right of the key
    {
        if(temp->data == key)
        {
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            newNode->previous = temp;
            temp->next->previous = newNode;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
        
    }
    headTail *newHeadTail = new headTail(head,tail);
    return newHeadTail;
}

headTail * deleteNode (Node* head,Node *tail,int key)
{
    Node * temp =head;
    if(temp->data == key) // Node appeared as head node
    {
        head->next->previous = head->previous;
        head = head->next;
        tail->next = head;
        
        headTail *newHeadTail = new headTail(head,tail);
        return newHeadTail;
        
    }
    else if(tail->data == key) // Node appeared as tail node
    {
        tail = tail->previous;
        tail->next = head;
        head->previous = tail;
        
        headTail *newHeadTail = new headTail(head,tail);
        return newHeadTail;
    }
    else{
        temp = temp->next;
        while(temp != head)
        {
            if(temp -> data == key)
            {
                temp->previous->next = temp->next;
                temp->next->previous = temp->previous;
                break;
            }
            temp = temp->next;
        }
        
        headTail *newHeadTail = new headTail(head,tail);
        return newHeadTail;
    }
}

void search(Node*head,Node *tail,int key)
{
    Node * temp = head;
    if(temp->data == key)
    {
        cout << "Add\t P D N" << endl;
        cout << temp <<" " << temp->previous->data << " "<<temp->data
        << " "<< temp->next->data << endl;
        return;
    }
    temp = temp->next;
    while(temp != head)
    {
        if(temp->data == key)
        {
            cout << "Add\tP D N" << endl;
            cout << temp <<" " << temp->previous->data << " "<<temp->data
            << " "<< temp->next->data << endl;
            return;
        }
        temp = temp->next;
    }
    
    cout << "Element not found in the given Doubly-circular-LinkedList" << endl;
    return;
    
}

int size(Node *head)
{
    Node* temp = head;
    int count=0;
    if(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    while(temp != head)
    {
        temp = temp->next;
        count++;
        
    }
    return count;
}

bool isPalindromic(Node *head,Node *tail)
{
    Node * headTemp = head, *tailTemp = tail;
    while(headTemp != tailTemp)
    {
        if(headTemp-> data != tailTemp->data)
        {
            return false;
        }
        headTemp = headTemp->next;
        tailTemp = tailTemp->previous;
    }
    
    return true;
}

bool isCircularLinkedList(Node *head,Node *tail)
{
    return head == tail->next;
}

int main()
{
    headTail * newHeadTail = addElements();
//    display((addAtBeg(newHeadTail->head, newHeadTail->tail))->head);
//    int key;
//    cin >> key;
//    newHeadTail = addAnyWhere(newHeadTail->head,newHeadTail->tail,key);
    
//    newHeadTail = deleteNode(newHeadTail->head, newHeadTail->tail, key);
//    search(newHeadTail->head,newHeadTail->tail,key);
//  display(newHeadTail->head);
//    cout << size(newHeadTail->head);
    
//    cout << isPalindromic(newHeadTail->head, newHeadTail->tail);
    
    cout << isCircularLinkedList(newHeadTail->head ,newHeadTail->tail);
    

    
    return 0;
    
    
    
    

    
    
}
