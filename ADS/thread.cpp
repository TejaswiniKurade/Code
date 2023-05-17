#include <bits/stdc++.h>
using namespace std;
#define MAX_VALUE 65536

struct node {
    int key;
    node *left, *right;
    bool left_thread,right_thread;
};

class threaded_binary{
    
        
    public:
    node *root;
        threaded_binary()
        {
            root= new node();
            root->right=root->left=root;
            root->left_thread = true;
            root->key = MAX_VALUE;
        }
        
        
        void makeEmpty()
        {
            root= new node();
            root->right=root;
            root->left=root;
            root->left_thread = true;
            root->key = MAX_VALUE;
        }
        
        void insert(int key)
        {
            node *p = root;
            while(1){
                if(p->key < key)
                {
                    if(p->right_thread){
                        break;
                    }
                    p=p->right;
                } 
                
                else if(p->key > key){
                    if(p->left_thread){
                        break;
                    }
                    p=p->left;
                
                }
                else{
                    return;
                }
            
            }
            
            node *tmp = new node();
            tmp->key = key;
            tmp->right_thread=true;
            tmp->left_thread=true;
            
            if(p->key < key)
            {
                tmp->right=p->right;
                tmp->left=p;
                p->right=tmp;
                p->right_thread=false;
            }
            else
            {
                tmp->right=p;
                tmp->left=p->left;
                p->left=tmp;
                p->left_thread=false;
            }
        }
        
      
	    void bst_insert(int val)
		{

			node *p = root;

			if (p->left == p)
			{
				// first insertion
				node *tmp = new node();
				tmp->left = NULL;
				tmp->right = NULL;
				tmp->key = val;
				p->left = tmp;
				return;
			}

			while (true)
			{
				if (p->key < val)
				{
					if (p->right == NULL)
						break;
					p = p->right;
				}
				else if (p->key > val)
				{
					if (p->left == NULL)
						break;
					p = p->left;
				}
				else
				{
					return;
				}
			}

			node *tmp = new node();
			tmp->left = NULL;
			tmp->right = NULL;
			tmp->key = val;

			if (p->key < val)
			{
				p->right = tmp;
			}
			else
			{
				p->left = tmp;
			}
		}

		void convert_thread(){
			vector<node *> vec;

    		node *T = root->left;
    		stack<node *> stk;
    		int ct = 0;
    		while (T != NULL || !stk.empty())
    		{
        		while (T != NULL)
        		{
            		stk.push(T);
            		T = T->left;
        		}
        		T = stk.top();
        		stk.pop();

        		vec.push_back(T);

        		T = T->right;
        		ct++;
    		}

    		int n = vec.size();

			node *t = vec[0];
			t->left = root;
			t->left_thread = true;
			t = vec[n - 1];
			t->right = root;
			t->right_thread = true;

			root->left_thread = false;

			for (int i = 0; i < n; i++)
			{
				node *t = vec[i];

				if (i)
					if (t->left == NULL)
					{
						t->left = vec[i - 1];
						t->left_thread = true;
					}
					else
					{
						t->left_thread = false;
					}

				if (i != n - 1)
					if (t->right == NULL)
					{
						t->right = vec[i + 1];
						t->right_thread = true;
					}
					else
					{
						t->right_thread = false;
					}
    		}
		}


