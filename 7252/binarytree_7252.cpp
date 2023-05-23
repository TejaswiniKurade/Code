#include<bits/stdc++.h>
using namespace std;

class node{
    int data;
    node *left,*right;
    public:
        node(int x){
            this->data=x;
            this->left=NULL;
            this->right=NULL;
        }
    friend class binarytree;
};

class binarytree{
    node *root,*root1,*temp;
    
    public:
         
         binarytree(){
            this->root=NULL;
         }
    int ch;
    node *get_root(){
        return root;
    }
    
    void insert(int val){
          node *ptr=new node(val);
      
      if(root==NULL){
         root=ptr;
      }
      else{
          temp=root;
          while(1){
              cout<<"Enter 0 to insert the value at left subtree & 1 to insert at right subtree: ";
              cin>>ch;
              if(ch==0){
                  if(temp->left==NULL){
                       temp->left=ptr;
                       break;
                  }
                  else{
                       temp=temp->left;
                  }
              }
              else{
                   if(temp->right==NULL){
                       temp->right=ptr;
                       break;
                  }
                  else{
                       temp=temp->right;
                  }
              }
          }
      }
   }

  void bst_insert(int val){
      node *p=new node(val);
      if(root==NULL){
         root=p; return;
      }
      else{ 
         temp=root;
      }
      while(1){
         if(val<temp->data){
             if(temp->left==NULL){
                temp->left=p;
                break;
             }
             else{
               temp=temp->left;
             }
         }
         else{
             if(temp->right==NULL){
                temp->right=p;
                break;
             }
             else{
               temp=temp->right;
             }
         }
      }
  }

   void preorder_trav(node *root){
       if(root!=NULL){
           cout<<root->data<<" ";
           preorder_trav(root->left);
           preorder_trav(root->right);
       }
       cout<<endl;
   } 
   void preorder(){
      preorder_trav(root);
   }

   void inorder_trav(node *root){
       if(root!=NULL){
          inorder_trav(root->left);
          cout<<root->data<<" ";
          inorder_trav(root->right);
       }
       cout<<endl;
   }
   void inorder(){
       inorder_trav(root);
   }

   void postorder_trav(node *root){
      if(root!=NULL){
          postorder_trav(root->left);
          postorder_trav(root->right);
          cout<<root->data<<" ";
      }
      cout<<endl;
   }
   void postorder(){
       postorder_trav(root);
   }
   
   void levelorder_trav(node *root){
       queue<node *>q;
       q.push(root);
       while(q.size()!=0){
          node *x=q.front();
          q.pop();
              cout<<x->data<<" ";
              if(x->left!=NULL){
                   q.push(x->left);
              }
              if(x->right!=NULL){
                   q.push(x->right);
              }
  
         cout<<endl;
       }
   }
   void levelorder(){
      levelorder_trav(root);
   }

   int high(node *root){
       if(root==NULL){
          return 0;
       }
       else{
          int l=high(root->left);
          int r=high(root->right);
          if(l>r){
            return l+1;
          }
          else{
            return r+1;
          }
       }
   }
   
   void height(){
       int v=high(root);
       cout<<v<<endl;
   }

   node* create_clone(node *root){
      node *x,*y;
      if(root==NULL){
          return NULL;
      }
      else{
         node *p=new node(root->data);
         x=create_clone(root->left);
         y=create_clone(root->right);
         p->left=x;
         p->right=y;
         return p;
      }
   }
  
   node* clone(){
      create_clone(root);
   }


   void it_inorder(node *root){
      stack<node*>st;
      node *x=root;
      while(x!=NULL || !st.empty()){
          while(x!=NULL){
             st.push(x);
             x=x->left;
          }
          x=st.top();
          st.pop();
          cout<<x->data<<" ";
          x=x->right;
      }
      cout<<endl;
   }

   void inorder_1(){
       it_inorder(root);
   }

   void it_preorder(node *root){
      stack<node*>st;
      node *x=root;
      while(x!=NULL || !st.empty()){
          
          while(x!=NULL){
             cout<<x->data<<" ";
             st.push(x);
             x=x->left;
          }
          x=st.top();
          st.pop();
          
          x=x->right;
      }
      cout<<endl;
   }

   void preorder_1(){
       it_preorder(root);
   }


   void it_postorder(node *root){
    stack<node *> s1, s2;
    node *t = NULL;
    s1.push(root);
    while (s1.size() != 0)
    {
        t = s1.top();
        s1.pop();
        s2.push(t);
        if (t->left != NULL)
            s1.push(t->left);
        if (t->right != NULL)
            s1.push(t->right);
    }
    while (s2.size() != 0)
    {
        t = s2.top();
        s2.pop();
        cout << t->data << " ";
    }
}

   void postorder_1(){
       it_postorder(root);
   }


 node* mirr_image(node *root){

    if (root == NULL)
        return NULL;
    node *t = new node(root->data);
    node *x=mirr_image(root->left);
    node *y=mirr_image(root->right);
    t->left=y;
    t->right=x;
    return t;
 }
 node* mirror_image(){
       mirr_image(root);
   }

