#include <iostream>
#include <stack>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    char ch;
};
bool isOperator(char c)
{

    if (c == '+' || c == '-' || c == '*' || c == '/')
    {
        return true;
    }
    return false;
}
node *newNode(char c)
{
    node *temp = new node;
    temp->left = NULL;
    temp->right = NULL;
    temp->ch = c;
    return temp;
}
node *createTree(string expresion)
{
    node *t;
    node *t1;
    node *t2;
    stack<node *> st;
    for (int i = expresion.length() - 1; i >= 0; i--)
    {
        cout << expresion[i] << "\t";
        if (!isOperator(expresion[i]))
        {
            t = newNode(expresion[i]);
            st.push(t);
        }
        else
        {
            t = newNode(expresion[i]);
            t1 = st.top();
            st.pop();
            t2 = st.top();
            st.pop();
            t->left = t1;
            t->right = t2;
            st.push(t);
        }
    }
    t = st.top();
    return t;
}
void postOrder(node *temp)
{
    stack<node *> st1;
    stack<node *> st2;
    st1.push(temp);
    while (!st1.empty())
    {
        node *t = st1.top();
        st2.push(t);

        st1.pop();
        if (t->left != NULL)
        {
            st1.push(t->left);
        }
        if (t->right != NULL)
        {
            st1.push(t->right);
        }
    }
    while (!st2.empty())
    {
        node *t = st2.top();
        cout << t->ch << "\t";
        st2.pop();
    }
    return;
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        cout << root->ch << "\t";
        inorder(root->right);
    }
}
void delete_tree(node *root)
{
    if (root == NULL)
    {

        return;
    }
    else
    {
        cout << "Deleting :- " << root->ch << endl;
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}
int main()
{
    string expression;
    node *root_node;
    cout << "\nEnter the Prefix Expression:- ";
    cin >> expression;
    root_node = createTree(expression);
    cout << "\nTree Created successfully" << endl;
    cout << "\nPost order traversing:- " << endl;
    postOrder(root_node);
    cout << "\n Inorder Traversing:- " << endl;
    inorder(root_node);
    cout << "\n\nDeleting Tree...." << endl;
    delete_tree(root_node);
    cout << "\nDeleted Successfully" << endl;
    return 0;
}
