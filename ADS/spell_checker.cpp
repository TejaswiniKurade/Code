#include <bits/stdc++.h>
using namespace std;


class node{
    public:
    string word;
    node *next;
    node(string w)
    {
    word=w;
    next=NULL;
    }
};

class hash
{
   
   public:
      node* table[23];
      hash()
      {
         for(int i=0;i<23;i++)
         {
            table[i]=NULL;
         }
      }
      void insert(string w)
       {
           node* x=new node(w); 
           int ind=hashfunc(w);
         
           node* head=table[ind];
           
           node* temp=head;
           if(head==NULL)
           {
              table[ind]=x;
              head=x;
              return;
           }
           else      
           {
            
             x->next=temp;
             table[ind]=x;
             head=x;
           
           }
         
           
       }
       
       int hashfunc(string s)
           {
              int l=s.length();
              int p=0;
              int i,j,k;
              int su=0;
              for(int i=l-1;i>-1;i--)
              {
                 su+=int(s[i])*(pow(10,p));
                 p++;
                 
              }
              return su%23;
              
            }
        void display(int i)
        {
            
            node* head=table[i];
            node *t= head;
            cout<<"i ="<<i<<endl;
            if(head==NULL)
            {
               cout<<-1;
            }
            
            while(t!=NULL)
            {
               cout<<t->word<<"  ";
               t=t->next;
            }
          
          
        }
        void display_full()
        {
           cout<<"Index"<<setw(9)<<"Data"<<endl;
           for(int i=0;i<23;i++)
           {
             cout<<i<<setw(9);
             node* head=table[i];
             node *t= head;
            if(head==NULL)
            {
               cout<<-1;
            }
            
            while(t!=NULL)
            {
               cout<<setw(9)<<t->word;
               t=t->next;
            }
            cout<<endl;
           }
        }
        
        void search(string w)
        {
           int ind =hashfunc(w);
           node* head=table[ind];
           node *t= head;
           while(t!=NULL)
           {
            if(t->word==w)
             {
               // cout<<"Spell correctly"<<endl;
                break;
             }
            t=t->next; 
           }

           if(t==NULL)
           {
              cout<<"INCORRECT SPELLING"<<endl;
           }
           else{
            cout<<"CORRECT SPELLING"<<endl;
           }

        }
 
}h;


int main(){
    //string w;
    int ch,i;
    char c;
    ifstream in;
    string w; 
    in.open("word.txt");
    while ( !in.eof() ) 
     { 
      h.insert(w);
        in>>w;
        
     }
     in.close();
    ofstream myfile;
    do{
        cout<<"**********SPELL CHECKER***********"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Search "<<endl;
        cout<<"3. Display full table "<<endl;
        cout<<"4. Display index wise"<<endl;
        cout<<"5. exit "<<endl;
        cout<<endl;
        cout<<"Enter your choice = ";
        cin>>ch;
        cout<<endl;
        switch(ch){
            case 1:
                cout<<"Enter element = ";
                cin>>w; 
                
                myfile.open("word.txt",ios::app);
                myfile<<w;
                myfile<<" ";
                myfile.close();
                h.insert(w);
                cout<<"Element inserted"<<endl;
                cout<<endl;
               
                break;

            case 2:
                cout<<"Enter word to search = ";
                cin>>w;
                h.search(w);
                cout<<endl;
                break;


            case 3: 
                
                cout<<"********TABLE*********"<<endl;
                h.display_full();
                cout<<endl;
                break;
            
            case 4: 
                   cout<<"Enter index = ";
                   cin>>i;
                  cout<<endl;
                   h.display(i);
                   cout<<endl;
                   break;

            case 5:
                 exit(0);
                 break;
            
        }
        cout<<"Do you want to continue y/n = ";
        fflush(stdin);
        cin>>c;
      cout<<endl;

    }while(c=='y' || c=='Y');
   
    return 0;
}
