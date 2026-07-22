/*
Problem: Sum Of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive Depth First Search (DFS) using subtrees

Approach:
- The initial thought process was that the sum equals to sum of current node and nodes of left and right subtree .
- This statement was the same for every particular node and the base case was when the reference to node becomes nullptr .

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
    
    int dfs_sum(Node* root){
        if(root == nullptr) return 0 ;
        
        return root -> data + dfs_sum(root -> left) + dfs_sum(root -> right) ;
    }
    
    
    int sumBT(Node* root) {
        return dfs_sum(root) ;
    }
};