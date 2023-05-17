#include<bits/stdc++.h>
using namespace std;

const int size=10;

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
        /*node x;
        int index,prev;
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
                else {

                    prev=index;
                    while(arr[index].prn!=-1){
                        index=(index+1)%size;
                    
                    }
                    arr[index]=x;
                    for(int i=prev+1;i<index;i++){
                       if(hashfunc(arr[index].prn)==prev){
                           prev=i;
                       }
                    }
                    int i=0;
                    while(i<10 && i!=index){
                       if(hashfunc(arr[i].prn)==prev){
                           if(arr[i].link==-1){
                               arr[i].link=index;
                               break;
                           }
                           else{
                              i=arr[i].link;
                           }
                       }
                       else{
                           i++;
                       }
                       
                    }
                    //arr[prev].link=index;
                
                }
               else{
                    while(arr[index].prn!=-1){
                        index=(index+1)%size;
                    
                    }
                    arr[index]=x;
                }
                
                
                */
            
           
         node x;
        int index,prev;
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

    int del(int key){
        node temp,dummy;
        dummy.prn=-2;
        dummy.marks=-2;
        int ind;
        ind=hashfunc(key);
        while(arr[ind].prn!=-1){
            if(arr[ind].prn==key){
                temp=arr[ind];
                arr[ind]=dummy;
                return temp.prn;
            }
            ind=(ind+1)%size;


        }
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
        cout<<"*********************Hash Table**********"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Search "<<endl;
        cout<<"3. Delete "<<endl;
        cout<<"4. Display "<<endl;
        cout<<"5. exit "<<endl;
        cout<<"enter your choice = ";
        cin>>ch;
        switch(ch){
            case 1:
                //cout<<"To insert "<<endl;
                //cout<<"enter number of elements you want to insert = ";
               //cin>>y;
                //for(int i=0;i<y;i++){
                //    h.insert();
               // }
                h.insert();
                
                
                cout<<"element inserted"<<endl;
                break;

            case 2:
                cout<<"enter prn to search ";
                cin>>prn;
                h.search(prn);
                break;

            case 3:
                //cout<<"not done"<<endl;
                cout<<"enter prn to delete ";
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
        cout<<"do you want to continue y/n = ";
        fflush(stdin);
        cin>>c;


    }while(c=='y' || c=='Y');
    return 0;
}
