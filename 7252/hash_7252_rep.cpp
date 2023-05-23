#include<bits/stdc++.h>
using namespace std;

const int size=10;

typedef struct node{
    int prn;
    int data;
    int link;
}node;

class Hash{

    public:
    node arr[size];
    //int index,prev;
    void init(){
        for(int i=0;i<size;i++){
            arr[i].prn=-1;
            arr[i].data=-1;
            arr[i].link=-1;
        }
    }

    void display(){
        cout<<"Index"<<setw(7)<<"PRN"<<setw(11)<<"Data"<<setw(10)<<"Link"<<endl;
        for(int i=0;i<size;i++){
            cout<<i<<setw(10)<<arr[i].prn<<setw(10)<<arr[i].data<<setw(10)<<arr[i].link<<endl;
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
        int index,prev,prev_new;
        if(isfull()){
            cout<<"Hash table is full"<<endl;
        }
            cout<<"Enter prn number = ";
            cin>>x.prn;
            cout<<"Enter Data = ";
            cin>>x.data;
            x.link=-1;
            index=hashfunc(x.prn);
            if(arr[index].prn==-1){
                arr[index]=x;
            }
           
           
           else if((index==hashfunc(arr[index].prn)) )
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
                prev_new=arr[index].link;
                int old=index;
                cout<<"Old index ="<<old<<endl;
                arr[index]=x;
                while(arr[index].prn!=-1)
                {
                     index=(index+1)%size;
                    cout<<"index  "<<index<<endl;
                 }
                arr[index].prn=prev;
                arr[index].link=prev_new;
                for(int i=0;i<10;i++)
                {
                    cout<<"i = "<<i<<endl;   
                    if(arr[i].link==old)
                    {
                        arr[i].link=index;
                        break;
                    }
                }
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
        cout<<"*******Hash Table*******"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Display "<<endl;
        cout<<"3. exit "<<endl;
        cout<<"enter your choice = ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"To insert "<<endl;
                h.insert();
                cout<<"element inserted"<<endl;
                break;
            case 2:
                h.display();
                break;
            case 3:
                 exit(0);
                 break;
            
        }
        fflush(stdin);
        
    }while(1);
    return 0;
}