        void display()
        {
            node *tmp,*p;
            tmp=root;
            while(1)
            {
            	p=tmp;
            	tmp = tmp->right;
            	if(!p->right_thread)
            	{
            	    while(!tmp->left_thread)
            	    {
            	        tmp=tmp->left;
            	    }
            	}
                
                if(tmp==root)
                    break;
                
                cout<<tmp->key<<" "<<"("<<tmp->left_thread<<","<<tmp->right_thread<<")"<<"    ";
            }
            cout<<endl;
        }
        
        
        bool search(int key){
            node *tmp;
            tmp=root->left;
            while(1){
                if(tmp->key<key){
                   if(tmp->right_thread){
                   		return false;
                   }
                   tmp=tmp->right;
                }
                else if(tmp->key>key){
                   if(tmp->left_thread){
                   		return false;
                   }
                   tmp=tmp->left;
                }
                else{
                    return true;
                }
            }
        }
        
        
        void del(int key){
        	node *dest=root->left,*p=root;
        	
        	while(1){
        	    if(dest->key<key){
        	        if(dest->right_thread){
        	            return;
        	        }
        	        p=dest;
        	        dest=dest->right;
        	    }
        	    else if(dest->key > key){
        	        if(dest->left_thread){
        	            return;
        	        }
        	        p=dest;
        	        dest=dest->left;
        	        
        	    }
        	    else{
        	        break;
        	    
        	    }
        	
        	}
        	
        	node *target=dest;
        	if(!dest->right_thread && !dest->left_thread){
        	    //dest has two children
        	    p=dest;
        	    
        	    target=dest->left;
        	    while(!target->right_thread)
        	    {
        	        p=target;
        	        target=target->right;
        	    }
        	    dest->key=target->key;
        	
        	}
        	
        	if(p->key >= target->key){
        			//only left child
        	    if(target->right_thread && target->left_thread){
        	         p->left=target->left;
        	         p->left_thread=true;
        	    }
        	    else if(target->right_thread){
        	         node *largest=target->left;
        	         while(!largest->right_thread){
        	             largest=largest->right;
        	         
        	         }
        	         largest->right=p;
        	         p->left=target->left;
        	    }
        	    else{
        	         node *smallest=target->right;
        	         while(!smallest->left_thread){
        	             smallest=smallest->left;
        	         
        	         }
        	         smallest->left=target->left;
        	         p->left=target->right;
        	    }
        	}
        	else{
        			//only right child
        		if(target->right_thread && target->left_thread){
        	         p->right=target->right;
        	         p->right_thread=true;
        	    }
        	    else if(target->right_thread){
        	         node *largest=target->left;
        	         while(!largest->right_thread){
        	             largest=largest->right;
        	         
        	         }
        	         largest->right=target->right;
        	         p->right=target->left;
        	    }
        	    else{
        	         node *smallest=target->right;
        	         while(!smallest->left_thread){
        	             smallest=smallest->left;
        	         
        	         }
        	         smallest->left=p;
        	         p->right=target->right;
        	    }
        	
        	}
        
        }

        
        
        
        
};

int main()
{
	threaded_binary tb;
	int n,val,val2,val3;
	int ch;
	
	do{
	     cout<<"--------Threaded binary tree----------"<<endl;
	     cout<<"1. Insert element (build binary threaded search tree from scratch)"<<endl;
	     cout<<"2. Display tree"<<endl;
		 cout<<"3. Insert binary search tree"<<endl;
		 cout<<"4. convert into binary threaded search tree"<<endl;
	     cout<<"5. Search"<<endl;
	     cout<<"6. Delete element"<<endl;
	     cout<<"7. Exit"<<endl;
	     cout<<"Enter choice = ";
	     cin>>ch;
	     switch(ch){
	          case 1:cout<<"enter no of elements to insert = ";
					cin>>n;
					for(int i=0;i<n;i++){
	    				cout<<"enter value = ";
	   				    cin>>val;
	    				tb.insert(val);
					}
					break;
			  case 2:
			  		tb.display();
			  		break;
			  case 3:
			        cout<<"enter no of elements to insert = ";
					cin>>n;
					for(int i=0;i<n;i++){
	    				cout<<"enter value = ";
	   				    cin>>val;
	    				tb.bst_insert(val);
					}
					break;
			  case 4:
			        tb.convert_thread();
					cout<<"Converted"<<endl;
					tb.display();
					break;
			  case 5:
			  		cout<<"enter value to search = ";
					cin>>val2;
					if(tb.search(val2)){
	    				cout<<"key present in tree"<<endl;
					}
					else{
						cout<<"key not present in tree"<<endl;
					}
					break;
			  case 6:
			        cout<<"Enter value to delete = ";
			        cin>>val3;
			        tb.del(val3);
			        tb.display();
			        break;
			  case 7:
			        exit(0);
			        
					
	     
	     }
	
	
	}while(ch!=7);

	return 0;
}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
   




