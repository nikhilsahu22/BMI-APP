#include <iostream>
#include <string>
#include<stdlib.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

class LLAdt{
private:
    Node *first ;
    Node *second ; //other two pointer for concat
    Node *third ;

public:
   LLAdt(){
     first = NULL;
    }
    
    int length(Node *p);    
    void insertfirst(int x);
    void insertAtPosition(int value, int pos);
    void deletefirst();
    int deleteAtPosition(int index);
    Node* search(int key);
    void create(int A[], int n);
    void create2(int B[], int n);
    void Concat();
	void Display() ; 
};

int LLAdt :: length(Node *p){
	int c=0;
	p=first;
	while(p){
	    c++;
	    p=p->next;
	}
	return c ;
}

void LLAdt :: insertfirst(int x){
    Node *t;
    t = new Node;
    t->data = x;
    t->next = first;
    first = t;
}

void LLAdt :: insertAtPosition(int value, int pos) {
    if (pos < 0 || pos > length(first)){
    	cout<<"Index is not in range \n"<<endl ;
    	
    	return;
	}
    	
    struct Node *p, *t;
    p = first;
    t = new Node;
    if (pos == 0){
        t->data = value;
        t->next = first;
        first = t;
    }
    else if (pos > 0){
        for (int i = 0; i < pos - 1 && p; i++) {
            p = p->next;
        }
        t->data = value;
        t->next = p->next;
        p->next = t;
    }
}

void LLAdt :: deletefirst(){
    Node *p = first;
    first = first->next;
    int x = p->data;
    delete p;
}

