#include<bits/stdc++.h>
using namespace std;

const int size=23;

typedef struct node{
    int prn;
    int marks;
    int link;
}node;

class Hash{

    public:
    node arr[size];
    //int index,prev;
    void init(){
        for(int i=0;i<size;i++){
            arr[i].prn=-1;
            arr[i].marks=-1;
            arr[i].link=-1;
        }
    }

    void display(){
        cout<<"   "<<"Index"<<"   "<<"PRN"<<"      "<<"Marks"<<"    "<<"Link"<<endl;
        for(int i=0;i<size;i++){
            cout<<"   "<<i<<"      "<<arr[i].prn<<"          "<<arr[i].marks<<"      "<<arr[i].link<<endl;
        }
    }

    int isfull(){
        for(int i=0;i<size;i++){
            if(arr[i].prn==-1){
                return 0;
            }
        }
        return 1;
    }

    int hashfunc(int key){
        return key%size;
    }

    void insert(){
        node x;
        int index,prev,previ;
        if(isfull()){
            cout<<"Hash table is full"<<endl;
        }
        
            cout<<"Enter prn number = ";
            cin>>x.prn;
            cout<<"Enter marks = ";
            cin>>x.marks;
            x.link=-1;
            index=hashfunc(x.prn);
            if(arr[index].prn==-1){
                arr[index]=x;
            }
           
           
           else if((hashfunc(arr[index].prn)==index) )
           {  
                 while(arr[index].link!=-1)
                {
                    index=arr[index].link;

                }

                prev=index;
                while(arr[index].prn!=-1){
                    index=(index+1)%size;
                    
                }
                arr[index]=x;
                arr[prev].link=index;
            }
            else{
                
                prev=arr[index].prn;
                cout<<"prev ="<<prev<<endl;
                previ=arr[index].link;
                int purana=index;
                cout<<"purana ="<<purana<<endl;
                arr[index]=x;
                while(arr[index].prn!=-1)
                {
                     index=(index+1)%size;
                    cout<<"index  "<<index<<endl;
                 }
                arr[index].prn=prev;
                arr[index].link=previ;
                // previ=hashfunc(prev);
                // prev=index;
                for(int i=0;i<10;i++)
                {
                    cout<<"i = "<<i<<endl;   
                    if(arr[i].link==purana)
                    {
                        arr[i].link=index;
                        break;
                    }
                    
                }
                //arr[prev].link=index;

            }


        
    }

    void search(int key){
        // node s;
        // cout<<"enter prn to search ";
        int index;
        // cin>>s.prn;
        index=hashfunc(key);
        
        while(arr[index].prn!=key){
            index=(index+1)%size;
        }
        if(arr[index].prn==key){
            cout<<"PRN is present in table"<<endl;
            cout<<"PRN = "<<arr[index].prn<<"   "<<"Marks = "<<arr[index].marks<<endl;
        }
        // else if(arr[index].prn==key){
        //     index=(index+1)%size;

        // }
        else{
            cout<<"PRN not found !!!"<<endl;
        }
    }


};

int main(){
    int prn,x,y;
    Hash h;
    h.init();
    int ch;
    char c;
    do{
        cout<<"********Hash Table***"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Search "<<endl;
       
        cout<<"4. Display "<<endl;
        cout<<"5. exit "<<endl;
        cout<<"enter your choice = ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"To insert "<<endl;
                
                h.insert();
                cout<<"element inserted"<<endl;
                break;

            case 2:
                cout<<"enter prn to search ";
                cin>>prn;
                h.search(prn);
                break;

    
            case 4:
                h.display();
                break;
            case 5:
                 exit(0);
                 break;
            
        }
        //cout<<"do you want to continue y/n = ";
        fflush(stdin);
        //cin>>c;


    }while(1);
    return 0;
}