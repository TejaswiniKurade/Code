#include<bits/stdc++.h>
using namespace std;

class Node{
private:
    Node* left;
    bool lthread;
    int data;
    bool rthread;
    Node* right;
public:
    Node(int val, bool l = 0, bool r = 0){
        this->data = val;
        this->lthread = l;
        this->rthread = r;
        this->left = NULL;
        this->right = NULL;
    }
    friend class ThreadedBinaryTree;
};

class ThreadedBinaryTree{
private:
    Node* Dummy = new Node(-1);
    Node* root;
public:
    ThreadedBinaryTree(){
        Dummy->left = root;
        root = NULL;
    }
    void insert(int );
    void convert();
    void threadedInOrder();
	void threadedInsert(int );
    void Delete(int);
    void print_tree();
};

void ThreadedBinaryTree:: insert(int d){
    Node* ptr = new Node(d);
    if(root == NULL){
        root = ptr;
    }
    else{
        Node* temp = root;
        int choice;
        while(1){
            cout<<"press 0 for inserting as left subtree of "<<temp->data<<endl;
            cout<<"press 1 for inserting as right subtree of "<<temp->data<<endl;
            cin>>choice;
            if(choice == 0){
                if(temp->left == NULL){
                    temp->left = ptr;
                    break;
                }
                else
                    temp = temp->left;
            }
            else{
                if(temp->right == NULL){
                    temp->right = ptr;
                    break;
                }
                else
                    temp = temp->right;
            }
        }
    }
}

void ThreadedBinaryTree::threadedInsert(int d){
	Node* ptr = new Node(d);
	if(root == NULL){
		root = ptr;
		root->left =Dummy;
		root->lthread = 1;
		root->right = Dummy;
		root->rthread = 1;
			
	}
	else{
		Node* temp1;
		Node* temp2;
		int choice;
		temp1 = root;
		temp2 = temp1;
		while(1){
			cout<<"press 0 for inserting as left subtree of "<<temp1->data<<endl;
            cout<<"press 1 for inserting as right subtree of "<<temp1->data<<endl;
            cin>>choice;
			if(choice == 0){
				if(temp1->lthread == 1){
					ptr->left = temp1->left;
					ptr->lthread = 1;
					ptr->right = temp1;
					ptr->rthread = 1;
					temp1->left = ptr;
					temp1->lthread = 0;
					break;
				}
				else{
					temp2 = temp1;
					temp1 = temp1->left;	
				}	
			}
			else{
				if(temp1->rthread == 1){
					ptr->right = temp1->right;
					ptr->rthread = 1;
					ptr->left = temp1;
					ptr->lthread = 1;
					temp1->right = ptr;
					temp1->rthread = 0;	
					break;
				}
				else{
					temp2 = temp1;
					temp1 = temp1->right;
				}		
			}
		}
	}
}

