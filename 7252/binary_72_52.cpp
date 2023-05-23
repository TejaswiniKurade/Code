#include <bits/stdc++.h>
#include <queue>
using namespace std;
class node{
   
   private:
   int data;
   node *left,*right;
	public:
   node(){
      left=NULL;
      right=NULL;
   }
   node(int x){
     data=x;
      left=NULL;
      right=NULL;
      
   }
	friend class binarytree;
};

class binarytree{
   node* root;
	public:
	binarytree(){
		root=NULL;
	}
	binarytree(node* x){root=x;}
   node *temp;
	node* get_root(){return root;}
   void insert(int val){
       node *ptr=new node(val);
       int ch;
       if(root==NULL){
          root=ptr;return;
       }
       else{
           temp=root;
           while(1){
              cout << "Enter 1 for right abd 0 for left subtree" << endl;
              cin >> ch;
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
	void insert_bs(int val){
	    node *ptr=new node(val);
       	if(root==NULL){
          root=ptr;return;
       	}
		else{
			temp=root;
			while(1){
				if(val<temp->data){
					if(temp->left==NULL){
						temp->left=ptr;break;
					}
					else{
						temp=temp->left;
					}
				}
				else{
					if(temp->right==NULL){
						temp->right=ptr;break;
					}
					else{
						temp=temp->right;
					}
				}
			}

		}

	}
  
   void preorder(node *root){
       if(root!=NULL){
          cout << root->data <<" ";
          preorder(root->left);
          preorder(root->right);
       }
      // cout << endl;
   }
      void preorder1(){
       preorder(root);                         
   }
	void iterative_pre(node* root){
		stack<node*> st;
		node* x=root;
		while(x!=NULL || st.empty()){
			while(x!=NULL){
				cout<<x->data<<" ";
				st.push(x);
				x=x->left;
			}
			x=st.top();
			st.pop();
			x=x->right;			
			
		}
	}
	void iterative_pre1(){
	 iterative_pre(root);}
    void inorder(node *root){
      if(root!=NULL){
          inorder(root->left);
          cout << root->data << " ";
          inorder(root->right);
          
      }
      //cout << endl;
   }
   void inorder1(){
      inorder(root);
   }
   void postorder(node *root){
       if(root!=NULL){
          postorder(root->left);
          postorder(root->right);
          cout << root->data << " ";
       }
   }
   void postorder1(){
       postorder(root);
   }
   void levelorder(node *root){
       queue<node *> q;
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
          cout << x->data << " ";
          q.pop();
          
       }
   }
   void levelorder1(){
       levelorder(root);
   }
   int  height(node* root){
		if(root==NULL){return 0;}
		return (max(height(root->left),height(root->right))+1);
		
	}
	int height1(){
		height(root);                      
	}
   bool identical(node* root,node* root2){

      if(root==root2 && root==NULL){return 1;}
      else if(root==NULL && root2!=NULL){return 0;}
      else if(root!=NULL && root2==NULL){return 0;}
      else{
         if((root->data==root2->data) && identical(root->left,root2->left) && identical(root->right,root2->right)){
            return 1;
         }
         else{
            return 0;
         }
      }
   }
	node* create_clone(node* root){
		if(root==NULL){
			return 	NULL;
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
	node* create_clone1(){create_clone(root);}
	node* mirror(node* root){
		if(root==NULL){
			return 	NULL;
		}
		else{
			node* p=new node(root->data);
			node* x=mirror(root->left);
			node* y=mirror(root->right);
			p->left=y;
			p->right=x;
			return p;
		}
	}
	node* mirror1(){mirror(root);}
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
	node* deletion(node* root,int key){
		if (root == NULL)
        return NULL;
    	if (root->left == NULL && root->right == NULL) {
        	if (root->data == key)
           	 return NULL;
        	else
            return root;
    }
	
	node* key_node = NULL;
    node* temp;
    node* last;
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data == key)
            key_node = temp;
        if (temp->left) {
            last = temp; // storing the parent node
            q.push(temp->left);
        }
        if (temp->right) {
            last = temp; // storing the parent node
            q.push(temp->right);
        }
    }
    if (key_node != NULL) {
        key_node->data
            = temp->data; // replacing key_node's data to
                          // deepest node's data
        if (last->right == temp)
            last->right = NULL;
        else
            last->left = NULL;
        delete (temp);
    } return root;
    }

   
   
};
/*delnode=search(key)Parent=delnodeparent;if((delNode->left == NULL) && (delNode->right == NULL)) // node to be deleted has no children {if(parent->left == delNode) { parent->left = NULL; free(delNode); delNode= NULL; } else if(parent->right == delNode){ parent->right = NULL;free(delNode); delNode= NULL; }else if((delNode->left!=NULL) && (delNode->right == NULL)) //node to be deleted has exactly one child { if(parent->left == delNode) { parent->left = delNode->left; free(delNode); delNode= NULL; } 

else if(parent->right == delNode){ parent->right = delNode->left;free(delNode); delNode= NULL; }}
else if((delNode->left==NULL) && (delNode->right!= NULL)) //node to be deleted has exactly one child { if(parent->left == delNode) { parent->left = delNode-> right; delNode = NULL; } else if(parent->right == delNode){ parent->right = delNode-> right;delNode = NULL; }}

else if((delNode->right!=NULL)&&(delNode->left != NULL)) //if has two children {  temp = delNode;trav = delNode->right; if((trav->right == NULL)&&(trav->left == NULL)){  delNode->key = trav->key;  free trav; delNode->right =NULL; } else {ptr = trav; while(trav->left!=NULL) { ptr = trav; //smallest node in right subtree       trav=trav->left;} delNode->key = trav->key; ptr->left=trav->right;trav = NULL; } } 
ALGORITHM(RECURSIVE)delnode(node *root, key)if root==NULL return root;if key< root->dataroot->left =delnode( root->left,key)else if key< root->dataroot->left =delnode( root->left,key)else{ if (root->left==NULL)temp==root->right;  free root; return temp;else if (root->right==NULL)temp==root->left;  free root; return temp;}
else temp= root->right;while (temp->left !=NULL) temp=temp->left;root->key =temp->keyroot->right=delnode(root->right,temp->key)



*/



int main(){
   binarytree bt,bt1;
   node* root2,clone,ans;
   int cho;
   char ch;
   int val1,val2,n,m,x,val3,val4,index,key;
   map<int,int> mp;
   vector<int> pre,in,post;
   do{
   
      cout << "------------BINARY TREE-----------" << endl;
      cout << "1.Insert element" << endl;
      cout << "2.display preorder" << endl;
      cout << "3.Display inorder" << endl;
      cout << "4.Display postorder" << endl;
      cout << "5.Display level order" << endl;
      cout << "6.Display height" << endl;
      cout<<"7.identical or not"<<endl;
      cout<<"8.Create a clone"<<endl;
      cout<<"9.Create a mirror image"<<endl;
	  cout<<"10.Create a tree from inorder and preorder"<<endl;
	  cout<<"11.Create a tree from inorder and postorder"<<endl;
	  cout<<"12.delete a node from binary tree"<<endl;
      cout << "13.Exit" << endl;
      
      cout << "Enter your choice";
      cin >> cho;
      switch(cho){
      
          case 1:
			cout<<"Enter 0 if you want to insert elements in binary tree and 1 for binary search tree"<<endl;
			cin>>x;
			cout << "Enter number of values: " ;
          	cin >> n;cout << endl;
			cout << "Enter the root value: ";
            cin>> val1;
			if(x){
				bt.insert_bs(val1);
          		for(int i=0;i<n-1;i++){
             		cout << "Enter the value: " ;
             		cin >> val2;
             		bt.insert_bs(val2);
         		 }
			}
			else{
				bt.insert(val1);
          		for(int i=0;i<n-1;i++){
             		cout << "Enter the value: " ;
             		cin >> val2;
             		bt.insert(val2);
         		 }
			}
         
          
        
         
          break;
          
          case 2:
          cout << "Preorder" << endl;
          bt.preorder1();
          break;
          case 3:
          cout << "Inorder" << endl;
          bt.inorder1();
          break;
          case 4:
          cout << "Postoder" << endl;
          bt.postorder1();
          break;
          case 5:
          cout << "level order" << endl;
          bt.levelorder1();
          break;
          case 6:
           cout << "Height" << endl;
           cout<<bt.height1()<<endl;
          break;
          case 7:
            cout<<"Identical or not"<<endl;
            cout << "Enter number of values: " ;
          	cin >> m;cout << endl;
			cout << "Enter the root value: ";
            cin>> val3;
            bt1.insert(val3);
          		for(int i=0;i<m-1;i++){
             		cout << "Enter the value: " ;
             		cin >> val4;
             		bt1.insert(val4);
         		 }
             cout<<bt.identical(bt.get_root(),bt1.get_root());
			
                //root2=bt1.get_root();
               // cout<<bt.identical(root2);
                
            

          break;
		case 8:
			cout<<"clone of the binary tree"<<endl;
			
			bt.preorder(bt.create_clone1());
			
			 break;
		case 9:
				cout<<"mirror of the binary tree"<<endl;
				bt.preorder(bt.mirror1());
				break;

		case 10:
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
			    bt.postorder( bt.solve(in,pre,index,0,n-1,n,mp));
 				break;
		case 11:
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
			    bt.preorder(bt.solve1(in,post,index,0,n-1,n,mp));
 				break;
		case 12:
			cout<<"to delete an elemnt"<<endl;
			cin>>key;
			bt.preorder1();cout<<endl;
			bt.preorder(bt.deletion(bt.get_root(),key));



			break;
        case 13: 
          	exit(0);
          	break;
      }
		fflush(stdin);
   }
   while(cho!=11);
   return 0;
}
           
