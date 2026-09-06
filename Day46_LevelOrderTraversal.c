#include <stdlib.h>

struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int getTreeSize(struct TreeNode* root)
{
    if (!root)
    {
        return 0;
    }
    return 1 + getTreeSize(root->left) + getTreeSize(root->right);
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (!root)
    {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    int treeSize = getTreeSize(root);
    
    struct TreeNode** queue = (struct TreeNode**)malloc(treeSize * sizeof(struct TreeNode*));
    int head = 0;
    int tail = 0;
    
    int** result = (int**)malloc(treeSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(treeSize * sizeof(int));
    *returnSize = 0;

    queue[tail++] = root;

    while (head < tail)
    {
        int levelSize = tail - head;
        result[*returnSize] = (int*)malloc(levelSize * sizeof(int));
        (*returnColumnSizes)[*returnSize] = levelSize;

        for (int i = 0; i < levelSize; i++)
        {
            struct TreeNode* node = queue[head++];
            result[*returnSize][i] = node->val;

            if (node->left)
            {
                queue[tail++] = node->left;
            }
            if (node->right)
            {
                queue[tail++] = node->right;
            }
        }
        (*returnSize)++;
    }

    free(queue);
    return result;
}

int main()
{
    return 0;
}