static vector<Node*> v;
void ThreadedBinaryTree::convert(){
    stack< Node*> st;
    Node *curr = root;
 
    while (curr != NULL || st.empty() == false)
    {
        while (curr !=  NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        v.push_back(curr);  
        curr = curr->right;
    }
   
    for(int i = 0; i < v.size(); i++){
        if(i == 0){
            if(v[i]->right == NULL && v[i]->left != NULL){
                v[i]->right = v[i+1];
                v[i]->rthread = 1; //denoting that thread is built.
            }
            if(v[i]->left == NULL && v[i]->right != NULL){
                v[i]->left = Dummy;
                v[i]->lthread = 1; //denoting that thread is built.
            }
            if(v[i]->left == NULL && v[i]->right == NULL){
                v[i]->right = v[i+1];
                v[i]->rthread = 1;//denoting that thread is built.
                v[i]->left = Dummy;
                v[i]->lthread = 1;//denoting that thread is built.
            }
        }
        else if(i == v.size() - 1){
            if(v[i]->right == NULL && v[i]->left != NULL){
                v[i]->right = Dummy;
                v[i]->rthread = 1;//denoting that thread is built.
            }
            if(v[i]->left == NULL && v[i]->right != NULL){
                v[i]->left = v[i-1];
                v[i]->lthread = 1;//denoting that thread is built.
            }
            if(v[i]->left == NULL && v[i]->right == NULL){
                v[i]->left = v[i-1];
                v[i]->lthread = 1;//denoting that thread is built.
                v[i]->right = Dummy;
                v[i]->rthread = 1;//denoting that thread is built.
            }
        }
        else{
            if(v[i]->right == NULL && v[i]->left != NULL){
                v[i]->right = v[i+1];
                v[i]->rthread = 1;//denoting that thread is built.
            }
            if(v[i]->left == NULL && v[i]->right != NULL){
                v[i]->left = v[i-1];
                v[i]->lthread = 1;//denoting that thread is built.
            }
            if(v[i]->left == NULL && v[i]->right == NULL){
                v[i]->left = v[i-1];
                v[i]->lthread = 1;//denoting that thread is built.
                v[i]->right = v[i+1];
                v[i]->rthread = 1;//denoting that thread is built.
            }
            else{// if both not NULL in case of root.
                continue;
            }
        }
    }
}

void ThreadedBinaryTree:: threadedInOrder(){
    Node* temp = root;
    while(temp != Dummy){
        while(!temp->lthread){
            temp = temp->left;
		}
        cout<<temp->data<<" "<<"["<<temp->lthread<<','<<temp->rthread<<"]"<<"  ";
        while(temp->rthread){
            temp = temp->right;
            if(temp == Dummy){
                return;
            }
            cout<<temp->data<<" "<<"["<<temp->lthread<<','<<temp->rthread<<"]"<<"  ";
        }
        temp = temp->right;
    }
}

void ThreadedBinaryTree:: Delete(int data){
            Node *dest = root->left, *p = root;
            while(true)
            {
                if (dest->data < data)
                {
                    /* not found */
                    if (dest->rthread)
                        return;
                    p = dest;
                    dest = dest->right;
                }
                else if (dest->data > data)
                {
                    /* not found */
                    if (dest->lthread)
                        return;
                    p = dest;
                    dest = dest->left;
                }
                else
                {
                    /* found */
                    break;
                }
            }
            Node *target = dest;
            if (!dest->rthread && !dest->lthread)
            {
                /* dest has two children*/
                p = dest;
                /* find largest node at left child */
                target = dest->left;
                while (!target->rthread)
                {
                    p = target;
                    target = target->right;
                }
                /* using replace mode*/
                dest->data = target->data;
            }
            if (p->data >= target->data)
            {
                if (target->rthread && target->lthread)
                {
                    p->left = target->left;
                    p->lthread = true;
                }
                else if (target->rthread)
                {
                    Node *largest = target->left;
                    while (!largest->rthread)
                    {
                        largest = largest->right;
                    }
                    largest->right = p;
                    p->left = target->left;
                }
                else
                {
                    Node *smallest = target->right;
                    while (!smallest->lthread)
                    {
                        smallest = smallest->left;
                    }
                    smallest->left = target->left;
                    p->left = target->right;
                }
            }
            else
            {
                if (target->rthread && target->lthread)
                {
                    p->right = target->right;
                    p->rthread = true;
                }
                else if (target->rthread)
                {
                    Node *largest = target->left;
                    while (!largest->rthread)
                    {
                        largest = largest->right;
                    }
                    largest->right =  target->right;
                    p->right = target->left;
                }
                else
                {
                    Node *smallest = target->right;
                    while (!smallest->lthread)
                    {
                        smallest = smallest->left;
                    }
                    smallest->left = p;
                    p->right = target->right;
                }
            }
}

void ThreadedBinaryTree ::print_tree()
        {
            Node *tmp = root, *p;
            while(true)
            {
                p = tmp;
                tmp = tmp->right;
                if (!p->rthread)
                {
                    while (!tmp->lthread)
                    {
                        tmp = tmp->left;
                    }
                }
                if (tmp == root)
                    break;
                cout<<tmp->data<<"   ";
            }
            cout<<endl;
        }

int main(){
    ThreadedBinaryTree tbst;
    int choice;
	char ch;
	do{
		int flag = 0;
		cout<<"\n\t\tWELCOME TO THREADED BINARY TREE MENU"
			<<"\n\t1.Normal insert."
			<<"\n\t2.Convert (only for option 1)."
			<<"\n\t3.Threaded insert."
			<<"\n\t4.Display Threaded Inorder."
            <<"\n\t5.Delete a Node."
			<<"\n\t6.Exit."
			<<"\n\tChoose : ";
		cin>>choice;
		switch(choice){
			case 1: 
				flag = 1;
				int d;
				cout<<"\nEnter data: ";
				cin>>d; 
				cout<<"\n";
				tbst.insert(d);
				break;
			case 2:
					tbst.convert();
					cout<<"\noperation Successful.";
					break;		
			case 3:
				int d1;
				cout<<"\nEnter data: ";
				cin>>d1;
				cout<<endl;
				tbst.threadedInsert(d1);
				break;
			case 4:
				cout<<"\nThreaded inorder traversal: \n";
				tbst.threadedInOrder();
				break;
			case 5:
                int val;
				cout<<"Enter integer element to delete: ";
                cin>>val;
                tbst.Delete(val);
                break;
            case 6:
                cout<<"\n\tExiting.";
				exit(0);
				break;
			default:
				cout<<"\n\t PLEASE ENTER VALUES BETWEEN 1 TO 5.";
				break;
		}
        
		//cout<<"\n\tDo you want to continue(y/n): ";
		// cin>>ch;
        ch='y';
	}while(ch == 'y' || ch == 'Y');
    cout<<"\nTree = ";
        tbst.print_tree();
return 0;
}




