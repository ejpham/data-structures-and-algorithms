#ifndef BINTREE_H
#define BINTREE_H

struct binaryTreeNode
{
    int info;
    binaryTreeNode* llink;
    binaryTreeNode* rlink;
};

class binaryTree
{
private:
    binaryTreeNode* root;
    int height(binaryTreeNode* p) const;
    int max(int x, int y) const;
    void destroy(binaryTreeNode*& p);
    void deleteFromTree(binaryTreeNode*& p);

    int sum;
    void initSum();
    void addValue(int value);
    void preorder_mod(binaryTreeNode* p);
public:
    binaryTree();
    bool isEmpty() const;
    int treeHeight() const;
    void insert(const int& insertItem);
    void deleteNode(const int& deleteItem);
    void destroyTree();
    ~binaryTree();

    int getSumOfAllLeftNodes();
};

#endif