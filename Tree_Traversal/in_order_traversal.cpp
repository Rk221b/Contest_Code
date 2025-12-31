/*
 Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/description/
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
    void helper(TreeNode *root, vector<int> &inOrder)
    {

        if (root == NULL)
            return;

        helper(root->left, inOrder);
        inOrder.push_back(root->val);
        helper(root->right, inOrder);
    }

public:
    vector<int> inorderTraversal(TreeNode *root)
    {

        // Recursive

        // vector<int> inOrder;
        // helper(root,inOrder);

        // return inOrder;

        // Iterative

        vector<int> ans;
        stack<TreeNode *> st;

        while (root != NULL || !st.empty())
        {

            // Go left till you can
            while (root != NULL)
            {
                st.push(root);
                root = root->left;
            }

            // Process the element as we are not on leftmost node
            TreeNode *element = st.top();
            st.pop();
            ans.push_back(element->val);

            // Can Go one step to right
            root = element->right;
        }

        return ans;
    }
};