int LLAdt :: deleteAtPosition(int index){
    struct Node *p=first , *q=NULL;
    int x=-1;
    
    if(index<0 || index>length(p)){
    	cout<<" Index given higher than element present \n";
    	return -1;
    } 
    
    if(index==1){
        x=first->data;
        first=first->next;
    }
    
	else{
        for(int i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        x=p->data;
        q->next=p->next;
    }

    delete p;
    return x;
}

Node* LLAdt :: search(int key){
 	Node *p=first;
    while(p){
        if(key==p->data){
            cout<<"Pointer of the Node is "<<endl ;
            return p;
        }p=p->next ;
    }
    return NULL;
}

void LLAdt :: create(int A[], int n){
    Node *last, *t;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++){
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void LLAdt ::  create2(int B[], int n){
    Node *last, *t;
    second = new Node;
    second->data = B[0];
    second->next = NULL;
    last = second;

    for (int i = 1; i < n; i++){
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void LLAdt :: Display(){
	int i=0 ;
        Node *p=first;

		while(p){
            cout<<p->data;
            p=p->next;
        
        if (i < length(p) - 1){  
            	cout << "--> ";
                i++ ;
        }
     }cout<<endl;
}
	
void LLAdt :: Concat(){   
    Node *p=first ,*q=second ;
    third = p;
    while (p->next){
        p = p->next;
    }
    p->next = q;
    cout<<"Concatenated Elements are "<<endl;
}

int main(){	
    LLAdt LinkedList;

	int A[] = {1, 4, 5, 6, 9};
    LinkedList.create(A, 5);

    int B[] = {2, 3, 7, 8};
    LinkedList.create2(B, 4);
    
    
class Node {
    public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyLL{
    private:
        Node *first=NULL;
    public:
        DoublyLL(int A[],int n);
        void Display();
        int Length();
        void InsertHead(int x);
        void InsertEnd(int x);
        int RemoveHead();
        int RemoveEnd();
        ~DoublyLL();
};

DoublyLL :: ~DoublyLL(){
    Node *p=first ,*q ;
    while(p){
        q=p;
        p=p->next;
        cout<<"\n"<<"Removed :"<<q->data;
        delete q;
    }
}

DoublyLL::DoublyLL(int A[],int n){
    Node *last,*t;
    first=new Node;
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;
    
    for(int i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=NULL;        
        t->prev=last;
        last->next=t;
        last=t;
    }
}

void DoublyLL::InsertHead(int x){ //before first node 
    Node *t,*p=first;
    t=new Node;
    t->data=x;  
    
    t->next=first;
    p->prev = t ;
    first=t;
}

void DoublyLL::InsertEnd(int x) {
	Node *p = first ;
    Node *t = new Node;
    t->data = x;
    t->next = NULL ;

    if(first == NULL) { // If the list is empty
        t->prev = NULL ;
        first = t;
        
    } 
	else{
        while(p->next!= NULL ){
        	p=p->next;
		}            
        p->next=t;
        t->prev=p;
    }
}

int DoublyLL::RemoveHead(){
    Node *p=first;
    int x;

    first=first->next;
    x=p->data;
    delete p;
				        
    return x;
   
}

int DoublyLL::RemoveEnd() {
    Node *p = first;
    int x;

    if (first == NULL) {
        cout << "List is empty, cannot remove from the end." << endl;
        return -1; 
    }

    while (p->next != NULL) {
        p = p->next;
    }

    x = p->data;
    
    if (p->prev != NULL) {
        p->prev->next = NULL;
    } 
	else {
        // If p->prev is NULL, it means the list had only one element
        first = NULL;
    }

    delete p;

    return x;
}

int DoublyLL::Length(){
    Node *p=first;
    int x=0;
    while(p){
        x++  ; // or  ++x;
        p=p->next;
    }
    return x;
}

void DoublyLL::Display() {
        int i=0 ;
        Node *p=first;

		while(p){
            cout<<p->data;
            p=p->next;
        
        if (i < Length() - 1){  //just added if cond upto which print fun upto length() -1
            	cout << "<--> ";
                i++ ;
        }
     }cout<<endl;
}

class CircularLinkedList{
    private:
        Node *Head;
    public:
        CircularLinkedList(int A[],int n);
        void display();
        int length();
        Node* search(int key);
        void insert(int index,int value);
        int Delete(int index);
};

CircularLinkedList::CircularLinkedList(int A[],int n){
    Node *last,*t ;
    
    Head=new Node;  
    Head->data=A[0] ;
    Head->next=Head ;   // Point to itself since it's a circular list
    last=Head ;
    for(int i=1;i<n;i++){
        t=new Node ;
        t->data=A[i] ;
        t->next=last->next ;   // Point to itself since it's a circular list
        last->next=t ;
        last=t ;
    }
}

int CircularLinkedList::length(){
    Node *p=Head;
    int l=0;
    do
    {
        l++;
        p=p->next;
    }while(p!=Head);
    return l;

}

void CircularLinkedList::insert(int index,int value){
    if(index<0 || index>length())  //length is a fun()
        return ;

    Node *p=Head,*t;
    t=new Node;
    t->data=value;
    if(index==0){
        if(Head==NULL){
            t->next=t;
            Head=t;
        }
        else{
            while(p->next!=Head)
                p=p->next;
            t->next=p->next;
            p->next=t;

        }
    }
    else{
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
            p->next=t;
    }
}

int CircularLinkedList::Delete(int index){
    if(index<0 || index>length())
        return -1;

    Node *p=Head,*q;
    int x,i;
    if(index==1){
        while(p->next!=Head)
            p=p->next;
        if(p==Head){
            x=p->data;
            delete p;
            Head=NULL;
            return x;
        }
        x=Head->data;
        p->next=Head->next;
        delete Head;
        Head=p->next;
        return x;
    }
    else{
        for(i=0;i<index-1;i++)
            p=p->next;
        q=p->next;
        x=q->data;
        p->next=q->next;
        delete q;
        return x;
    }
}

Node* CircularLinkedList :: search(int key){
 	Node *p= Head;
 	
    do{
        if(key==p->data){
            cout<<"Pointer of the Node is  " ;
            return p;
        }p=p->next ;
    }while(p!=Head);
    
    return NULL;
}

void CircularLinkedList::display(){
    Node *p=Head;
    do{
        cout<<p->data<<"->";
        p=p->next;

    }while(p!=Head);
    cout<<endl;
}

int main() {
    int A[] = {1, 3, 5, 8, 9};

    CircularLinkedList l(A, 5);
    int choice;    

#include<iostream>
using namespace std;

struct Stack{
    int size ;
    int top ;
    int *S ;
} ;

void create(Stack *st){ //already keyword as stack-->cause ambiguity
    cout<<"Enter size of stack \n";
    cin>>st->size ;
    st->top = -1 ;
    st->S = new int[st->size] ; //This is for storing size of Stack 
}

void display(Stack st){
        for(int i=st.top ; i>=0 ; i-- ){
            cout<<st.S[i]<<" " ;
        }cout<<endl ;
}

void push(Stack *st , int x){
    if(st->top==st->size -1){
        cout<<"Stack is full ";
    }
    else{
        st->top ++ ;
        st->S[st->top]=x ;
    }
}

int pop(Stack *st){
    int x =-1 ;
    if(st->top== -1){
        cout<<"Stack is empty ";
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(Stack st , int pos){
    int x = -1 ;
    if(st.top -pos + 1 < 0 ){
        cout<<"Invalid index ";
    }
    else{
        x = st.S[st.top-pos +1];
    }
    return x ;
}

int stackTop(Stack st ){
    if(st.top== -1){
        return -1;
    }
    else{
        return st.S[st.top];
    }
}

bool isEmpty(Stack st){
    if(st.top==-1){
        return 1 ;
    }
    return 0 ;
}

bool isFull(Stack st){
    if(st.top= st.size - 1){
        return 1 ;
    }
    return 0 ;
}

int main(){
    struct Stack st ;
    create(&st);

    push(&st , 10);
    cout<<"Inserted 1st element  ";
    display(st);

    push(&st , 40);
    cout<<"Inserted 2nd element ";
    display(st);

    push(&st , 80);
    cout<<"Inserted 3rd element ";
    display(st);

    pop(&st);
    cout<<"Deleted last inserted element \n ";
    display(st);

  
    cout<<"POS at 2 --> "<< peek(st , 2)<<endl<<endl;
    cout<<stackTop(st)<<" "<<isEmpty(st)<<" "<<isFull(st) ;

    return 0;
}

#include<iostream>
using namespace std ;

struct Node{
    int data ;
    Node * next;    
}*top = NULL;

void push(int x ){
    Node *t ;
    t =new Node ;

    if(t ==NULL){ //if it is unable to create linked list i.e point to NUll then stackFull
        cout<<"Stack is Full ";
    }
    else{
        t->data = x ;
        t->next = top ;
        top = t ;
    }
}

int pop(){
    Node *t  ;
    int x =-1 ;
    if(top ==NULL){ 
        cout<<"Stack is Empty ";
    }
    else{
        t = top ;
        x = t->data ;
        top = top->next ;
        delete t ;
    }
    return x ;
}

void display(){
    Node *p = top ;
    while(p!=NULL){
        cout<<p->data<<" " ;
        p= p->next ;
    }cout<<endl ;
}

int peek(int pos){
    Node *p = top;
    for(int i=0 ; i<pos-1 && p!=NULL ; i++){
        p=p->next ;
    }
    if(p){
        return p->data ;
    }
    else{
        return -1 ;
    }
}

int stackTop(){
    if(top){
        return top->data ;
    }
    return -1;
}

bool isEmpty(){
    return top ? 0 : 1 ;
}

bool isFull(){
    Node *t = new Node ;
    int r = t ? 0 : 1 ;
    delete t ;

    return r ;
}

int main(){
    push(5);
    push(3);
    push(9);
    display() ;

    cout<<"Peek at 2--> "<<peek(2)<<endl;
    cout<<"POP is "<< pop()<<endl;
    display() ;
    cout<<"stacktop "<< stackTop()<<endl; 
    cout<<"isEmpty "<<isEmpty()<<endl;
    cout<<"isfull "<< isFull();

    return  0;
}

#include<iostream>
using namespace std ;

struct Node{
    int data ;
    Node * next ;
}*front=NULL , *rear=NULL;

void enqueue(int x){
    Node *t= new Node ;
    if(t==NULL){
        cout<<"Queue is full ";
    }
    else{
        t->data=x ;
        t->next=NULL;
        if(front==NULL){
            front=rear =t;
        }
        else{
            rear->next = t;
            rear = t ;
        }
    }
}
int dequeue(){
    int x = -1 ;
    Node *p ;
    if(front==NULL){
        cout<<"Queue is empty ";
        return x ;
    }
    else{
        p = front ;
        front= front->next ;
        x =p->data ;
        delete p ;
     
    } return x;
}
void Display(){
    Node *p = front ;
    while(p!=NULL){
        cout<<p->data<<" " ;
        p=p->next ;
    }
}

#include<iostream>
using namespace std ;

struct Queues{
    int front ;
    int rear ;
    int size ;
    int *Q ;
};

void create(Queues *q ,int s ){
        q->front = q->rear = -1;
        q->size = s ;
        q->Q = new int [q->size ] ;
}

void enqueue(Queues *q , int x){
    if(q->rear == q->size -1){
        cout<<"Queue is Full ";
    }
    q->rear++;
    q->Q[q->rear]= x ;
}

int dequeue(Queues *q){
    int x=-1 ;
    if(q->front ==q->rear){
        cout<<"Queue is empty ";
        return x ;
    }
    q->front++ ;
    x = q->Q[q->front] ;
    
    return x ;
}

void Display(Queues q){
    for(int i=q.front+1 ; i<=q.rear ; i++ ){
        cout<<q.Q[i]<<" " ;
    }
}    
    
    
    
    
    
    
    
    
    
    
    
    
    









    
    
