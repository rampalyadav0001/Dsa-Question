https://leetcode.com/problems/cousins-in-binary-tree-ii/description/

Cousins in Binary Tree II

Given the root of a binary tree, replace the value of each node in the tree with the sum of all its cousins values.

Two nodes of a binary tree are cousins if they have the same depth with different parents.

Return the root of the modified tree.

Note that the depth of a node is the number of edges in the path from the root node to it.

 

Example 1:


Input: root = [5,4,9,1,10,null,7]
Output: [0,0,0,7,7,null,11]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 5 does not have any cousins so its sum is 0.
- Node with value 4 does not have any cousins so its sum is 0.
- Node with value 9 does not have any cousins so its sum is 0.
- Node with value 1 has a cousin with value 7 so its sum is 7.
- Node with value 10 has a cousin with value 7 so its sum is 7.
- Node with value 7 has cousins with values 1 and 10 so its sum is 11.
Example 2:


Input: root = [3,1,2]
Output: [0,0,0]
Explanation: The diagram above shows the initial binary tree and the binary tree after changing the value of each node.
- Node with value 3 does not have any cousins so its sum is 0.
- Node with value 1 does not have any cousins so its sum is 0.
- Node with value 2 does not have any cousins so its sum is 0.





code::->
class Solution {
public:
    // This function is used to calculate the sum of values at each level in the binary tree.
    void dfs(TreeNode* root, int level, unordered_map<int, int>& mp) {
        if (root == nullptr) return; // If the node is null, return.

        mp[level] += root->val; // Add the value of the current node to the sum at its level.
        dfs(root->left, level + 1, mp); // Recursively call dfs for the left child.
        dfs(root->right, level + 1, mp); // Recursively call dfs for the right child.
    }

    // This function is used to replace each node's value with the difference between the sum at its level and the sum of its children's values.
    void solve(TreeNode* root,int sublingsum, int level, unordered_map<int, int>& mp) {
       if(root==NULL)return ; // If the node is null, return.

       int leftchild=root->left==NULL?0:root->left->val; // Get the value of the left child if it exists, otherwise 0.
       int rightchild=root->right==NULL?0:root->right->val; // Get the value of the right child if it exists, otherwise 0.
       solve(root->left,rightchild,level+1,mp); // Recursively call solve for the left child.
       solve(root->right,leftchild,level+1,mp); // Recursively call solve for the right child.
       root->val=mp[level]-(root->val+sublingsum); // Replace the current node's value with the difference between the sum at its level and its children's values.
    }

    // This function is used to replace each node's value in a binary tree with the difference between the sum of all nodes at that level and its children's values.
    TreeNode* replaceValueInTree(TreeNode* root) {
        if (root == nullptr) return nullptr; // If the root is null, return null.

        unordered_map<int, int> mp; // Create a map to store the sum of values at each level.
        dfs(root, 0, mp); // Call dfs to calculate the sum of values at each level.
        solve(root, 0,0, mp); // Call solve to replace each node's value.

        return root; // Return the root of the modified tree.
    }
};


code 2::-->(bfs)

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        vector<int>level;

        while (!q.empty()) {
            int currLevelSum = 0;
            int sz = q.size();
            while (sz--) {
                TreeNode* currNode = q.front();
                q.pop();
                currLevelSum += currNode->val;
                if (currNode->left)
                    q.push(currNode->left);
                if (currNode->right)
                    q.push(currNode->right);
            }
            level.push_back(currLevelSum);
        }

        q.push(root);
        int i = 1;
        root->val = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* currNode = q.front();
                q.pop();
                int siblingSum = currNode->left ? currNode->left->val : 0;
                siblingSum += currNode->right ? currNode->right->val : 0;
                if (currNode->left) {
                    currNode->left->val = level[i] - siblingSum;
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    currNode->right->val = level[i] - siblingSum;
                    q.push(currNode->right);
                }
            }
            i++;
        }
        return root;
    }
};

code 3::-->

class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode* >q;
        q.push(root);
        int prevLevelSum = root->val;

        while (!q.empty()) {
            int sz = q.size();
            queue<TreeNode*>currentLevelNodes;
            int currLevelSum = 0;

            while (sz--) {
                TreeNode* currNode = q.front();
                q.pop();
                currNode->val = prevLevelSum - currNode->val;

                int siblingSum = currNode->left ? currNode->left->val : 0;
                siblingSum += currNode->right ? currNode->right->val : 0;

                if (currNode->left) {
                    currLevelSum += currNode->left->val;
                    currNode->left->val = siblingSum;
                    q.push(currNode->left);
                }
                if (currNode->right) {
                    currLevelSum += currNode->right->val;
                    currNode->right->val = siblingSum;
                    q.push(currNode->right);
                }
            }

            prevLevelSum = currLevelSum;
        }
        return root;
    }
};