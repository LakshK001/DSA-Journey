/*
Problem: Top View of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
Difficulty: Medium
Topic: Binary Tree
Pattern: Iterative BFS 

Approach:
- The crux --> Top view has elements as number of horizontal nodes . The top view has elements from each horizontal position and that too with least level .
- The horizontal number of nodes is determined by going to extreme left and right , then updating left as negative x axis and right as positive .
- Now , in order to store values in array , index start with zero ie assume everything position is shifted towards positive x-axis by extreme left (l) .
- This shift brings the , root at the abs(l) position .
- Now , we just iterate in BFS and see if value is not already updated at specefic position , update it because we iterate level wise , so least level comes first .


Time Complexity: O(n) 
Auxilliary Space Complexity: O(w) where w is width of binary tree . In worst case , w = n .
*/

#include<vector>
#include<algorithm>
#include<queue>
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
  
    void find_extremes(Node* root , int curr , int &l , int &r){
        if(root == nullptr) return ;
        
        l = min(l , curr) ;
        r = max(r , curr) ;
        
        find_extremes(root-> left , curr-1 , l , r);
        find_extremes(root-> right , curr+1 , l , r);
    }

    vector<int> topView(Node *root) {
        
        int l = 0 , r = 0 ;
        find_extremes(root , 0 , l , r) ;
        
        vector<int> top_view(r-l+1) ;
        vector<bool> visited(r-l+1 , 0) ;
        
        queue<Node*> level ;
        queue<int> shifted_x ;
        level.push(root) ;
        shifted_x.push(-l) ;
        
        
        while(!level.empty()){
            
            int curr_idx = shifted_x.front() ;
            Node *curr = level.front() ;
            
            if(visited[curr_idx] == 0){
                visited[curr_idx] = 1 ;
                top_view[curr_idx] = curr -> data ;
            }
            
            if(curr -> left != NULL){
                level.push(curr -> left) ;
                shifted_x.push(curr_idx - 1) ;
            }
            
            if(curr -> right != NULL){
                level.push(curr -> right) ;
                shifted_x.push(curr_idx + 1) ;
            }
            
            level.pop() ;
            shifted_x.pop() ;
        }
        
        return top_view ;
    }
};