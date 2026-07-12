/*
Problem: Sum Of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive Depth First Search (DFS) using variable

Approach:
- I just knew that the depth first search iterates over all the nodes once .
- So , just initialised variable from 0 and incremented by value of each node in each traversal .

Time Complexity: O(n)
Space Complexity: O(h) where h is the width of the Binary Tree . In worst case : h = n
*/



/* Tree Node Structure
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    
    void pre_order_traversal(Node* root , int &ans){
        if(root == nullptr) return  ;
        
        ans += root -> data ;
        
        pre_order_traversal(root -> right , ans) ;
        pre_order_traversal(root -> left , ans) ;
    }
    
    
    int sumBT(Node* root) {
        
        int ans = 0 ;
        pre_order_traversal(root , ans) ;
        return ans ;
        
    }
};