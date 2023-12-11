#include <iostream>

using namespace std;
 
class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
};
 
class BST{
private:
    Node* root;
public:
    BST(){ root = NULL; }
    Node* getRoot(){ return root; }
    void Preorder(Node* p);
    void Inorder(Node* p);
    void Postorder(Node* p);
    void Insert(int key);
    int Height(Node *t);
    Node*Delete(Node *p,int key); //using recurr so	
	Node*Inprec(Node *p);
	Node*Insucc(Node *p);
    Node* Search(int key);
};
 
void BST::Insert(int key) {
 
    Node* t = root;
    Node* p;
    Node* r;
 
    // root is empty
    if (root == NULL){
        p = new Node;
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
    }
 
    while(t != NULL){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }
 
    // Now t points at NULL and r points at insert location
    p = new Node;
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;
 
    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }
 
}

Node * BST::Delete(Node *p,int key){
    Node *t=NULL;
    if (p==NULL)
       return NULL;
       
   if(p->lchild==NULL && p->rchild==NULL){
       if (p == root){
            root = NULL;
       }
        delete p;
       return NULL;
    }
    
    if(p->data>key)
        p->lchild=Delete(p->lchild,key);
        
    else if(p->data<key)
       p->rchild=Delete(p->rchild,key);
       
    else{
        if( Height(p->lchild) > Height(p->rchild) ){
            t=Inprec(p->lchild);
            p->data=t->data;
            p->lchild=Delete(p->lchild,t->data);
        }
        else{
            t=Insucc(p->rchild);
            p->data=t->data;
            p->rchild=Delete(p->rchild,t->data);
       }
    }
    return p;
}

int BST:: Height(struct Node *t){
    if(t==NULL)
        return 0;
    int lh=Height(t->lchild);
    int rh=Height(t->rchild);
    return lh<rh?rh+1:lh+1;
}

Node * BST:: Inprec(Node *p){
    while(p && p->rchild!=NULL)
       p=p->rchild;
    return p;
}

Node * BST::Insucc(Node *p){	
	while(p && p->lchild!=NULL){
		p=p->lchild;		
	}
	 return p;        
}
 
void BST::Postorder(Node* p){
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " ;        
    }
}

Node* BST::Search(int key){
    Node* t = root;
    while (t != NULL){
        if (key == t->data){
            return t;
            
        } 
		else if (key < t->data){
            t = t->lchild;
        } 
		else {
            t = t->rchild;
        }
    }
    return NULL;
}
 
int main() {
    BST bst;
    int choice;

                cout << "Postorder Traversal: ";
                bst.Postorder(bst.getRoot());
                cout << endl;
                break;	    
            case 6: {
                int key;
                cout << "Enter key to search: ";
                cin >> key;
                Node* temp = bst.Search(key);
                if (temp != NULL) {
                    cout << "Found " << temp->data << endl;
                } else {
                    cout << "Element not found" << endl;
                }
                break;
            }
            case 7:
                cout << "Exiting program\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 7);

    return 0;
}

#include <iostream>

using namespace std;
 
class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};
 
class AVL{
public:
    Node* root;
 
    AVL(){ root = NULL; }
 
    // Helper methods for inserting
    int NodeHeight(Node* p);
    int BalanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);
 
    // Insert & search
    Node* rInsert(Node* p, int key);
    Node* Search(int key);
     
	 // Traversal
    void Inorder(Node *p);
    void Inorder(){ Inorder(root); }

};
 
int AVL::NodeHeight(Node *p) {
    int hl;
    int hr;
 
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
 
    return hl > hr ? hl + 1 : hr + 1;
}
 
int AVL::BalanceFactor(Node *p) {
    int hl;
    int hr;
 
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
 
    return hl - hr;
}
 
Node* AVL::LLRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
 
    pl->rchild = p;
    p->lchild = plr;
 
    // Update height
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
 
    // Update root
    if (root == p){
        root = pl;
    }
    return pl;
}
 
Node* AVL::RRRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
 
    pr->lchild = p;
    p->rchild = prl;
 
    // Update height
    p->height = NodeHeight(p);
    pr->height = NodeHeight(pr);
 
    // Update root
    if (root == p){
        root = pr;
    }
    return pr;
}
 
Node* AVL::LRRotation(Node *p) {
    Node* pl = p->lchild;
    Node* plr = pl->rchild;
 
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
 
    plr->lchild = pl;
    plr->rchild = p;
 
    // Update height
    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);
 
    // Update root
    if (p == root){
        root = plr;
    }
    return plr;
}
 
Node* AVL::RLRotation(Node *p) {
    Node* pr = p->rchild;
    Node* prl = pr->lchild;
 
    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;
 
    prl->rchild = pr;
    prl->lchild = p;
 
    // Update height
    pr->height = NodeHeight(pr);
    p->height = NodeHeight(p);
    prl->height = NodeHeight(prl);
 
    // Update root
    if (root == p){
        root = prl;
    }
    return prl;
}
 
