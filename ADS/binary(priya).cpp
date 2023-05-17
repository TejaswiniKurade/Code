#include<bits/stdc++.h>
using namespace std;

class node{
    
    public:
       int data;
       node *left,*right;

       node(int x)
       {
          this->data=x;
          this->left=NULL;
          this->right=NULL;
       }
 
};

class Binary_tree{
    
    public:
        node *root,*temp;
        Binary_tree(){
           root=NULL;
        }
        
        void insert(int val){
            node *p=new node(val);
            int ch;
            if(root==NULL){
                root=p;
            }
            else{
                temp=root;
                
                while(1){
                    cout<<"Press 1 for inserting in right sub-tree and 0 for left-tree of "<<temp->data<<" = ";
                    cin>>ch;
                    if(ch==0){
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
            
            
        
        }
    
        void preorder_traverse(node *root){
           if(root!=NULL){
                cout<<root->data<<" ";
                preorder_traverse(root->left);
                preorder_traverse(root->right);
           }
           cout<<endl;
        }
        void preorder(){
            preorder_traverse(root);
        }
        void inorder_traverse(node *root){
           if(root!=NULL){
                inorder_traverse(root->left);
                cout<<root->data<<" ";
                inorder_traverse(root->right);
           }
           cout<<endl;
        }
        void inorder(){
            inorder_traverse(root);
        }
        void postorder_traverse(node *root){
            if(root!=NULL){
                postorder_traverse(root->left);
                postorder_traverse(root->right);
                cout<<root->data<<" ";
                
            }
            cout<<endl;
        }
        void postorder(){
            postorder_traverse(root);
        }


};


int main(){
    Binary_tree bt;
    int cho;
    char ch;
    int val,val2,n;
    do{
        cout<<"***** BINARY TREE *****"<<endl;
        cout<<endl;
        cout<<"1. Insert element "<<endl;
        cout<<"2. Preorder "<<endl;
        cout<<"3. Inorder "<<endl;
        cout<<"4. Postorder "<<endl;
        cout<<"5. exit " <<endl;
        cout<<"enter your choice = ";
        cin>>cho;
        cout<<endl;
        switch(cho){
            case 1:
                cout<<"Number of elements you want to insert = ";
                cin>>n;
                cout<<"enter root value = ";
                cin>>val;
                bt.insert(val);
                for(int i=0;i<n-1;i++){
                    cout<<"enter value = ";
                    cin>>val2;
                    bt.insert(val2);
                    
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
        
    
    }while(cho!=5);


   return 0;
}
