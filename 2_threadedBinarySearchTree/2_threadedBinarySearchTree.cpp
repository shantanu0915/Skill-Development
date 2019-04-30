#include<bits/stdc++.h>
using namespace std;

struct treeNode
{
    struct treeNode *left, *right;
    int info;
    bool lthread;
    bool rthread;
};

treeNode *insert(treeNode *root, int ikey)
{
    treeNode *ptr = root;
    treeNode *par = NULL;
    while (ptr != NULL)
    {
        if (ikey == (ptr->info))
        {
            printf("Duplicate Key !\n");
            return root;
        }

        par = ptr;
        if (ikey < ptr->info)
        {
            if (ptr -> lthread == false)
                ptr = ptr -> left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr -> right;
            else
                break;
        }
    }

    treeNode *tmp = new treeNode;
    tmp -> info = ikey;
    tmp -> lthread = true;
    tmp -> rthread = true;

    if (par == NULL)
    {
        root = tmp;
        tmp -> left = NULL;
        tmp -> right = NULL;
    }
    else if (ikey < (par -> info))
    {
        tmp -> left = par -> left;
        tmp -> right = par;
        par -> lthread = false;
        par -> left = tmp;
    }
    else
    {
        tmp -> left = par;
        tmp -> right = par -> right;
        par -> rthread = false;
        par -> right = tmp;
    }

    return root;
}

treeNode *inorderSuccessor(treeNode *ptr)
{
    if (ptr -> rthread == true)
        return ptr->right;
    ptr = ptr -> right;
    while (ptr -> lthread == false)
        ptr = ptr -> left;
    return ptr;
}

void inorder(treeNode *root)
{
    if (root == NULL)
        printf("Tree is empty");
    treeNode *ptr = root;
    while (ptr -> lthread == false)
        ptr = ptr -> left;
    while (ptr != NULL)
    {
        printf("%d ",ptr -> info);
        ptr = inorderSuccessor(ptr);
    }
}
int main()
{
    treeNode *root = NULL;
    char ch = 'y';
    int val;
    while(ch == 'y')
    {
        cout<<"Enter any number: ";
        cin>>val;
        root = insert(root,val);
        cout<<"Do you wish to enter more (y/n): ";
        cin>>ch;
    }
    cout<<"Inorder Traversal: ";
    inorder(root);

    return 0;
}

