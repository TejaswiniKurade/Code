#include <bits/stdc++.h>
using namespace std;

class Node
{
  int data;
  bool qf;
  Node *next;

public:
  Node(int d)
  {
    data = d;
    qf = 0;
    next = NULL;
  }
  friend class graph;
};

class graph
{
  vector<Node *> v;

public:
   void create();
};

void graph::create()
{
  cout << "Enter no of edges = ";
  int n; cin >> n;
  v.assign({NULL});
  for (int i = 0; i < n; i++)
  {
    while (1)
    {
      cout << "Enter " << i << " adjacent element = ";
      int d;
      cin >> d;
      if (d != -1)
      {
        Node *ins_node = new Node(d);
        if (v[i] == NULL)
        {
          v[i] = ins_node;
        }
        else
        {
          while (v[i]->next != NULL)
          {
            v[i] = v[i]->next;
          }
          v[i] = ins_node;
        }
      }
      else
      {
        break;
      }
    }
  }
}

int main()
{
  graph g;
  g.create();
}