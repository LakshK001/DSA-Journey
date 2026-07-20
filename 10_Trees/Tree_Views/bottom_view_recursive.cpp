/*
Problem: Top View of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
Difficulty: Medium
Topic: Binary Tree
Pattern: Recursive DFS 

Approach:
- The crux --> Bottom view has elements as number of horizontal nodes . The bottom view has elements from each horizontal position and that too with maximum level .
- It is the very similar problem to the top view , the only change is that the maximum level of element must be stored so the condition changes that current level is less than level stored .
- The iterative approach can also be done in the same way , just update the array every time without condition as traversal is level wise and we want the maximum level .


Time Complexity: O(n) 
Auxilliary Space Complexity: O(h+w) where h is height of binary tree and w is width of binary tree . In worst case , h = n or w = n .
*/

#include<vector>
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
  
    
    void Bview(vector<int> &ans , vector<int> &curr_level , Node *root , int pos , int level){
        if(root == nullptr) return ;
        
        if(curr_level[pos] == -1 || curr_level[pos]<level){
            ans[pos] = root -> data ;
            curr_level[pos] = level ;
        }
        
        Bview(ans , curr_level , root -> right , pos + 1 , level + 1) ;
        Bview(ans , curr_level , root -> left , pos - 1 , level + 1) ;
    }
    
    void find_extreme(Node *root , int pos , int &l , int &r){
        if(root == nullptr) return  ;
        
        l = min(l , pos) ;
        r = max(r , pos) ;
        
        find_extreme(root -> left , pos - 1 , l , r) ;
        find_extreme(root -> right , pos + 1 , l , r) ;
    }
    
    vector<int> bottomView(Node *root) {
        
        int l = 0 , r = 0 ;
        find_extreme(root , 0 , l , r) ;
        
        vector<int> ans(r-l+1) ;
        vector<int> curr_level(r-l+1 , -1) ;
        
        Bview(ans , curr_level , root , -l , 0) ;
        
        return ans ;
 
    }
};