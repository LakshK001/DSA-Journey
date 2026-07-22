/*
Problem: Mirror Trees
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/mirror-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS

Approach:
- For mirroring the tree , the key concept is that swap the left and right sub branches for each node .
- It is done easily by pointing to one sub branch by temp and then putting other branch at its place and then at other's place put temp branch .
- This will be carried out for every sub branch untill it comes to nullptr .


Time Complexity: O(n)
Space Complexity: O(h) , where h is the height of the Binary Tree . In worst case h = n .
*/

/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* root) {
        
        if(root == nullptr) return ;
        
        Node * temp = root -> right ;
        root -> right = root -> left ;
        root -> left = temp ;
        
        mirror(root -> left) ;
        mirror(root -> right) ;
    }
};