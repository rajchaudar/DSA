#include <iostream>
using namespace std;
class node
{
public:
    string key;
    string value;
    node *left, *right;
};
class Dictionary
{
public:
    node *root;
    Dictionary()
    {
        root = NULL;
    }

    void CreateTree(node *&root)
    {
        node *temp = new node;
        cout << endl
             << "\n Enter data of root node of tree(key & value):- ";
        cin >> temp->key >> temp->value;
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
        if (root->key > temp->key)
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
        else if (root->key < temp->key)
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
    void update_keyword(node *root, node *temp)
    {
        if (root->key > temp->key)
        {
            return update_keyword(root->left, temp);
        }
        else if (root->key < temp->key)
        {
            return update_keyword(root->right, temp);
        }
        else if (root->key == temp->key)
        {
            cout << "\n Key is already present..." << endl;
            cout << "\n Updating value..." << endl;
            root->value = temp->value;
            cout << "\n value updated succesfully" << endl;
            return;
        }
    }
    void InorderDisplay_ascending(node *root)
    {
        if (root == NULL)
        {
            return;
        }
        else
        {
            InorderDisplay_ascending(root->left);
            cout << root->key << " = " << root->value << " ";
            InorderDisplay_ascending(root->right);
        }
    }
    void InorderDisplay_descending(node *root)
    {
        if (root == NULL)
        {

            return;
        }
        else
        {
            InorderDisplay_descending(root->right);
            cout << root->key << " = " << root->value << " ";
            InorderDisplay_descending(root->left);
        }
    }
    int Search(node *root, string user_key, int comparision)
    {
        if (root->key == user_key)
        {
            cout << "\n Key is present in tree" << endl;
            comparision++;
            return comparision;
        }
        else if (root->key > user_key)
        {
            comparision++;
            return Search(root->left, user_key, comparision);
        }
        else if (root->key < user_key)
        {
            comparision++;
            return Search(root->right, user_key, comparision);
        }
        else
        {
            cout << "\n Key is not present in Tree" << endl;
            return comparision;
        }
    }
    node *MaxDataValue(node *root)
    {
        if (root == NULL)
        {
            return root;
        }
        else if (root->right == NULL)
        {
            return root;
        }
        else
        {
            return MaxDataValue(root->right);
        }
    }
    node *delete_node(node *root, string user_key)
    {
        if (root == NULL)
        {
            return root;
        }
        else if (root->key > user_key)
        {
            root->left = delete_node(root->left, user_key);
            return root;
        }
        else if (root->key < user_key)
        {
            root->right = delete_node(root->right, user_key);
            return root;
        }
        else
        {
            if ((root->left == NULL) && (root->right == NULL))
            {
                node *temp = root;
                root = NULL;
                delete temp;
                return root;
            }
            else if (root->right == NULL)
            {
                node *temp = root;
                root = root->left;
                delete temp;
                return root;
            }
            else if (root->left == NULL)
            {
                node *temp = root;
                root = root->right;
                delete temp;
                return root;
            }
            else
            {
                node *temp = MaxDataValue(root->left);
                root->key = temp->key;
                root->value = temp->value;
                root->left = delete_node(root->left, temp->key);
                return root;
            }
        }
    }
};
int main()
{
    Dictionary MyTree;
    int ch, comp;
    string key;
    string temp_key;
    cout << "1.Creating Tree(only one's)" << endl;
    cout << "2.Insert Element." << endl;
    cout << "3.Update keyword value." << endl;
    cout << "4.ascending traversing" << endl;
    cout << "5.descending traversing" << endl;
    cout << "6.Search Value." << endl;
    cout << "7.Delete node." << endl;
    cout << "8.Exit." << endl;
    while (true)
    {
        cout << endl
             << "\n Enter your choice:- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            MyTree.CreateTree(MyTree.root);
            cout << "\n Tree created successfully....." << endl;
            break;
        case 2:
            node *tem;
            tem = new node;
            cout << "\n Enter new node data(key & value):- ";
            cin >> tem->key >> tem->value;
            tem->left = NULL;
            tem->right = NULL;
            MyTree.InsertNode(MyTree.root, tem);
            cout << "\n Node added successfully....." << endl;
            break;
        case 3:
        {
            node *tem2 = new node;

            cout << "\n Enter the data of node want to replace(key & value):-";
            cin >> tem2->key >> tem2->value;
            tem2->left = NULL;
            tem2->right = NULL;
            // MyTree.InsertNode(MyTree.root,tem2);
            MyTree.update_keyword(MyTree.root, tem2);
            break;
        }
        case 4:
            cout << "\n Ascending traversing...:-" << endl;
            MyTree.InorderDisplay_ascending(MyTree.root);
            break;
        case 5:
            cout << "\n Ascending traversing...:-" << endl;
            MyTree.InorderDisplay_descending(MyTree.root);
            break;
        case 6:
            cout << "\n Enter the key want to find:- ";
            cin >> key;
            comp = MyTree.Search(MyTree.root, key, 0);
            cout << "\n Number of comparision required....." << comp << endl;
            break;
        case 7:
            cout << "\n Enter the key want to delete:-" << endl;
            cin >> temp_key;
            MyTree.delete_node(MyTree.root, temp_key);
            cout << "Successfully deleted " << temp_key << endl;
            break;
        case 8:
            cout << "\n Exiting...." << endl;
            exit(0);
            break;
        }
    }
    return 0;
}
