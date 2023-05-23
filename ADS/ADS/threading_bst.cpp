#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

class node
{
    int data;
    bool lthread;
    bool rthread;
    node *llink;
    node *rlink;

public:
    node()
    {
        data = -1;
        lthread = 1;
        rthread = 1;
        llink = NULL;
        rlink = NULL;
    }
    node(int d)
    {
        data = d;
        lthread = 1;
        rthread = 1;
        llink = NULL;
        rlink = NULL;
    }
    node(node *dm)
    {
        data = MAX;
        lthread = 1;
        rthread = 1;
        llink = NULL;
        rlink = dm;
    }
    friend class threaded_binary;
};

class threaded_binary
{
    node *root;
    node *dummy = new node(dummy);

public:
    threaded_binary()
    {
        dummy->llink = root;
        root = NULL;
    }
    void insert_tbt(int val);
    void inorder(node *root);
    void inorder();
    void delete_tbt(int val);
    node *getDummy() const { return dummy; }
};

void threaded_binary::insert_tbt(int val)
{
    if (root == NULL)
    {
        root = new node(val);
        root->lthread = 1;
        root->rthread = 1;
        root->llink = dummy;
        root->rlink = dummy;
    }
    else
    {
        node *temp = root;
        node *tempf = temp;
        while (1)
        {
            if (val < temp->data)
            {
                if (temp->lthread == 1)
                {
                    break;
                }
                else
                {
                    tempf = temp;
                    temp = temp->llink;
                }
            }
            else
            {
                if (temp->rthread == 1)
                {
                    break;
                }
                else
                {
                    tempf = temp;
                    temp = temp->rlink;
                }
            }
        }
        node *my_node = new node(val);
        if (val < temp->data)
        {
            my_node->llink=temp->llink;
            my_node->rlink=temp;
            temp->llink = my_node;
            tempf->lthread = 0;
        }
        else
        {
            
            my_node->rlink=temp->rlink;
            my_node->llink=temp;
            temp->rlink = my_node;
            tempf->rthread = 0;
        }
    }
}

void threaded_binary::inorder()
{
    node* currentNode =root;
    if (currentNode == nullptr)
        return;
    while (currentNode->lthread == 0)
        currentNode = currentNode->llink;

    while (currentNode != getDummy())
    {
        cout << currentNode->data << " ";

        if (currentNode->rthread)
            currentNode = currentNode->rlink;

        else
        {
            currentNode = currentNode->rlink;
            while (currentNode->lthread == 0)
                currentNode = currentNode->llink;
        }
    }
}

void threaded_binary:: delete_tbt(int val)
{
    node *temp=root,*tempf=temp;
    while(1)
    {
        if (val < temp->data)
        {
            if (temp->lthread == 1)
            {
                break;
            }
            else
            {
                tempf = temp;
                temp = temp->llink;
            }
        }
        else
        {
            if (temp->rthread == 1)
            {
                break;
            }
            else
            {
                tempf = temp;
                temp = temp->rlink;
            }
        }
    }
    if (!temp->rthread && !temp->lthread)
    {
       
    }

}


int main()
{
    threaded_binary th;
    th.insert_tbt(10);
    th.insert_tbt(15);
    th.insert_tbt(5);
    th.insert_tbt(4);
    th.inorder();
}