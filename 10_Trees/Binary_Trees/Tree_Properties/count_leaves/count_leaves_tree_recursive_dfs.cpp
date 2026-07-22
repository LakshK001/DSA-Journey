/*
Problem: Count Leaves in Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS

Approach:
- The DFS also iterates all the nodes in the Binary Tree .
- The key concept here is that the total count will be current element if any and the right and left subtree .
- The function call towards right and left subtree will help traversing all the nodes , the base case is when root becomes nullptr. 

Time Complexity: O(n)
Space Complexity: O(h) , where h is the height of the Binary Tree . In worst case h = n .

*/


using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */


class Solution {
  public:
    
    int countLeavesDFS(Node* root){
        if(root == nullptr) return 0 ;
        
        bool flag = root -> right == nullptr && root -> left == nullptr ;
        return flag + countLeavesDFS(root -> left) + countLeavesDFS(root -> right) ;
        
    }
    
    int countLeaves(Node* root) {
        return countLeavesDFS(root) ;
    }
};