https://leetcode.com/problems/cousins-in-binary-tree/description/

993. Cousins in Binary Tree
Solved
Easy
Topics
Companies
Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

 
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


 I simply create  a mapping of child node and parent node and level .than according to question if level is same and parent is different than nodes are cousin simply return true else return false;


class Solution {
public:
    void dfs(TreeNode* root, int x, int y, int level, int node, vector<pair<pair<int, int>, int>>& mp) {
        if (root == NULL) return;
        if (root->val == x || root->val == y) {
            mp.push_back({{root->val, node}, level});
        }
        dfs(root->left, x, y, level + 1, root->val, mp);
        dfs(root->right, x, y, level + 1, root->val, mp);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        vector<pair<pair<int, int>, int>> mp;
        dfs(root, x, y, 0, root->val, mp);
        int xLevel = -1, yLevel = -1;
        int xParent = -1, yParent = -1;

        for (auto it : mp) {
            if (it.first.first == x) {
                xLevel = it.second;
                xParent = it.first.second;
            } else if (it.first.first == y) {
                yLevel = it.second;
                yParent = it.first.second;
            }
        }

        if (xLevel != -1 && yLevel != -1 && xLevel == yLevel && xParent != yParent) {
            return true;
        }

        return false;
    }
};
