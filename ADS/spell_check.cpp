#include<bits/stdc++.h>
using namespace std;
#define table_size 23
class node
{
    public:
    string data;
    node *next;
    node(string w)
    {
      data=w;
      next=NULL;
    }
};

class linked{
    node *head;
    public:
       node *arr[table_size]={NULL},*c;
       void create();
       void insert(string);
       void check(string);
       void display();
};

/* long long hash_func(string s){
        long long p = 31, m = 1e9 + 7;
        long long hash_value;
        long long hash_so_far = 0;
        long long p_pow = 1;
         const long long n = s.length();
       for (long long i = 0; i < n; ++i) {
             hash_so_far
                 = (hash_so_far + (s[i] - 'a' + 1) * p_pow)
                   % m;
             p_pow = (p_pow * p) % m;
         }
         hash_value = hash_so_far;
         return hash_value%23;

 }*/

int hash_func(string s)
{
        int l=s.length();
        int p=0;
        int i,j,k;
        int su=0;
        for(int i=l-1;i>-1;i--)
        {
            su+=(s[i] - 'a' + 1)*(pow(10,p));
            p++;
                 
        }
        return su%23;
              
}



void linked::insert(string st){
    node *New,*temp;
    
    //string st;
    
    //cout<<"enter string = ";
    //cin>>st;
    New= new node(st);
    long long i=hash_func(st);
    New->data=st;
    //New->next=NULL;
    if(arr[i]==NULL){
        arr[i]=New;
    }         
    else{
        c=arr[i];
        New->next=c;
        arr[i]=New;
        
    }
    cout<<"Inserted at index = "<<i<<endl;
}

void linked::display(){
    cout<<"  "<<"Index"<<"   "<<endl;;
    for(int i=0;i<table_size;i++){
        cout<<"  "<<i<<"  ";
        
        if(arr[i]==NULL){
            cout<<"-1"<<endl;
        }
        else{
            c=arr[i];
            while(c!=NULL){
                cout<<c->data<<" -> ";
                c=c->next;
           }
            // for(c=arr[i];c!=NULL;c=c->next){
            //     cout<<c->data<<" -> ";
            // }
            cout<<endl;
        }
    }
}

void linked::check(string w){
    int ind=hash_func(w);
    int cnt=0;
    if(arr[ind]==NULL){
        cout<<"INCORRECT WORD"<<endl;
    }
    else{
        for(c=arr[ind];c!=NULL;c=c->next){
            cnt++;
            if(c->data==w){
                cout<<"CORRECT WORD "<<endl;
                
                break;
            }
            

        }
        if(c==NULL){
            cout<<"INCORRECT WORD"<<endl;
        }
        cout<<"Number of comparisions = ";
        cout<<cnt<<endl;
    }
}



int main(){
    linked l;
    int cho,n;
    char ch;
    string my;
    ifstream in;
    ofstream of;
    string w; 
    in.open("word.txt");
    while ( !in.eof() ) 
     { 
        
        getline(in, w);
        l.insert(w);
        
     }
     in.close();

    do{
        cout<<"*******   Spell check  ****** "<<endl;
        cout<<"1. enter string "<<endl;
        cout<<"2. display "<<endl;
        cout<<"3. Check spell"<<endl;
        cout<<"4. exit"<<endl;
        cout<<"enter your choice = ";
        cin>>cho;
        switch(cho){
            case 1:
                cout<<"Enter element = ";
                cin>>w;
                l.insert(w);
                of.open("word.txt",ios::app);
                of<<w<<endl;
                of.close();
                break;
            case 2:
                cout<<"*** table ***"<<endl;
                l.display();
                break;
            case 3:
                cout<<"Enter string to check = ";
                cin>>my;
                l.check(my);
                break;
            case 4:
                exit(0);
                break;
        }
        cout<<"do you want to continue y/n = ";
        fflush(stdin);
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}
