/*
Problem: Count Non Leaves in Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Iterative BFS

Approach:
- I just thought of the same way I thought for the leaves in Binary Tree .
- Just inverted the condition so it becomes for the non leaf nodes .

Time Complexity: O(n)
Space Complexity: O(w) , where w is the width of the Binary Tree . In worst case w = n .

*/

#include<queue>
using namespace std;


/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/


class Solution {
  public:
    int countNonLeafNodes(Node* root) {
        
        queue<Node*> q ;
        q.push(root) ;
        
        int non_leaves = 0 ;
        
        while(!q.empty()) {
            
            Node *curr = q.front() ;
            
            if(!(curr -> left == nullptr && curr -> right == nullptr)) non_leaves ++ ;
            
            if(curr -> left != nullptr) q.push(curr -> left) ;
            if(curr -> right != nullptr) q.push(curr -> right) ;
            
            q.pop() ;
        }
        
        return non_leaves ;
    }
};