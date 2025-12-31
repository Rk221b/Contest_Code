/*
 Problem Link: https://leetcode.com/problems/binary-tree-postorder-traversal/description/
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

        helper(root->left, ans);
        helper(root->right, ans);
        ans.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
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

        // Push root to stack to start postorder traversal
        st.push(root);

        while (!st.empty())
        {
            // Process st top first
            TreeNode *element = st.top();
            st.pop();
            ans.push_back(element->val);

            // Process left node first
            if (element->left != NULL)
            {
                st.push(element->left);
            }

            // Process right node next
            if (element->right != NULL)
            {
                st.push(element->right);
            }
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};