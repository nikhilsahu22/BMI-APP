#include<iostream>
using namespace std ;

struct array{
    int A[10] ;
    int size ;
    int length ;

void display(){
    for(int i=0 ; i<size ; i++){
        cout<<A[i] ;
    }
}

int linearsearch(int key){

    for(int i=0 ; i<size ; i++ ){
        if(key==A[i]){
            
            return i ;
            }
        }
    return -1 ;
} 

void swap(int &x , int  &y){
    int temp ;
    temp = x ;
    x = y ;
    y = temp ;
}

int linTransearch(int key){

    for(int i=0 ; i<size ; i++ ){
        if(key==A[i]){
            
            swap(A[i] , A[i-1]) ;
            return i ;
            }
        }
    return -1 ;
} 

int linAdvsearch(int key){

    for(int i=0 ; i<size ; i++ ){
        if(key==A[i]){
            
            swap(A[i] , A[0]) ;
            return i ;
            }
        }
    return -1 ;
} 
   
};
   


int main(){
    struct array arr={{1,2,3,4,5,6,7},10,7};

    cout<<arr.linearsearch(9)<<endl ;
    cout<<arr.linearsearch(9)<<endl ;

    cout<<arr.linTransearch(4);
    cout<<arr.linTransearch(4);
    cout<<arr.linTransearch(4)<<endl;

    cout<<arr.linAdvsearch(6);
    cout<<arr.linAdvsearch(6);
    cout<<arr.linAdvsearch(6);


    return 0; 
}

#include<iostream>
using namespace std ;

struct array{
    int A[10] ;
    int size ;
    int length ;

int binarysearch( int key){
    int l= 0 ;
    int h= length -1;
    
    while(l<=h){
        int mid = (l + h)/2 ;

        if(key==A[mid]){
            return mid ;
        }

        else if(A[mid]<=key){
            l = mid + 1 ;     
        }

        else if(A[mid]>key){
            h = mid -1 ; 
        } 
      }
      return -1 ;
}

int Rbinarysearch(int l , int h, int key){
     
    if(l<=h){    
        int mid = (l + h)/2 ;

        if(key==A[mid]){
            return mid ;
        }

        else if(A[mid]<=key){
            return Rbinarysearch(mid+1 ,h, key);           
        }

        else if(A[mid]>key){
            return Rbinarysearch( l , mid -1 , key ) ;    
            }

             //inside l<=h condition
        }
        return -1 ; 
}

};    

int main(){
   array arr={{1,2,3,4,5,6,7},10,7};
   cout<<arr.binarysearch(6) ;
   cout<<arr.binarysearch(7)<<endl ;

   cout<<arr.Rbinarysearch(0 ,arr.length-1, 7) ;
 
    return 0; 
}
