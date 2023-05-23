#include <bits/stdc++.h>
#include <cstdlib>
#define MAX_VALUE 1e9
using namespace std;


class Node
{
	public:
        int key;
        Node *left, *right;
        bool leftThread, rightThread;
};

class ThreadedBinarySearchTree{
	private:
        Node *root;
    public:
        ThreadedBinarySearchTree(){
            root = new Node();
            root->right = root->left = root;
            root->leftThread = true;
            root->key = MAX_VALUE;
        }
        
        void insert(int key);
        bool search(int key);
        void inorder();
        void Delete(int key);
        void convert();
        void bst_insert(int val);
};

void ThreadedBinarySearchTree :: convert(){
	
	vector<Node*>vec;
	
	Node *T = root->left;
 	stack<Node *>stk;
 	int ct=0;
 	while(T!=NULL || !stk.empty()){
 		while(T!=NULL){
 			stk.push(T);
 			T=T->left;
 		}
 		T=stk.top();
 		stk.pop();
 		
 		vec.push_back(T);
 		
 		T=T->right;
 		ct++;

 	}
 	
 	int n = vec.size();
 	
 	Node * t = vec[0];
 	t->left=root;
 	t->leftThread=true;
 	t=vec[n-1];
 	t->right=root;
 	t->rightThread=true;
 	
 	root->leftThread = false;
 	
 	for(int i =0 ;i<n;i++){
 		Node * t = vec[i];
 		
 		if(i)
 		if(t->left==NULL){
 			t->left=vec[i-1];
 			t->leftThread=true;
 		}
 		else{
 			t->leftThread=false;
 		}
 		
 		if(i!=n-1)
 		if(t->right==NULL){
 			t->right=vec[i+1];
 			t->rightThread=true;
 		}
 		else{
 			t->rightThread=false;
 		}
 	}
 	
 	
 
}

void ThreadedBinarySearchTree :: bst_insert (int val){

	Node *p = root;
	
	if(p->left==p){
		//first insertion
		 Node *tmp = new Node();
    	tmp->left=NULL;tmp->right=NULL;
    	tmp->key = val;
    	p->left=tmp;return;
		
	}
	
        while(true){
            if (p->key < val){
                if (p->right==NULL)
                    break;
                p = p->right;
            }
            else if (p->key > val){
                if (p->left==NULL)
                    break;
                p = p->left;
            }
            else{
                return;
            }
        }
        
    Node *tmp = new Node();
    tmp->left=NULL;tmp->right=NULL;
    tmp->key = val;
    
    if (p->key < val){
      //  tmp->right = p->right;
       // tmp->left = p;
        p->right = tmp;
       // p->rightThread = false;
    }
    else{
        //tmp->right = p;
        //tmp->left = p->left;
        p->left = tmp;
        //p->leftThread = false;
    }
	
}


void ThreadedBinarySearchTree :: insert(int key){
        Node *p = root;
        while(true){
            if (p->key < key){
                if (p->rightThread)
                    break;
                p = p->right;
            }
            else if (p->key > key){
                if (p->leftThread)
                    break;
                p = p->left;
            }
            else{
                return;
            }
        }
        
    Node *tmp = new Node();
    tmp->key = key;
    tmp->rightThread = tmp->leftThread = true;
    
    if (p->key < key){
        tmp->right = p->right;
        tmp->left = p;
        p->right = tmp;
        p->rightThread = false;
    }
    else{
        tmp->right = p;
        tmp->left = p->left;
        p->left = tmp;
        p->leftThread = false;
    }
}


bool ThreadedBinarySearchTree :: search(int key){
    Node *tmp = root->left;
    while(true){
        if (tmp->key < key){
            if (tmp->rightThread)
                return false;
            tmp = tmp->right;
        }
        else if (tmp->key > key){
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

void ThreadedBinarySearchTree :: inorder(){
    Node *tmp = root, *p;
    while(true){
        p = tmp;
        tmp = tmp->right;
        if (!p->rightThread){
            while (!tmp->leftThread){
                tmp = tmp->left;
            }
        }
        if (tmp == root)break;
        cout<<tmp->key<<"   ";
    }
    cout<<endl;
}


void ThreadedBinarySearchTree :: Delete(int key){
    Node *dest = root->left, *p = root;

    while(true){
        if (dest->key < key){
            if (dest->rightThread)
                return;
            p = dest;
            dest = dest->right;
        }
        else if (dest->key > key){
            if (dest->leftThread)return;
            p = dest;
            dest = dest->left;
        }
        else{
            break;
        }
    }

    Node *target = dest;
    if (!dest->rightThread && !dest->leftThread){
        p = dest;
        target = dest->left;
        while (!target->rightThread) {
            p = target;
            target = target->right;
        }
        dest->key = target->key;
    }
    
    if (p->key >= target->key){
        if (target->rightThread && target->leftThread){
            p->left = target->left;
            p->leftThread = true;
        }
        else if (target->rightThread)  {
            Node *largest = target->left;
            while (!largest->rightThread)  {
                largest = largest->right;
            }
            largest->right = p;
            p->left = target->left;
        }
        else{
            Node *smallest = target->right;
            while (!smallest->leftThread){
                smallest = smallest->left;
            }
            smallest->left = target->left;
            p->left = target->right;
        }
    }
    else{
        if (target->rightThread && target->leftThread){
            p->right = target->right;
            p->rightThread = true;
        }

        else if (target->rightThread) {

            Node *largest = target->left;
            while (!largest->rightThread){
                largest = largest->right;
            }
            largest->right =  target->right;
            p->right = target->left;
        }
        else{
            Node *smallest = target->right;
            while (!smallest->leftThread){
                smallest = smallest->left;
            }
            smallest->left = p;
            p->right = target->right;
        }
    }
}


int main(){
    ThreadedBinarySearchTree tbst,bst;

    char ch;
    int choice, val;

    do{
        cout<<"\nMENU\n";
        cout<<"1. Insert "<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Search"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Convert"<<endl;
        cout<<"6. BST insert"<<endl;
        cout<<"7. exit"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;
        switch (choice){
        case 1 :
            cout<<"Enter integer element to insert: ";
            cin>>val;
            tbst.insert(val);
            break;
        case 2 :
            cout<<"Enter integer element to delete: ";
            cin>>val;
            tbst.Delete(val);
            break;
        case 3 :
            cout<<"Enter integer element to search: ";
            cin>>val;
            if (tbst.search(val) == true)
            cout<<"Element "<<val<<" found in the tree"<<endl;
            else cout<<"Element "<<val<<" not found in the tree"<<endl;
            break;
        case 4 :
            cout<<"\nInorder: ";tbst.inorder();
            break;
        case 5:
        	tbst.convert();
        	break;
        case 6:
        	cout<<"Enter integer element to insert: ";
            cin>>val;
        	tbst.bst_insert(val);break;
        case 7: exit(0);
        default :
            cout<<"Wrong Entry \n ";
            break;
        }
        
    }while (true);


}



