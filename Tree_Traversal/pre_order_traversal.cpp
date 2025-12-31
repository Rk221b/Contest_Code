/*
 Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/description/
*/

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
class Solution
{

    void helper(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        ans.push_back(root->val);
        helper(root->left, ans);
        helper(root->right, ans);
    }

public:
    vector<int> preorderTraversal(TreeNode *root)
    {

        // Recursive

        // vector<int> ans;
        // helper(root,ans);

        // return ans;

        // Iterative

        vector<int> ans;
        stack<TreeNode *> st;

        if (!root)
            return ans;

        // Push root to stack first to start preorder
        st.push(root);

        while (!st.empty())
        {
            // Process stack top first
            TreeNode *element = st.top();
            st.pop();
            ans.push_back(element->val);

            // Process right node first
            if (element->right != NULL)
            {
                st.push(element->right);
            }

            // Process left node next
            if (element->left != NULL)
            {
                st.push(element->left);
            }
        }
        return ans;
    }
};