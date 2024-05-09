#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left, *right;
};
class BST
{
public:
    node *root;
    BST()
    {
        root = NULL;
    }
    void CreateTree(node *&root)
    {
        node *temp = new node;
        cout << endl
             << "Enter root node of tree:- ";
        cin >> temp->data;
        temp->left = NULL;
        temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            InsertNode(root, temp);
        }
    }
    void InsertNode(node *root, node *temp)
    {
        if (root == NULL)
        {
            cout << "Tree is empty...." << endl;
        }
        else if (root->data > temp->data)
        {
            if (root->left == NULL)
            {
                root->left = temp;
            }
            else
            {
                InsertNode(root->left, temp);
            }
        }
        else
        {
            if (root->right == NULL)
            {
                root->right = temp;
            }
            else
            {
                InsertNode(root->right, temp);
            }
        }
    }
    void InorderDisplay(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            InorderDisplay(root->left);
            cout << root->data << " ";
            InorderDisplay(root->right);
        }
    }
    int longestpath(node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        else
        {
            return (max(longestpath(root->left), longestpath(root->right)) + 1);
        }
    }
    int MinDataValue(node *root)
    {
        if (root == NULL)
        {
            return -1;
        }
        else if (root->left == NULL)
        {
            return root->data;
        }
        else
        {
            return MinDataValue(root->left);
        }
    }
    void Search(node *root, int num)
    {
        if (root->data == num)
        {
            cout << "Key is present in tree" << endl;
        }
        else if (root->data > num)
        {
            Search(root->left, num);
        }
        else if (root->data < num)
        {
            Search(root->right, num);
        }
        else
        {
            cout << "Key is not present in Tree" << endl;
        }
    }
    void SwapTreeNode(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            node *temp = new node;
            temp = root->left;
            root->left = root->right;
            root->right = temp;
            SwapTreeNode(root->left);
            SwapTreeNode(root->right);
        }
    }
};
int main()
{
    BST MyTree;
    int ch;
    cout << "1.Creating Tree(only one's)" << endl;
    cout << "2.Insert Element." << endl;
    cout << "3.Display Tree." << endl;
    cout << "4.Number of Nodes on longest path" << endl;
    cout << "5.Minimum value node in tree is" << endl;
    cout << "6.Search Value." << endl;
    cout << "7.Swap Tree nodes." << endl;
    cout << "8.Exit." << endl;

    while (true)
    {
        cout << endl
             << "Enter your choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            MyTree.CreateTree(MyTree.root);
            cout << "Tree created successfully....." << endl;
            break;
        case 2:
            node *tem;
            tem = new node;
            cout << "Enter new node data:- ";
            cin >> tem->data;
            tem->left = NULL;
            tem->right = NULL;
            MyTree.InsertNode(MyTree.root, tem);
            cout << "Node added successfully....." << endl;
            break;
        case 3:
            cout << "node in tree are:- " << endl;
            MyTree.InorderDisplay(MyTree.root);
            break;
        case 4:
            cout << "Number of nodes in longest path:- " << MyTree.longestpath(MyTree.root) << endl;
            break;
        case 5:
            cout << "Minimum value node in tree is :- " << MyTree.MinDataValue(MyTree.root) << endl;
            break;
        case 6:
            int key;
            cout << "Enter the key want to find:- ";
            cin >> key;
            MyTree.Search(MyTree.root, key);
            break;
        case 7:
            cout << "Swapping Tree nodes..." << endl;
            MyTree.SwapTreeNode(MyTree.root);
            cout << "Tree nodes Swapped.." << endl;
            break;
        case 8:
            cout << "Exiting...." << endl;
            exit(0);

            break;
        }
    }
    return 0;
}
