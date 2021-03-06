/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> bfs;
        vector<vector<int>> levels;
        if (!root) {
            return levels;
        }
        bool leftToRight = true;
        bfs.push(root);
        while (!bfs.empty()) {
            int size = bfs.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* node = bfs.front();
                bfs.pop();
                level.push_back(node->val);
                if (node->left) {
                    bfs.push(node->left);
                }
                if (node->right) {
                    bfs.push(node->right);
                }
            }
            if (!leftToRight) {
                reverse(level.begin(), level.end());
            }
            leftToRight = !leftToRight;
            levels.push_back(level);
        }
        return levels;
    }
};