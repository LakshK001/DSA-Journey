/*
Problem: Top View of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
Difficulty: Medium
Topic: Binary Tree
Pattern: Recursive DFS 

Approach:
- The crux --> Top view has elements as number of horizontal nodes . The top view has elements from each horizontal position and that too with least level .
- The similar thinking and approach is used as the iterative . The change is just that here we are using pre order traversal .
- Problem in recursive DFS --> no guarantee that we get the minimum level height element of particular position .
- Solution --> Another vector which carries the minimum level stored in that particular position till now ie update the value only if that position is seen first time or current level is less than stored level .


Time Complexity: O(n) 
Auxilliary Space Complexity: O(h+w) where h is height of binary tree and w is width of binary tree . In worst case , h = n or w = n .
*/

#include<vector>
#include<algorithm>
using namespace std ;

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
  
    void top_view_find (Node* root ,vector<int> &ans , vector<int> &min_level , int pos , int level){
        if(root == nullptr) return ;
        
        if(min_level[pos] == -1 || level < min_level[pos]){
            ans[pos] = root -> data ;
            min_level[pos] = level ;
        }
        
        top_view_find(root-> left, ans , min_level , pos -1 , level+1 ) ;
        top_view_find(root-> right, ans , min_level , pos +1 , level+1 ) ;
    }
    
    void find_extreme(Node* root , int pos , int &l ,int &r){
        if(root == nullptr) return ;
        
        l = min(l , pos) ;
        r = max(r , pos) ;
        
        find_extreme(root -> left , pos-1 , l ,r ) ;
        find_extreme(root -> right , pos+1 , l ,r ) ;
    }
    
    
    vector<int> topView(Node *root) {
        
        int l =0 , r = 0 ;
        find_extreme(root , 0 , l , r) ;
        vector<int> ans(r-l+1 );
        vector<int> min_level(r-l+1 , -1);
        
        top_view_find(root , ans , min_level , -l , 0) ;
        
        return ans ;
    }
};