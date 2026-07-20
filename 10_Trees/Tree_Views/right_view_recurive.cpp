/*
Problem: Right View of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS 

Approach:
- Same observation as left view -> when a level will start if it will give the right/end most element update it .
- We will know that it is particular element , if arr.size() == level because at nth level n elements are already there in array (0 to n-1 levels).
- The only twist is that we recursively gone to right side first .
- Similary Iterative BFS can be done easily in this by constantly updating arr[i] for all elements of particular level . Last updation will automatically store right most element .


Time Complexity: O(n) 
Auxilliary Space Complexity: O(h) where h is height of binary tree . In worst case , h = n .
*/

#include<vector>
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
  
    void Rview (int level , vector<int> & ans , Node* root){
        if(root == nullptr) return ;
        
        if(level == ans.size()) ans.push_back(root-> data) ;
        
        Rview(level + 1 , ans , root -> right) ;
        Rview(level + 1 , ans , root -> left) ;
    }
    
    vector<int> rightView(Node *root) {
        
        vector<int> ans ;
        Rview(0 , ans , root) ;
        return ans ;
    }
};