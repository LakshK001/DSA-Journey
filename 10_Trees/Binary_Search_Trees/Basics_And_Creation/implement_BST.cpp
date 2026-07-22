/*
Problem: Implement Binary Search Trees
Platform: Lecture Basics
Difficulty: Easy
Topic: Binary Search Tree
Pattern: Recursive BST insertion

Approach:
- We have moved to right and left of current node according to conditions using recursion .
- The point when we are at bottom ie nullptr is the position where node has to be inserted , so new node with value is created and returned .
- The returned node is stored in curr -> left or curr -> right automatically which connects the formed node in the tree .
- The return of curr at the last helps to get the root of the BST each time .
- The inorder traversal of BST is also done , which stores values in non decreasing order .


Time Complexity: O(n*n) In worst case ie ascending or descending order , each insertion of a node become O(n) task
Auxilliary Space Complexity: O(h) where h is the height of BST . In worst case h = n .
*/

#include<iostream>
#include<vector>
using namespace std ;

class Node{
    public :
    int data ;
    Node *left ;
    Node *right ;

    Node(int val){
        data = val ;
        left = right = nullptr ;
    }
};

Node* insert(vector<int> &arr , int idx , Node* curr){

    if(curr == nullptr){
        Node* temp = new Node(arr[idx]) ;
        return temp ;
    }

    if(arr[idx] < curr->data)  curr -> left = insert(arr , idx , curr-> left) ;
    else curr -> right = insert(arr , idx , curr->right) ;

    return curr ;
}

void print_BST(Node* root) {
    if(root == nullptr) return ;

    cout<<root ->data<<" " ;
    print_BST(root -> left) ;
    print_BST(root -> right) ;
}


int main(){
    int n ;
    cout<<"Enter number of elements : ";
    cin>>n ; 

    cout<<"Enter elements : " ;
    vector<int> elem(n) ;
    for(int i=0 ; i<n ; i++) cin>>elem[i] ;

    Node* root = nullptr;
    for(int i=0 ; i<n ; i++) {
        root = insert(elem , i , root) ;
    }

    print_BST(root) ;

    return 0 ;
}