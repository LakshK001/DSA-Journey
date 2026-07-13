/*
Problem: Sum Root to Leaf Nodes
Platform: LeetCode 129
Problem Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/
Difficulty: Medium
Topic: Binary Tree
Pattern: Recursive DFS with accumulation from root to leaf .

Approach:
- The initial thought was accumulation of a number from root to leaf only that directly took me to DFS recursive search .
- One variable was accumulating the number by adding and multiplying the next left and right node values if they exist .
- The backtracking helped to get from the left child to the parent again so the accumulated sum can be used by parent .
- The base case was when we find leaf node , we just add it to the answer by dividing 10 .

Time Complexity: O(n)
Space Complexity: O(h) , where h is the height of the Binary Tree . In worst case h = n .

Mistakes I made :
- Initially I took the base case as when root becomes null .
- I took the temp as int , where it can overflow .
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


class Solution {
public:
    
    void dfs_sum(TreeNode* root , int &total , long long temp){
        
        if(root -> right == nullptr && root -> left == nullptr){
            total += temp/10 ;
            return ;
        }

        if(root -> left ){
            temp = (temp + root -> left -> val)*10  ;
            dfs_sum(root -> left , total , temp) ;
            temp = (temp/10 - root -> left -> val)  ;
        }

        if(root -> right ){
            temp = (temp + root -> right -> val)*10  ;
            dfs_sum(root -> right , total , temp) ;
        }
    }

    int sumNumbers(TreeNode* root) {
        int total_sum = 0;
        dfs_sum(root , total_sum , root -> val * 10) ;
        return total_sum ;
    }
};