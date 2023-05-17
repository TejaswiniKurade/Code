#include<bits/stdc++.h>
using namespace std;

class node{
    
    public:
       int data;
       node *left,*right;
       node(){
          this->left=NULL;
          this->right=NULL;
       }
       node(int x){
          this->data=x;
          this->left=NULL;
          this->right=NULL;
       }
 
};

class Binary_tree{
    
    public:
        node *root,*temp,*root1;
        Binary_tree(){
           root=NULL;
        }
        
        node* get_root()
        {
            return root;
        }
        void create(int val){
            node* New=new node();
            if(!New){
                cout << "Memory error\n";
                New=NULL;
            }
            New->data=val;
            New->left=NULL;
            New->right=NULL;
            root=New;
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
           
        }

       
       
        
        void inorder_traverse(node *root){
           if(root!=NULL){
                inorder_traverse(root->left);
                cout<<root->data<<" ";
                inorder_traverse(root->right);
           }
           
        }

        
        
        
        void postorder_traverse(node *root){
            if(root!=NULL){
                postorder_traverse(root->left);
                postorder_traverse(root->right);
                cout<<root->data<<" ";
                
            }
            
        }
       
       
        
        void level_order_traverse(node *root){
            queue<node*> q;
            q.push(root);
            node *x;
            while(!q.empty()){
               x=q.front();
               if(x->left!=NULL){
                   q.push(x->left);
               }
               if(x->right!=NULL){
                   q.push(x->right);
               }
               cout<<x->data<<" ";
               q.pop();
            }
                  
        }

         void preorder1(){
            preorder_traverse(root);
        }
        void postorder1(){
           postorder_traverse(root);
       }
       void inorder1(){
            inorder_traverse(root);
        }
        void level1(){
            level_order_traverse(root);
        }
       
        
        
        
        

        //iterative
        void preorder2(){
 	        node *T = root;
 	        stack<node *>stk;
 	        while(T!=NULL || !stk.empty()){
 		        while(T!=NULL){
 			    stk.push(T);
 			    cout<<T->data<<" ";
 			    T=T->left;
 		        }
 		        T=stk.top();
 		        stk.pop();
 		
 		        T=T->right;
 	        }
 	        cout<<endl;
 	
        }
        
        void inorder2(){
 	        node *T = root;
 	        stack<node *>stk;
 	         while(T!=NULL || !stk.empty()){
 		        while(T!=NULL){
 			        stk.push(T);
 			        T=T->left;
 		        } 
 		        T=stk.top();
 		        stk.pop();
 		
 		        cout<<T->data<<" ";
 		
 		        T=T->right;
 	        }
 	        cout<<endl;
 	
        }

        void postorder2(){
 	        node *T = root;
 	        stack<node *>stk,stk1;
 	        stk.push(T);
 	        while(!stk.empty()){
 		        T=stk.top();
 		        stk.pop();
 		        stk1.push(T);
 		        if(T->left!=NULL){
 			        stk.push(T->left);
 		        }
 		        if(T->right!=NULL){
 			        stk.push(T->right);
 		        }
 	        }
 	        while(!stk1.empty()){
 		        cout<<stk1.top()->data<<" ";
 		        stk1.pop();
 	        }
 	
 	
        }

        
        
        int height_tree(node *root){
            if(root==NULL){
               return 0;
            }
            else{
               int l=height_tree(root->left);
               int r=height_tree(root->right);
               return max(l,r)+1;
            }
        }
        
        void height(){
           int len=height_tree(root);
           cout<<len;
        }
        
        
      
        
        node* create_clone(node* root){
            //int x,y;
            if(root==NULL){
                return 0;
            }
            else{
                node* p=new node(root->data);
                node* x=create_clone(root->left);
                node* y=create_clone(root->right);
               p->left=x;
               p->right=y;
              
               return p;
            }
        
        }
        
        node* clone(){
           
           create_clone(root);
           
          
        }
        
        
        node* mirror_image(node* root){
             if(root==NULL){
                return 0;
            }
            else{
                node* p=new node(root->data);
                node* x=mirror_image(root->left);
                node* y=mirror_image(root->right);
                p->left=y;
                p->right=x;
                
               return p;
            }
        
        }
        
        node* mirror(){
            mirror_image(root);
            
        }
        
        
        bool check(node* root,node* root2){
            int x=0,y=0;
            if(root==root2 && root==NULL){
                return 1;
            }
            else if(root==NULL && root2!=NULL){
                return 0;
            }
            else if(root!=NULL && root2==NULL){
                return 0;
            }
            else{
             
                if(root->data==root2->data){
                    x=check(root->left,root2->left);
                    if(x==1){
                    
                        y=check(root->right,root2->right);
                        if(y==1){
                             return 1;
                        }
                    }
                }
                else{
                    return 0;
                }
            }
        
        
        }
        
       
       node* solve(vector<int> in,vector<int> pre,int &index,int inorderstart,int inorderend,int n,map<int,int>& mp){
		if(index>=n || 	inorderstart>inorderend){
			return NULL;
		}                                       
		int element =pre[index++];
		node* root=new node(element);
		int position=mp[element];
		root->left=solve(in,pre,index,inorderstart,position-1,n,mp);
		root->right=solve(in,pre,index,position+1,inorderend,n,mp);
	
	return root;}
		node* solve1(vector<int> in,vector<int> post,int &index,int inorderstart,int inorderend,int n,map<int,int>& mp){
		if(index<0 || 	inorderstart>inorderend){
			return NULL;
		}                                       
		int element =post[index--];
		node* root=new node(element);
		int position=mp[element];
		root->right=solve(in,post,index,position+1,inorderend,n,mp);
		root->left=solve(in,post,index,inorderstart,position-1,n,mp);
	
	return root;}
        
 

  


};




