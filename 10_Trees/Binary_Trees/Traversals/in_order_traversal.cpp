/*
Problem: In-Order Traversal
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/inorder-traversal/1
Difficulty: Easy
Topic: Binary Trees
Pattern: Depth First Search (DFS)

Approach:
- The approach was very similar to the pre-order traversal .
- We just have to traverse the left subtree then the node and then the right subtree .
- It was done in the same recursive way just changed the position of statemenets

Time Complexity: O(n)
Space Complexity: O(h) where h is the height of binary tree . In worst case , h = n

*/


#include<iostream>
#include<vector>
using namespace std ;

/*
GFG provides :
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  
    void traversal(vector<int> & ans , Node *root){
        if(root == NULL) return ;
        
        traversal(ans , root -> left) ;
        ans.push_back(root -> data) ;
        traversal(ans , root -> right) ;
        
    }
    
    vector<int> inOrder(Node* root) {
        // code here
        vector<int> ans ;
        traversal(ans , root) ;
        return ans ;
    }
};