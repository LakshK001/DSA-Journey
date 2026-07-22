/*
Problem: Size Of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/size-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive Depth First Search (DFS) using counter

Approach:
- I just knew that the depth first search iterates over all the nodes once .
- So , just added count initialised from 0 and incremented by 1 in each node traversal .

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
  
    void pre_order_traversal(Node* root , int &count){
        if(root == nullptr) return ;
        
        count++ ;
        pre_order_traversal(root -> left , count) ;
        pre_order_traversal(root -> right , count) ;
    }
    
    int getSize(Node* root) {
       
       int count = 0 ;
       pre_order_traversal(root , count) ;
       return count ;
        
    }
};