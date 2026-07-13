/*
Problem: Construct String from Binary Tree
Platform: LeetCode 606
Problem Link: https://leetcode.com/problems/construct-string-from-binary-tree/
Difficulty: Medium
Topic: Binary Tree
Pattern: Recursive DFS and String formation

Approach:
- For each valid node , push the value of node in the string . The value can be either made by stoi or manually by accessing digits and handling edge case .
- Then if the left node exist , open the paranthesis and go to left subtree then close parenthesis . Then check if right exist , do the same for it .
- If left does not exist , then check for right , if exists then add () for telling the left empty as per problem statement . If right does not exist then return .
- Base case is when the root becomes null ptr .

Time Complexity: O(n)
Space Complexity: O(h) , where h is the height of the Binary Tree . In worst case h = n .

Mistakes I made :
- I didn't read problem carefully and interpreted the single digit number only . Then I saw constraints and corrected the code for multi digit and negative numbers .
- Then I forgot about the edge case for the 0 value as it not be passed in s . Then I added another edge case condition .

*/

#include<iostream>
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

    void transform(TreeNode* root , string &s){
        if(root == nullptr) return ;
        
        if(root -> val < 0) s.push_back('-') ;

        int pushing_value = abs(root -> val) ;
        if(pushing_value == 0) s.push_back('0') ;
        string temp ;

        while(pushing_value != 0){
            int ld = pushing_value % 10 ;
            temp.push_back(ld + '0') ;
            pushing_value /= 10 ;
        }

        reverse(temp.begin() , temp.end()) ;
        s += temp ;

         

        if(root -> left){
            s.push_back('(') ;
            transform(root -> left , s) ;
            s.push_back(')') ;

            if(root -> right){
                s.push_back('(') ;
                transform(root -> right , s) ;
                s.push_back(')') ;
            }
        }
        else{
            if(root -> right){
                s += "()" ;
                s.push_back('(') ;
                transform(root -> right , s) ;
                s.push_back(')') ;
            }
            else return ;
        }
    }

    string tree2str(TreeNode* root) {
        string s ;
        transform(root , s) ;
        return s ;
    }
};