/*
Problem: Left View of Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS 

Approach:
- In recursive standard pre order traversal , we can add a parameter level that will actually tell the current level of tree .
- But how we will know that it is the first element of that level was the question ?
- We solved this problem as first time we go to a level , we land at the first element only at that level .
- So , when we go to nth level , already n elements should be there in the array ie insert value when arr.size() == level .


Time Complexity: O(n) 
Auxilliary Space Complexity: O(h) where h is height of binary tree . In worst case , h = n .
*/

#include<vector>
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
  
    void l_view(int level , Node* root , vector<int> &left_view) {
        if(root == nullptr) return ;
        
        if(left_view.size() == level) left_view.push_back(root -> data) ;
        
        l_view(level+1 , root -> left , left_view) ;
        l_view(level+1 , root -> right , left_view) ;
    }
    
    vector<int> leftView(Node *root) {
    
       vector<int> left_view ;
       l_view(0 , root , left_view) ;
       
       return left_view ;
    }
};