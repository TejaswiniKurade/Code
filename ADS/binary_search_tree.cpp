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

class search_tree{
     
    public:
       node* root;
       search_tree(){
          root=NULL;
       }
       
       node* get_root()
        {
            return root;
        }
       void create_search(int val){
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
        
       void insert_search(int val){
           node *p=new node(val);
          
              if(root==NULL){
                  root=p;
              }
              else{
                
                  node *t=root;
                while(1){
                  if(val<t->data){
                      if(t->left==NULL){
                         t->left=p;
                         break;
                         //return;
                      }
                      else{
                         t=t->left;
                      }
                      
                  }
                  else{
                      if(t->right==NULL){
                         t->right=p;
                         break;
                         //return;
                      }
                      else{
                         t=t->right;
                      }
                  }
                  
                 }
               
              }
           
           


       }
       
       
       void inorder_traverse(node *root_s){
           if(root_s!=NULL){
                inorder_traverse(root_s->left);
                cout<<root_s->data<<" ";
                inorder_traverse(root_s->right);
           }
           
        }
        
        
        void preorder_traverse(node *root_s){
           if(root_s!=NULL){
                cout<<root_s->data<<" ";
                preorder_traverse(root_s->left);
                preorder_traverse(root_s->right);
           }
           
        }
        
        void postorder_traverse(node *root_s){
            if(root_s!=NULL){
                postorder_traverse(root_s->left);
                postorder_traverse(root_s->right);
                cout<<root_s->data<<" ";
                
            }
            
        }
 
        void level_order_traverse(node *root_s){
            queue<node*> q;
            q.push(root_s);
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
 			//if(parent1->left==temp1)
 			//parent1->left=NULL;
 			 parent1->right=NULL;
 		}
 		
 	}
 	
 
 }

};




        
        







int main(){
   
    search_tree bt,bt2;
    node* root2;
    int cho;
    char ch;
    int val,val2,n,val3,m,x,index,key,val1;
    
    do{
       cout<<"***** binary tree *****"<<endl;
        cout<<"1. Create binary Search tee "<<endl;
        cout<<"2. Insert element "<<endl;
        cout<<"3. Recursive Traversal"<<endl;
        cout<<"4. Iterative Traversal"<<endl;
        cout<<"5. Height of binary tree"<<endl;
        cout<<"6. Check if two trees are same or not"<<endl;
        cout<<"7. Mirror image"<<endl;
        cout<<"8. Clone"<<endl;
        cout<<"9. Delete node"<<endl;
        cout<<"10. EXIT" <<endl;
        cout<<"enter your choice = ";
        cin>>cho;
        switch(cho){
        
        
            case 1: 
                cout<<"Enter root of tree = ";
                cin>>val;
                bt.create_search(val);
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
                    bt.insert_search(val2);
                    
                }
                break;
                
            case 3:
                cout<<"Recursive traversal"<<endl;
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
                cout<<"Iterative traversal"<<endl;
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
                bt2.create_search(val1);
                cout<<"Number of elements you want to insert = ";
                cin>>m;
                
                for(int i=0;i<m;i++){
                    cout<<"enter value = ";
                    cin>>val2;
                    bt2.insert_search(val2);
                    
                }

                //int chk=bt.check(bt.get_root(),bt2.get_root());
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
                break;
                
            case 8:
                cout<<"clone of the binary tree"<<endl;
                bt.preorder_traverse(bt.clone());
                cout<<endl;
                break;
                
            case 9:
                cout<<"to delete an elemnt"<<endl;
			    cin>>key;
			    bt.del_bst(key);
			    bt.preorder2();
                break;

            
            case 10:
                exit(0);
                break;
                
        
        
        }
        
    
    }while(cho!=10);


   


   return 0;
}
