/*
Problem: Path Sum II
Platform: LeetCode
Problem Link: https://leetcode.com/problems/path-sum-ii/
Difficulty: Medium
Topic: Binary Tree
Pattern: DFS with backtracking

Approach:
- I just gone through simple DFS and used backtracking of pushing each value in array so that one single array can be used to traverse whole tree .
- If left sub branch exist go to left and include left node value and then pop , do the same for the right sub tree .
- Do this untill you get the leaf node and check if this whole branch satisfies sum , if yes push it in the 2-D array .


Time Complexity: O(n*n) as pushing back 1-D array to 2-D array requires O(h) time . In worst case h is approx n .
Auxilliary Space Complexity: O(n)
*/

#include<vector>
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
    void root_to_leaf(TreeNode* root , int target , vector<vector<int>> &paths , vector<int> &curr , int sum){

        if(root-> right == nullptr && root -> left == nullptr){
            if(target == sum) paths.push_back(curr) ;
            return ;
        }

        if(root -> left){
            int temp = root -> left -> val ;
            curr.push_back(temp) ;
            root_to_leaf(root -> left , target , paths , curr , sum+temp ) ;
            curr.pop_back() ;
        }

        if(root -> right){
            int temp = root -> right -> val ;
            curr.push_back(temp) ;
            root_to_leaf(root -> right , target , paths , curr , sum+temp ) ;
            curr.pop_back() ;
        }
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> paths ;
        if(root == nullptr) return paths ;
        
        vector<int> curr ;
        curr.push_back(root -> val) ;
        root_to_leaf(root , targetSum , paths , curr , root -> val) ;

        return paths ;
    }
};