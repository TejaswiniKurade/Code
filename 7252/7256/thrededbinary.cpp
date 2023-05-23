#include <bits/stdc++.h>
using namespace std;
int MAX_VALUE=66666666;
int n=0;	

class Node
{
	public:
        int key;
        Node *left, *right;
        bool leftThread, rightThread;
        
        Node(){
        left=NULL;
        right=NULL;
        key=0;
        leftThread=false;
        rightThread=false;
        }
};

class ThreadedBinarySearchTree
{
	private:
        Node *root;
    	Node *rooot;
        Node *arr[1000000];
        int i=1;      
    public:
        ThreadedBinarySearchTree()
        {
            root = new Node();
            root->right = root->left = root;
            root->leftThread = true;
            root->key = MAX_VALUE;
        }

        void makeEmpty()
        {
            root = new Node();
            root->right = root->left = root;
            root->leftThread = true;
            root->key = MAX_VALUE;
        }
        
        void insert(int key)
        { 
            Node *p = root;
            while(true)
            {
            	
                if (p->key < key)
                {
                    if (p->rightThread)
                        break;
                    p = p->right;
                }
                else if (p->key > key)
                {
                	
                    if (p->leftThread)
                        break;
                    p = p->left;
                }
                else
                {
                    return;
                }
            }
            Node *tmp = new Node();
            tmp->key = key;
            tmp->rightThread = tmp->leftThread = true;
            if (p->key < key)
            {
                tmp->right = p->right;
                tmp->left = p;
                p->right = tmp;
                p->rightThread = false;
            }
            else
            {
                tmp->right = p;
                tmp->left = p->left;
                p->left = tmp;
                p->leftThread = false;
            }
        }

        bool search(int key)
        {
            Node *tmp = root->left;
            while (true)
            {
                if (tmp->key < key)
                {
                    if (tmp->rightThread)
                        return false;
                    tmp = tmp->right;
                }
                else if (tmp->key > key)
                {
                    if (tmp->leftThread)
                        return false;
                    tmp = tmp->left;
                }
                else
                {
                    return true;
                }
            }
        }

        void Delete(int key)

