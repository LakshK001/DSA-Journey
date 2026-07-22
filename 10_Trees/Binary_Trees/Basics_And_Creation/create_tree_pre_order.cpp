/*
Problem: Construct Binary Tree using pre-order inputs
Difficulty: Easy
Topic: Binary Tree
Pattern: Pre-order traversal (DFS)

Approach:
- Get the input for each node starting from the root node .
- Deciding whether to keep the node or not depending on the value . -1 -> end of the branch .
- Using recursive calls to put the reference of left and then the right child of the node .
- Then returning the current node to the parent node or the main function in order to store the reference in correct place .

Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the Binary Tree . In worst case : h == n

Mistake I made:
- Initially I grasped the concept of the construction while watching lecture but I was very confused about how to take each input .
- This was the first time that I saw that we are taking input inside the recursive function .

Note:
- Since -1 is used as the null marker, it cannot be stored as node data.
*/


#include<iostream>
using namespace std ;

class Node{
    public :
    int data ;
    Node *left , *right ;

    Node(int val){
        data = val ;
        left = right = NULL ;
    }
};

Node* binary_tree (){
    int x ;
    cin >> x ;
    if(x == -1) return NULL ;

    Node* temp = new Node(x) ;

    cout<<"Enter the left child of "<<x<<" : ";
    temp -> left = binary_tree() ;

    cout<<"Enter the right child of "<<x<<" : ";
    temp -> right = binary_tree() ;

    return temp ;
}


int main(){
    
    cout<<"Enter root node : " ;
    Node *root = binary_tree() ;
    
    return 0 ;
}