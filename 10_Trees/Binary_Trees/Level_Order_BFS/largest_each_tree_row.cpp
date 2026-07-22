/*
Problem: Largest Value in Each Row
Platform: LeetCode 515
Problem Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
Difficulty: Medium
Topic: Binary Tree
Pattern: Iterative BFS

Approach:
- Observed that the queue size at the beggining implies number of nodes at 0th level .
- Later , after dry running the traversal , queue size comes always equal to number of nodes once all the nodes of previous level are removed .
- So , traversed each level by for loop and for each level calculated maximum .

Time Complexity: O(n)
Space Complexity: O(w) , where w is the width of the Binary Tree . In worst case w = n .

*/

#include<vector>
#include<queue>
#include<limits.h>
#include<algorithm>
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> max_each_row ;
        if(root == nullptr) return max_each_row ; 
         
        queue<TreeNode*> q ;
        q.push(root) ;


        while(!q.empty()) {
            int each_row_size = q.size() , maxi = INT_MIN ;
            
            while(each_row_size --){
                TreeNode *curr = q.front() ;
                maxi = max(curr -> val , maxi) ;

                if(curr -> left != nullptr) q.push(curr -> left) ;
                if(curr -> right != nullptr) q.push(curr -> right) ;

                q.pop() ;
            }
            max_each_row.push_back(maxi) ;
        }

        return max_each_row ;
    }
};