  bool check_equal(node *root1,node *root2){
      if(root1==root2 && root1==NULL){
         return 1;
      }
      else if(root1==NULL && root2!=NULL){
         return 0;
      }
      else if(root1!=NULL && root2==NULL){
         return 0;
      }
      else{
         if(root1->data==root2->data && check_equal(root1->left,root2->left) && check_equal(root1->right,root2->right)){
               return 1;
         }
         else{
               return 0;
         }
      }
  }
  
void del_bst(int x){
 	if(root->data==x){
 		if(root->left==NULL && root->right==NULL){
 			root=NULL;
 		}
 		else if(root->left!=NULL && root->right==NULL){
 			root=root->left;
 		}
 		else if(root->left==NULL && root->right!=NULL){
 			root=root->right;
 		}
 		else{
 			node* temp=root;
 			node * temp1=temp->right;
	 		node* parent1=temp;
	 		while(temp1->left!=NULL){
	 			parent1=temp1;
	 			temp1=temp1->left;
	 		}
	 		temp->data=temp1->data;
	 		if(temp1->right!=NULL){
	 			if(parent1->left==temp1)
	 			parent1->left=temp1->right;
	 			else parent1->right=temp1->right;
	 		}
	 		else{
	 			if(parent1->left==temp1)
	 			parent1->left=NULL;
	 			else parent1->right=NULL;
	 		}
 		}
 		return;
 	}
 	node* temp=root;
 	node* parent;
 	while(temp->data!=x && temp!=NULL){
 		parent=temp;
 		if(temp->data>x){
 			temp=temp->left;
 		}
 		else temp=temp->right;
 	}
 	if(temp==NULL){cout<<"Value not in tree"<<endl;return;}
 	
 	if(temp->left==NULL && temp->right==NULL){
 		if(parent->left==temp){
 			parent->left=NULL;
 		}
 		else{
 			parent->right=NULL;
 		}
 	}
 	else if(temp->left!=NULL && temp->right==NULL){
 		
 		if(parent->left==temp){
 			parent->left=temp->left;
 		}
 		else{
 			parent->right=temp->left;
 		}
 	}
 	else if(temp->left==NULL && temp->right!=NULL){
 		
 		if(parent->left==temp){
 			parent->left=temp->right;
 		}
 		else{
 			parent->right=temp->right;
 		}
 	}
 	else{
 		node * temp1=temp->right;
 		node* parent1=temp;
 		while(temp1->left!=NULL){
 			parent1=temp1;
 			temp1=temp1->left;
 		}
 		temp->data=temp1->data;
 		if(temp1->right!=NULL){
 			if(parent1->left==temp1)
 			parent1->left=temp1->right;
 			else parent1->right=temp1->right;
 		}
 		else{
 			if(parent1->left==temp1)
 			parent1->left=NULL;
 			else parent1->right=NULL;
 		}
 		
 	}
 	
 
 }

};
 
int main(){
    binarytree bt,bt1;                                        
    int ch,m,val3,val4,size;
    node* copy = NULL;
    char c;
    int a,b,n,key=0,x;
    int In_array[1000];
    int Pre_array[1000];
    node* xz;
    do{
        
        cout<<"***** binary tree *****"<<endl;
        cout<<"1. Insert element "<<endl;
        cout<<"2. display preorder "<<endl;
        cout<<"3. display inorder "<<endl;
        cout<<"4. display postorder "<<endl;
        cout<<"5. display levelorder "<<endl;
        cout<<"6. height "<<endl;
        cout<<"7. clone "<<endl;
        cout<<"8. iterative inorder "<<endl;
        cout<<"9. iterative preorder "<<endl;
        cout<<"10. iterative postorder "<<endl;
        cout<<"11. mirror image "<<endl;
        cout<<"12. Two trees are equal or not?  "<<endl;
        cout<<"13. Binary search tree insertion  "<<endl;
        cout<<"14. delete a node"<<endl;
        cout<<"15. exit " <<endl;
        cout<<"enter your choice = ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"element to be inserted: ";
                cin>>n;
                cout<<"Enter the root value: ";
                cin>>a;
                bt.insert(a);
                for(int i=0;i<n-1;i++){
                    cout<<"enter value = ";
                    cin>>b;
                    bt.insert(b);
                    
                }
                break;
                
            case 2:
                cout<<"Preorder traversal"<<endl;
                bt.preorder();
                break;
                
            case 3:
                cout<<"Inorder traversal"<<endl;
                bt.inorder();
                break;
                
            case 4:
                cout<<"Postorder traversal"<<endl;
                bt.postorder();
                break;

           case 5:
                cout<<"level order traversal"<<endl;
                bt.levelorder();
                break;
 
           case 6:
                cout<<"Height of the tree is"<<endl;
                bt.height();
                break;

           case 7:
                cout<<"cloning"<<endl;
                bt.preorder_trav(bt.clone());
                break;

           case 8:
                cout<<"iterative inorder"<<endl;
                bt.inorder_1();
                break;

           case 9:
                cout<<"iterative preorder"<<endl;
                bt.preorder_1();
                break;

           case 10:
                cout<<"iterative postorder"<<endl;
                bt.postorder_1();
                break;

          case 11:
                cout<<"mirror image"<<endl;
                bt.preorder_trav(bt.mirror_image());
                break;
        
          case 12:
                cout << "Identical or not" << endl;
            cout << "elements to be inserted: ";
            cin >> m;
            cout << endl;
            cout << "Enter the root value: ";
            cin >> val3;
            bt1.insert(val3);
            for (int i = 0; i < m - 1; i++)
            {
                cout << "Enter the value: ";
                cin >> val4;
                bt1.insert(val4);
            }
            cout << bt.check_equal(bt.get_root(), bt1.get_root());
            cout<<endl;break;

          case 13:
                cout<<"Binary search tree insertion"<<endl;
                cout<<"element to be inserted: ";
                cin>>n;
                cout<<"Enter the root value: ";
                cin>>a;
                bt.bst_insert(a);
                for(int i=0;i<n-1;i++){
                    cout<<"enter value = ";
                    cin>>b;
                    bt.bst_insert(b);
                    
                }
                break;

          case 14:
                cout<<"to delete an elemnt"<<endl;
			    cin>>key;
			    bt.del_bst(key);
			    bt.preorder();
	            break;
	           
           case 15:
                exit(0);
                break;
                
        
        }
        
    
    }while(1);


   return 0;
}