Node* AVL::rInsert(Node *p, int key) {
    Node* t;
    if (p == NULL){
        t = new Node;
        t->data = key;
        t->lchild = NULL;
        t->rchild = NULL;
        t->height = 1;  // Starting height from 1 onwards instead of 0
        return t;
    }
 
    if (key < p->data){
        p->lchild = rInsert(p->lchild, key);
    } 
	else if (key > p->data){
        p->rchild = rInsert(p->rchild, key);
    }
 
    // Update height
    p->height = NodeHeight(p);
 
    // Balance Factor and Rotation
    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1) {
        return LLRotation(p);
    } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
        return LRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
        return RRRotation(p);
    } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
        return RLRotation(p);
    }
 
    return p;
}

void AVL::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

Node* AVL::Search(int key){
    Node* t = root;
    while (t != NULL){
        if (key == t->data){
            return t;           
        } 
		else if(key < t->data){
            t = t->lchild;
        } 
		else{
            t = t->rchild;
        }
    }
    return NULL;
}

#include<iostream>
#include<cstring>

using namespace std ;

struct Node{
    char data ;
    Node * next;    
}*top = NULL;

void push(char x ){
    Node *t ;
    t =new Node ;

    if(t ==NULL){ 
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

int stackTop(){
    if(top){
        return top->data ;
    }
    return -1;
}

bool isEmpty(){
    return top ? 0 : 1 ;
}

int isOperand(char s)
{
    if(s=='*' || s=='/' || s=='+' || s=='-')
        return 0;
    else 
        return 1;
}

int pre(char s)
{
    if(s=='*' || s=='/')
        return 2;
    else if(s=='+' || s=='-')
        return 1;
    return 0;
}

char* InfixToPost(char *s)
{
    char *postfix;
    int i=0,j=0;
    postfix=new char[strlen(s+1)];

    while(s[i]!='\0')
    {
        if(isOperand(s[i])) 
           postfix[j++]=s[i++];
        else
        {
            if(pre(s[i])>pre(stackTop()))
                push(s[i++]);
            else
            {
                postfix[j++]=pop();
            }
        }
    }
    while(!isEmpty())
    {
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    return postfix;
}

int evalP(char * postfix){
    int r=0; ;

    for(int i=0 ; postfix[i]!='\0' ; i++){
        if(isOperand(postfix[i])){
            push(postfix[i]- '0');
        }
        
        else{
            int x2=pop() ;
            int x1=pop() ;

            switch(postfix[i]){
                case '+' : r = x1 + x2 ;
                            break ;

                case '-' : r = x1 - x2 ;
                            break ;

                case '*' : r = x1 * x2 ;
                            break ;

                case '/' : r = x1 / x2 ;
                            break ;
                default :
                        break;            
            }  push(r) ;        
        }
    } return pop() ;
}



int main(){
    char postfix[]="2362/*+";
    int answer=evalP(postfix);
    cout<<answer;
    

    return 0;
    

}

#include<iostream>
#include<stdlib.h>
#include <cstring>
using namespace std;
struct Stack{
    int size;
    int top;
    char *S;
};


void create(Stack *st,char *s)
{
    int x=strlen(s);
    st->size=x;
    st->top=-1;
    st->S=new char[st->size];
}

void push(Stack *st,char x)
{
    if(st->size-st->top==1)
    {
        cout<<"stack is overflow\n";
    }
    else{
        st->top++;
        st->S[st->top]=x;
    }
}

char TopValue(Stack st)
{
    if(st.top==-1)
        return -1;
    else
        return st.S[st.top];
}

char pop(Stack *st)
{
    char x=-1;
    if(st->top==-1)
    {
        cout<<"Stack is underflow\n";
    }
    else{
        x=st->S[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(Stack st)
{
    if(st.top==-1)
        return 1;
    else
        return 0;
}

int isFull(Stack st)
{
    if(st.size-st.top==1)
        return 1;
    else
        return 0;
}

int isOperand(char s)
{
    if(s=='*' || s=='/' || s=='+' || s=='-')
        return 0;
    else 
        return 1;
}

int pre(char s)
{
    if(s=='*' || s=='/')
        return 2;
    else if(s=='+' || s=='-')
        return 1;
    return 0;
}

char* ToPost(char *s)
{
    char *postfix;
    int i=0,j=0;
    postfix=new char[strlen(s+2)];
    Stack st;
    create(&st,s);
    push(&st,'#');//because of comaprison of top vale with string 1st value # is pushed
                    //so there wont be any error
    while(s[i]!='\0')
    {
        if(isOperand(s[i]))
           postfix[j++]=s[i++];
        else
        {
            if(pre(s[i])>pre(TopValue(st)))//because of this comparison stack cant be expty so # is pushed
                push(&st,s[i++]);
            else
            {
                   postfix[j++]=pop(&st);
            }
        }
    }
    while(!isEmpty(st))
    {
        postfix[j++]=pop(&st);
    }
    postfix[j]='\0';
    return postfix;
}

int main()
{
    char s[]="a+b*c/d+e";
    char *postfix=ToPost(s);
    cout<<postfix;
    return 0;
}
 
