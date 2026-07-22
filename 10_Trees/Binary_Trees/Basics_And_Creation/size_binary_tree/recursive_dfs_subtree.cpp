/*
Problem: Size Of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/size-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive Depth First Search (DFS) using subtrees

Approach:
- The initial thought process was that the size equals to size of current node and nodes of left and right subtree .
- This statement was the same for every particular node and the base case was when the reference to node becomes nullptr .

Time Complexity: O(n)
Space Complexity: O(h) where h is the width of the Binary Tree . In worst case : h = n
*/


/* Node Structure
class Node {
public:
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    int tree_size(Node* root){
        if(root == nullptr) return 0 ;
        
        return 1 + tree_size(root -> left) + tree_size(root -> right) ;
    }
    
    int getSize(Node* root) {
       
       return tree_size(root) ;
        
    }
};