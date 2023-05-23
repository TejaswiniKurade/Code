#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node *left,*right;
        node(int x){
            this->data=x;
            this->left=NULL;
            this->right=NULL;
        }
};

class binarytree{
    public:
         node *root,*temp;
         binarytree(){
            this->root=NULL;
         }
    int ch;
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
};



int main(){
    binarytree bt;                                              
    int ch;
    char c;
    int a,b,n;
    do{
        
        cout<<"***** binary tree *****"<<endl;
        cout<<"1. Insert element "<<endl;
        cout<<"2. display preorder "<<endl;
        cout<<"3. display inorder "<<endl;
        cout<<"4. display postorder "<<endl;
        cout<<"5. exit " <<endl;
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
                exit(0);
                break;
                
        
        }
        fflush(stdin);
        
    
    }while(1);


   return 0;
}
