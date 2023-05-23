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
        int index,prev;
        if(isfull()){
            cout<<"Hash table is full"<<endl;
        }
        
            cout<<"Enter prn number = ";
            cin>>x.prn;
            cout<<"Enter marks = ";
            cin>>x.data;
            x.link=-1;
            index=hashfunc(x.prn);
            if(arr[index].prn==-1){
                arr[index]=x;
            }
            else if(index==hashfunc(arr[index].prn)){
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
                //cout<<"else"<<endl;
                prev=index;
                while(arr[index].prn!=-1)
                {
                    //cout<<"index  "<<index<<endl;
                    index=(index+1)%size;
                 }
                arr[index]=x;
                int i=0;
                while(i<10 && i!=index)
                {
                    if(hashfunc(arr[i].prn)==prev)
                    {
                        if(arr[i].link==-1)
                        {
                            arr[i].link=index;
                            break;
                        }
                        else
                        {
                            i=arr[i].link;
                        }
                    }
                    else{
                        i++;
                    }
                }
            }
    }


    void search(int key){
        int index;
        index=hashfunc(key);
        
        while(arr[index].prn!=key){
            index=(index+1)%size;
        }
        if(arr[index].prn==key){
            cout<<"PRN is present in table"<<endl;
            cout<<"PRN = "<<arr[index].prn<<"   "<<"Data = "<<arr[index].data<<endl;
        }
        else{
            cout<<"PRN not found !!!"<<endl;
        }
    }


    int del(int k){
        node a,x;
        x.prn=-2;
        x.data=-2;
        int ind;
        ind=hashfunc(k);
        while(arr[ind].prn!=-1){
            if(arr[ind].prn==k){
                a=arr[ind];
                arr[ind]=x;
                return a.prn;
            }
            ind=(ind+1)%size;}
        return -1;
    }
};

int main(){
    int prn,x,y;
    Hash h;
    h.init();
    int ch;
    char c;
    do{
        cout<<"******Hash Table******"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Search "<<endl;
        cout<<"3. Delete "<<endl;
        cout<<"4. Display "<<endl;
        cout<<"5. exit "<<endl;
        cout<<"Enter your choice = ";
        cin>>ch;
        switch(ch){
            case 1:
                cout<<"To insert "<<endl;
                h.insert();
                //cout<<"element inserted"<<endl;
                break;

            case 2:
                cout<<"Enter prn to search ";
                cin>>prn;
                h.search(prn);
                break;

            case 3:
                cout<<"Enter prn to Delete ";
                cin>>prn;
                x=h.del(prn);
                if(x==-1){
                    cout<<"not found"<<endl;
                }
                else{
                    cout<<"prn = "<<x<<" is deleted"<<endl;
                }
                break;

            case 4:
                h.display();
                break;
            case 5:
                 exit(0);
                 break;
            
        }
        fflush(stdin); 

    }while(1);
    return 0;
}
