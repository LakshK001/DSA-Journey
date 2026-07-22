/*
Problem: Find Bottom Left in Binary Tree
Platform: LeetCode 513
Problem Link: https://leetcode.com/problems/find-bottom-left-tree-value/
Difficulty: Medium
Topic: Binary Tree
Pattern: Iterative BFS

Approach:
- Accessing every level by BFS by knowing that queue size at each level initially represents number of nodes at that level .
- So the first element in the level is the left most element of the level .
- Updating every time left most element at each level will last put left most element of last level .

Time Complexity: O(n)
Space Complexity: O(w) , where w is the width of the Binary Tree . In worst case w = n .

*/

#include<queue>
using namespace std ;

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
    int findBottomLeftValue(TreeNode* root) {

        int bottom_left = root -> val ;
        queue<TreeNode*> q ;
        q.push(root) ;

        while(!q.empty()){
            int level_size = q.size() ;

            for(int i=0 ; i<level_size ; i++){

                TreeNode *curr = q.front() ;
                if(i == 0) bottom_left = curr -> val ;

                if(curr -> left != nullptr) q.push(curr -> left) ;
                if(curr -> right != nullptr) q.push(curr -> right) ;
                q.pop() ;
            }
        }

        return bottom_left ;
    }
};