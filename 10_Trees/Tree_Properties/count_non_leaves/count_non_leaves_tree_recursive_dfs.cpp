/*
Problem: Count Non Leaves in Binary Tree
Platform: GeeksForGeeks
Problem Link: https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1
Difficulty: Easy
Topic: Binary Tree
Pattern: Recursive DFS

Approach:
- Thought was the same as for counting the leaves .
- Just inverted the condition so that it can count non leaves instead of leaves .


Time Complexity: O(n)
Space Complexity: O(h) , where h is the height of the Binary Tree . In worst case h = n .

*/


using namespace std;


/*Structure of the node of the tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
*/


class Solution {
  public:
  
    int countNonLeaf(Node* root){
        if(root == nullptr) return 0 ;
        
        bool flag = !(root -> left == nullptr && root -> right == nullptr) ;
        return flag + countNonLeaf(root -> left) +countNonLeaf(root -> right) ;
    }
    
    int countNonLeafNodes(Node* root) {
        return countNonLeaf(root) ;
    }
};