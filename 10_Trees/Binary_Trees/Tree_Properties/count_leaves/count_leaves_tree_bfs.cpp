/*
Problem: Count Leaves in Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Iterative BFS

Approach:
- The breadth first search will traverse all the elements of the tree .
- Just add the simple counter variable which counts the leaves .
- Counter increments only if the right and left child does not exist ie in case of leave node .

Time Complexity: O(n)
Space Complexity: O(w) , where w is the width of the Binary Tree . In worst case w = n .

*/

#include<queue>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution {
  public:
    
    int countLeaves(Node* root) {
        
        queue<Node*> q ;
        q.push(root) ;
        
        int leaves = 0 ;
        
        while(!q.empty()) {
            
            Node *curr = q.front() ;
            
            if(curr -> left == nullptr && curr -> right == nullptr) leaves ++ ;
            
            if(curr -> left != nullptr) q.push(curr -> left) ;
            if(curr -> right != nullptr) q.push(curr -> right) ;
            
            q.pop() ;
        }
        
        return leaves ;
    }
};