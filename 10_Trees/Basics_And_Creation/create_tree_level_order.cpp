/*
Problem: Construct a Binary Tree Using Level-Order Input
Difficulty: Easy
Topic: Binary Tree
Pattern: Queue-Based Tree Construction

Approach:
- Take input for the root node .
- Then for every node , ask for left and right node value .
- If value is -1 , assume it as end otherwise push and consider the value .

Time Complexity: O(n)
Space Complexity: O(w) where w is the width of binary Tree . In worst case , it can w == n .

Mistake I made:
- Initially I got the idea that I need to store the nodes reference but I was unable to get the data structure ie queues .
- I missed the edge case where the root node can be -1 initially .
*/


#include<iostream>
#include<queue>
using namespace std;

class Node{
    public :
    int data ;
    Node *left , *right ;

    Node(int val){
        data = val ; 
        left = right = NULL ;
    }
};


int main(){

    queue<Node*> q ;
    int x ;
    cout<<"Enter root value : ";
    cin>>x ;
    
    if(x == -1){
        return  0; 
    }

    Node *root = new Node(x) ;
    q.push(root) ;

    while( !q.empty() ){
        int l , r ;
        cout<<"Enter the value of left child of "<<q.front()-> data<<" : ";
        cin >> l ;
        cout<<"Enter the value of right child of "<<q.front()-> data<<" : ";
        cin >> r ;
        
        if(l!=-1) {
            q.front() -> left = new Node(l) ;
            q.push(q.front()-> left) ;
        }
        if(r!=-1) {
            q.front() -> right = new Node(r) ;
            q.push(q.front()-> right) ;
        }

        q.pop() ;
    }

    return 0 ;
}