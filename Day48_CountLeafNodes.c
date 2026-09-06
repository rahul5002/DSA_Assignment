#include <stdlib.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int countLeaves(struct TreeNode* root)
{
    if (!root)
    {
        return 0;
    }

    if (!root->left && !root->right)
    {
        return 1;
    }

    return countLeaves(root->left) + countLeaves(root->right);
}

int main()
{
    return 0;
}