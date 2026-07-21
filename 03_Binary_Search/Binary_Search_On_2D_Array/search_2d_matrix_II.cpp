/*
Problem: Search a 2D Matrix II
Platform: Leetcode
Problem Link: https://leetcode.com/problems/search-a-2d-matrix-ii/description/
Difficulty: Medium
Topic: Binary Search
Pattern: Staircase Search

Approach:
- There are two corners in the matrix from where if we go in two different direction , the value increases and decreases in other direction .
- One is top right corner , if we go to left value decrease and if down value increases .(Used in this solution)
- One is bottom left corner , if we go to up value decrease and if right value increases .
- This analysis is used for deciding every step that where to iterate next from right now .

Time Complexity: O(r+c) 
Auxilliary Space Complexity: O(1)
*/

#include<vector>
using namespace std ;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size() , c = matrix[0].size() ;

        int i = 0 , j = c-1 ;
        while(i<r && j>=0){

            if(matrix[i][j] == target) return 1 ;
            else if(matrix[i][j] > target) j-- ;
            else i++ ;

        }
        return 0 ;
    }
};