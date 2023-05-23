#include <bits/stdc++.h>
using namespace std;


class node{

    string data;
    int f;
    node* left;
    node* right;
    node(){left=NULL;right=NULL;f=0;}
    node(string v,int c) {    this->data=v; this->f=c; }
    
    friend class tree;

};

class tree{
    
    node* root;
    
    public:
    tree(){root= NULL;}
    void frequency(string);
    void pro(){
        node *temp=root;
            pre_order(temp);
            cout<<endl;
          //  root=NULL;
    }
        void pre_order(node * root);
        
        void encode(string name){
            map<string,string> mp3,mp4;
            string text="";
          //  cout<<"::"<<endl;
          if(root->left==NULL && root->right==NULL)
            text="0";
            encode_string(root,text,mp3,mp4);
           
            string aa="";
            text="";
            for(int i=0;i<name.length();i++){
                aa=name[i];
                text+=mp3[aa];
                cout<<mp3[aa];
            }
            cout<<endl;
            decode_string(text,mp4);
        }
        void encode_string(node * root,string text,map<string,string>&mp3,map<string,string>&mp4){
            //cout<<",,,"<<endl;
            if(root!=NULL){
                if(root->left==NULL && root->right==NULL){
                  mp3[root->data]=text;
                  mp4[text]=root->data;
                }
                encode_string(root->left,text+"0",mp3,mp4);
                encode_string(root->right,text+"1",mp3,mp4);
            }
        }
        
        void decode_string(string text,map<string,string>&mp4){
            cout<<"DECODED STRING IS : ";
           // cout<<text<<endl;
            string l="";
            for(int i=0;i<text.length();i++){
                l+=text[i];
                if(mp4[l]!=""){
                    cout<<mp4[l];
                    l="";
                }
            }
            cout<<endl;
        }
       
        
}t;

void tree :: frequency(string a){
    int l=a.length();
    map<string , int> mp1;
    map<string,node*> mp2;
    multiset<pair<int,string>> s;
    
//    node *root;
    string s1="";
    for(int i=0;i<l;i++){
       s1=a[i];
        mp1[s1]++;
    //    cout<<a[i]<<" ";
    }
    
    
    for(auto it:mp1){
     s.insert({it.second,it.first});
     node *create=new node(it.first,it.second);
     mp2[it.first]=create;
    }
  
    while(!s.empty()){
        string l2=(*s.begin()).second;    int l1=(*s.begin()).first;
        s.erase({l1,l2});
     //   cout<<l2<<" "<<l1<<endl;
    //    cout<<s.size()<<",,"<<endl;
        node *create;
            if(mp2[l2]==0){
                cout<<"<<"<<endl;
                create=new node(l2,l1);
                mp2[l2]=create;
            }
            if(s.empty()==true){
                // root=create;
                // cout<<root->data<<"....."<<endl;
                root = mp2[l2];
                break;
            }
            
        string r2=(*s.begin()).second; int r1=(*s.begin()).first;
        s.erase({r1,r2});
            if(mp2[r2]==0){
                node * create1=new node(r2,r1);
                mp2[r2]=create1;
            }
            
        mp1[l2+r2]=l1+r1;
        node *xy=new node(l2+r2,mp1[l2+r2]);
        mp2[l2+r2]=xy;
        xy->left=mp2[l2];    xy->right=mp2[r2];
        s.insert({l1+r1,l2+r2});
        
        root=xy;
        
    }
//     cout<<",,"<<endl;
//     cout<<root->data<<endl;
   }
   
  

void tree :: pre_order(node * root){
   // cout<<1<<endl;
    if(root!=NULL){
        cout<<root->data<<" ";
        pre_order(root->left);
        pre_order(root->right);
    }
}

int main(){
    
    string s;
    
    while(true){
        cout<<"1.Enter the string "<<endl;
        cout<<"2.Display code"<<endl;
        cout<<"3.EXIT"<<endl;
        
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                cin>>s;
                break;
            case 2:
                t.frequency(s);
                cout<<"PRE_ORDER OF HUFFMAN TREE: ";
                t.pro();
                cout<<"CODED STRING IS : ";
                t.encode(s);
                cout<<endl;
                break;
            case 3:
                exit(0);
                                
        }
    }
}
    
