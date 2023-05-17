#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int freq;
    char letter;
    node *left, *right;
    node(int f, char d)
    {
        freq = f;
        letter = d;
        left = NULL;
        right = NULL;
    }
    friend class HuffmanTree;
};

class HuffmanTree
{
public:
    vector<pair<char, int>> freqvec;
    map<char, string> tree();
    bool compare(pair<char, int> &a, pair<char, int> &b);
    void frequencyTable(string s);
    void encode(node *root, string s, map<char, string> &codeTable);
    void decode(string s);
    void Menu();

};


map<char, string> HuffmanTree::tree()
{
    map<char, string> codeTable;
    priority_queue<node *, vector<node *>, function<bool(node *, node *)>> priorityNodes([](node *a, node *b)
                                                                                         { return a->freq > b->freq; });
    for (auto &i : freqvec)
    {
        node *x = new node(i.second, i.first);
        priorityNodes.push(x);
    }
    while (priorityNodes.size() != 1)
    {
        node *left = priorityNodes.top();
        priorityNodes.pop();
        node *right = priorityNodes.top();
        priorityNodes.pop();
        int sum = left->freq + right->freq;
        node *connect = new node(sum, '@');
        connect->left = left;
        connect->right = right;
        priorityNodes.push(connect);
    }
    node *root = priorityNodes.top();
    encode(root, "", codeTable);
    return codeTable;
}

bool HuffmanTree::compare(pair<char, int> &a, pair<char, int> &b)
{
    return a.second < b.second;
}

void HuffmanTree::frequencyTable(string s)
{
    queue<int> q[26];
    for (int i = 0; i < s.size(); i++)
    {
        q[s[i] - 97].push(1);
    }

    for (int i = 0; i < 26; i++)
    {
        if (q[i].size() > 0)
        {
            freqvec.push_back(make_pair(char(i + 97), q[i].size()));
        }
    }
    map<char, string> dis_table=tree();
    cout<<"Letter"<<setw(8)<<"Code"<<endl;
    for(auto &i:dis_table)
    {
        cout<<i.first<<setw(13)<<i.second<<endl;
    }
}

void HuffmanTree::encode(node *root, string s, map<char, string> &codeTable)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            codeTable[root->letter] = (s != "") ? s : "1";
        }
        encode(root->left, s + "0", codeTable);
        encode(root->right, s + "1", codeTable);
    }
}

void HuffmanTree::decode(string s)
{
    map<char, string> table;
    table=tree();
    
       int c=1,i=0;
       while(i+c<=s.size())
        {
           bool flag=0;
           string sub=s.substr(i,c);
           for (auto &j: table)
           {
              if(j.second==sub)
              {
                cout<<j.first;
                i=i+c;
                c=1;
                flag=1;
                break;
              }
           }
           if(flag==0)
           {
             c++;
           }
        }
}

void HuffmanTree:: Menu()
{
  
    cout <<"Huffman Encoding and Decoding";

    while (true)
    {
        string str;
        cout << "\n\n1.Encode\n2.Decode\n3.Exit\n";
        cout << ">>";

        int choice; cin >>choice;
        cout << endl;

        if (choice==1){
            cout << "Enter the string. - ";
            cin>>str;
            frequencyTable(str);
            

        }
        else if (choice == 2) 
        {
            cout << "Enter the binary string. - ";
            cin>>str;
            decode(str);
        }
        else 
        {
            exit(0);
        }
    }
}


int main()
{
    HuffmanTree h;
    h.Menu();
}
