// Balanced Tree --> For every node , the absolute difference of right and left sub branch height should not be more than 1 .

/*
Problem: Check Balanced Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS for height

Approach:
- For the brute force , I thought that I will do normal DFS search for left and right sub-branch and check current status by checking height at each node .
- The tree will be unbalanced if any of the node will be unbalanced thus used and operator bw current node , left and right subtree .
- The condition for balanced tree becomes , abs(left_ht - right_ht) <= 1 .


Time Complexity: O(n*n)
Space Complexity: O(h) , where h is the height of the Binary Tree . In worst case h = n .
*/


#include<algorithm>
using namespace std ;

/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
    int height(Node *root){
        if (root == nullptr) return -1 ;
        
        return 1 + max(height(root -> left) , height(root -> right)) ;
    }
    
    bool isBalanced(Node* root) {
        
        if(root == nullptr) return 1 ;
        
        int l = height(root -> left) , r = height(root -> right);
        bool flag = abs(l - r) <= 1 ;
        
        return flag && isBalanced(root -> left) && isBalanced(root -> right) ;
    }
};