int main(){
    Binary_tree bt,bt2;
    node* root2;
    
    int cho;
    char ch;
    int val,val2,n,m,val1,x,index,key;
    map<int,int> mp;
    vector<int> pre,in,post;
    do{
        cout<<"***** binary tree *****"<<endl;
        cout<<"1. Create binary tee "<<endl;
        cout<<"2. Insert element "<<endl;
        cout<<"3. Recursive Traversal"<<endl;
        cout<<"4. Iterative Traversal"<<endl;
        cout<<"5. Height of binary tree"<<endl;
        cout<<"6. Check if two trees are same or not"<<endl;
        cout<<"7. Mirror image"<<endl;
        cout<<"8. Clone"<<endl;
        cout<<"9. Create a tree from inorder and preorder"<<endl;
        cout<<"10. Create a tree from inorder and postorder " <<endl;
        cout<<"11. EXIT"<<endl;
        cout<<"enter your choice = ";
        cin>>cho;
        switch(cho){
        
        
            case 1: 
                cout<<"Enter root of tree = ";
                cin>>val;
                bt.create(val);
                break;
                
            case 2:
                cout<<"Number of elements you want to insert = ";
                cin>>n;
                //cout<<"enter value = ";
                //cin>>val;
                //bt.insert(val);
                for(int i=0;i<n;i++){
                    cout<<"enter value = ";
                    cin>>val2;
                    bt.insert(val2);
                    
                }
                break;
                
            case 3:
                cout<<"traversal"<<endl;
                cout<<"1. Inorder traversal =  ";
                bt.inorder1();
                cout<<endl;
                cout<<"2. Preorder traversal = ";
                bt.preorder1();
                cout<<endl;
                cout<<"3. Postorder traversal = ";
                bt.postorder1();
                cout<<endl;
                cout<<"4. Level order traversal = ";
                bt.level1();
               
                cout<<endl;
                break;
                
            case 4:
                cout<<"traversal"<<endl;
                cout<<"1. Inorder traversal = ";
                bt.inorder2();
                cout<<endl;
                cout<<"2. Preorder traversal = ";
                bt.preorder2();
                cout<<endl;
                cout<<"3. Postorder traversal = ";
                bt.postorder2();
                cout<<endl;
                cout<<"4. Level order traversal = ";
                bt.level1();
               
                cout<<endl;
                break;
           
                
            case 5:
                cout<<"Height of tree is = ";
                bt.height();
                cout<<endl;
                break;
                
            case 6:
                cout<<"Enter root of tree = ";
                cin>>val1;
                bt2.create(val1);
                cout<<"Number of elements you want to insert = ";
                cin>>m;
                
                for(int i=0;i<m;i++){
                    cout<<"enter value = ";
                    cin>>val2;
                    bt2.insert(val2);
                    
                }

                //int chk=check(bt.get_root(),bt2.get_root());
                if(bt.check(bt.get_root(),bt2.get_root())){
                    cout<<"Both trees are same"<<endl;
                }
                else{
                    cout<<"Trees are not same"<<endl;
                }
      
                break;
                
            case 7:
                cout<<"mirror of the binary tree"<<endl;
                bt.preorder_traverse(bt.mirror());
                cout<<endl;
                break;
                
            case 8:
                cout<<"clone of the binary tree"<<endl;
                bt.preorder_traverse(bt.clone());
                cout<<endl;
                break;
                
            case 9:
                cout<<"create a binary tree from preorder and inorder"<<endl;
		        cout<<"Enter the number of nodes in the tree"<<endl;
			    cin>>n;
		        cout<<"Enter the preorder array nodes"<<endl;
		
		        for(int i=0;i<n;i++){
			        cin>>x;
			        pre.push_back(x);
			    }
	               cout<<"Enter the inorder array nodes"<<endl;
	            for(int i=0;i<n;i++){
			        cin>>x;
			        in.push_back(x);
			    }
			    for(int i=0;i<n;i++){
				    mp[in[i]]=i;
			    }
			    index=0;
			    bt.postorder_traverse( bt.solve(in,pre,index,0,n-1,n,mp));
                cout<<endl;
                break;

            case 10:
                cout<<"create a binary tree from postorder and inorder"<<endl;
		        cout<<"Enter the number of nodes in the tree"<<endl;
			    cin>>n;
		        cout<<"Enter the postorder array nodes"<<endl;
		
		        for(int i=0;i<n;i++){
			        cin>>x;
			        post.push_back(x);
			    }
	            cout<<"Enter the inorder array nodes"<<endl;
	             for(int i=0;i<n;i++){
			            cin>>x;
			        in.push_back(x);
			    }
			    for(int i=0;i<n;i++){
				    mp[in[i]]=i;
			    }
			    index=n;
			    bt.preorder_traverse(bt.solve1(in,post,index,0,n-1,n,mp));
 			    cout<<endl;
                break;

            case 11:
                exit(0);
                break;
                
        
        
        }
        
    
    }while(cho!=11);


   return 0;
}
