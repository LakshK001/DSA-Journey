/*
Problem: Pre-Order Traversal
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/preorder-traversal/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Depth First Search (DFS)

Approach:
- In pre order traversal , we first get the current node , then left branch and then right .
- We have done exactly the same thing in recursion , pushed current node then called for left branch and then right .
- The stopping point is when some branch is completed ie the current becomes NULL

Time Complexity: O(n)
Space Complexity: O(h) where h is the height of the Binary Tree . In worst case : h = n

*/


#include<vector>
using namespace std ;

/*
GFG Node Structure : 

class Node
{
    int data;
    Node* left;
    Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
  
    void preOrderTraversal(vector<int> & ans , Node *root){
        if(root == NULL) return ;
        
        ans.push_back(root -> data) ;
        preOrderTraversal(ans , root -> left) ;
        preOrderTraversal(ans , root -> right) ;
        
    }
    
    
    vector<int> preOrder(Node* root) {
        // code here
        vector<int> ans ;
        preOrderTraversal(ans , root) ;
        return ans ;
    }
};