        {

            Node *dest = root->left, *p = root;

            for (;;)

            {

                if (dest->key < key)

                {

                    /* not found */

                    if (dest->rightThread)

                        return;

                    p = dest;

                    dest = dest->right;

                }

                else if (dest->key > key)

                {

                    /* not found */

                    if (dest->leftThread)

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

            if (!dest->rightThread && !dest->leftThread)

            {

                /* dest has two children*/

                p = dest;

                /* find largest node at left child */

                target = dest->left;

                while (!target->rightThread)

                {

                    p = target;

                    target = target->right;

                }

                /* using replace mode*/

                dest->key = target->key;

            }

            if (p->key >= target->key)

            {

                if (target->rightThread && target->leftThread)

                {

                    p->left = target->left;

                    p->leftThread = true;

                }

                else if (target->rightThread)

                {

                    Node *largest = target->left;

                    while (!largest->rightThread)

                    {

                        largest = largest->right;

                    }

                    largest->right = p;

                    p->left = target->left;

                }

                else

                {

                    Node *smallest = target->right;

                    while (!smallest->leftThread)

                    {

                        smallest = smallest->left;

                    }

                    smallest->left = target->left;

                    p->left = target->right;

                }

            }

            else

            {

                if (target->rightThread && target->leftThread)

                {

                    p->right = target->right;

                    p->rightThread = true;

                }

                else if (target->rightThread)

                {

                    Node *largest = target->left;

                    while (!largest->rightThread)

                    {

                        largest = largest->right;

                    }

                    largest->right =  target->right;

                    p->right = target->left;

                }

                else

                {

                    Node *smallest = target->right;

                    while (!smallest->leftThread)

                    {

                        smallest = smallest->left;

                    }

                    smallest->left = p;

                    p->right = target->right;

                }

            }

        }
        void in_order(){
        
		 	if(rooot==NULL)return;
		 	Node *temp=rooot;
		 	rooot=rooot->left;
		 	in_order();
		 	arr[i]=temp;
            i++;
            n++;
		 	cout<<temp->key<<" ";
		 	rooot=temp->right;
		 	in_order();
		 	rooot= temp;
		 	
 		}
        void Convert_BST_THBST(int n)
        {       
            Node *t=arr[1];
            t->left=root;
            t->right=arr[1];
            
            for(int i=2;i<=n-1;i++){
            	Node *tt=arr[i];
            	if(tt->rightThread==true)
            		tt->right=arr[i+1];
            	if(tt->leftThread==true)
            		tt->left=arr[i-1];
            }
            
            Node *ta=arr[n];
            ta->left=arr[n-1];
            ta->right=root;
        }
        
        void inorder(){
        	Node *tmp=root,*p;
        	
        	//cout<<tmp->key<<endl;
        	while(true){
        	
        		p=tmp;
        		tmp=tmp->right;
        		if(!p->rightThread){
        			while(!tmp->leftThread){
        				tmp=tmp->left;
        			}
        		}
        		if(tmp == root ) break;
        		cout<<tmp->key<<" ";
        	}
        	cout<<endl;
        }
        
          void printTree()
        {
            Node *tmp = root, *p;
            while (true)
            {
                p = tmp;
                tmp=tmp->right;
                if (!p->rightThread)
                {
                    while (!tmp->leftThread)
                    {
                        tmp = tmp->left;
                    }
                }
                if (tmp == root)
                    break;
                    arr[i]=tmp;
                 
                cout<<tmp->key<<"   ";
            }
            cout<<endl;
        }
        
        
          void insert_BST(int val){
			 	Node *x=new Node();
			 	x->key=val;
			 	 		 	
			 	if(root==NULL){
			 	cout<<val<<" inserted at root"<<endl;
			 		root=x;return;
			 	}
			 	if(!root->leftThread){
			 		rooot=root->left;
			 	}
			 	else if(!root->rightThread){
			 		rooot=root->right;
			 	}
			 	 Node * temp=root;
			// cout<<temp->key<<"...."<<endl;
			 	 while(true){
			 	 	// cout<<">>>///>"<<endl;	
			 	 	if(temp->key>val){
			 	 		if(temp->leftThread==true){
			 	 			temp->leftThread=false;
			 	 			temp->left=x;return;
			 	 		}
				 		temp=temp->left;
			 	 	}
			 	 	else{
			 	 		if(temp->rightThread==true){
			 	 			temp->rightThread=false;
			 	 			temp->right=x;return;
			 	 		}
			 	 		temp=temp->right;
			 	 	}
 				 }
 				// cout<<">>>>"<<endl;
 
 			}
 
};

int main()
{
    ThreadedBinarySearchTree tbst;
    cout<<"ThreadedBinarySearchTree Test\n";
    char ch;
    int choice, val;
    do
    {
        cout<<"\nThreadedBinarySearchTree Operations\n";
        cout<<"1. Insert value to form THBST "<<endl;
        cout<<"2. Print Threaded Binary Search tree : "<<endl;
        cout<<"3. Insert value to form BST "<<endl;
		cout<<"4. Convert BST TO THBST "<<endl;
        cout<<"5. Delete"<<endl;
        cout<<"6. Search"<<endl;
        cout<<"7. Clear"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1 :
            cout<<"Enter integer element to insert in threaded binary tree: ";
            cin>>val;
            tbst.insert(val);
            break;
        case 2:
        	 tbst.inorder();
        	 break;
        	 
        case 3:
        	cout<<"Enter integer element to insert in binary search tree: ";
            cin>>val;
            tbst.insert_BST(val);
            break;
        case 4:
        	 tbst.in_order();
        	 tbst.Convert_BST_THBST(n);
        	 tbst.printTree();
        	 break;
        case 5 :
            cout<<"Enter integer element to delete: ";
            cin>>val;
            tbst.Delete(val);
            break;

        case 6 :
            cout<<"Enter integer element to search: ";
            cin>>val;
            if (tbst.search(val) == true)
                cout<<"Element "<<val<<" found in the tree"<<endl;
            else
                cout<<"Element "<<val<<" not found in the tree"<<endl;
            break;

        case 7 :
            cout<<"\nTree Cleared\n";
            tbst.makeEmpty();
            break;

        default :
            cout<<"Wrong Entry \n ";
            break;
        }
        cout<<"\nDo you want to continue (Type y or n): ";
        cin>>ch;
    } while (ch == 'Y'|| ch == 'y');
    
    return 0;

}

    
