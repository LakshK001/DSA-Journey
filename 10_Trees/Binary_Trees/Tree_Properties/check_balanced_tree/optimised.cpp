// Balanced Tree --> For every node , the absolute difference of right and left sub branch height should not be more than 1 .

/*
Problem: Check Balanced Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS for height

Approach:
- For optimal approach , we have to carefully observe the pattern of recursive calls for calculating height .
- For calculating height of a node , each node in the sub trees get the height of their left and right sub branch one by one .
- This means we get the left and right itself while calculating height , just use condition of balanced tree in each step to check .

Time Complexity: O(n)
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
  
    int height(Node *root , bool &valid){
        if (root == nullptr) return -1 ;
        
        int l = height(root-> left , valid) ;
        int r = height(root-> right , valid) ;
        
        if(abs(l-r) > 1) valid = 0 ;
        
        return 1 + max(l,r) ;
    }
    
    bool isBalanced(Node* root) {
        
        bool valid = 1 ;
        height(root , valid) ;
        
        return valid ;
    }
};