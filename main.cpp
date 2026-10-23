
#include <bits/stdc++.h>

using namespace std;
class node
{
    public:
    int date;
    node * left;
     node * right;
     node()
     {
        date=0;
        left =right= NULL;
     }
};
class BST
{
    public:
    node *root;
    BST()
    {
     root = NULL;
    }
    node *Insert(node *r, int item)
    {
        if (r==NULL)
        {
            node *newnode = new node;
            newnode->date = item;
            newnode->left = NULL;
            newnode->right = NULL;
            r= newnode;
        }
        else if (item < r->date)
            r->left= Insert(r->left, item);
        else
           r->right= Insert(r->right, item);
        return r;
    }
    void Insert (int item)
    {
        root = Insert(root , item);
    }
    void preorder(node *r)
    {
        if(r == NULL)
            return;
        cout<<r->date<<"      ";
        preorder(r->left);
        preorder(r->right);
    }
        void INorder(node *r)
    {
        if(r == NULL)
            return;

      INorder(r->left);
      cout<<r->date<<"      ";
       INorder(r->right);
    }
        void postorder(node *r)
    {
        if(r == NULL)
            return;

        postorder(r->left);
        postorder(r->right);
             cout<<r->date<<"      ";
    }
    node *Search(node *r, int key)
    {
        if (r== NULL)
            return 0;
        else if (r->date == key)
            return r;
        else if ( key <r->date)
         return Search(r->left,key);
          else
       return Search (r->right, key);
    }
bool Search (int key)
{
    node *result =Search (root,key);
    if (result ==NULL)
        return false;
    else
        return true;
}
  node *findmin(node *r)
  {
      if (r== NULL)
        return 0;
      else if (r->left == NULL)
        return r;
      else
        return findmin(r->left);
  }
    node *findmax(node *r)
  {
          if (r== NULL)
        return 0;
      else if (r->right == NULL)
        return r;
      else
        return findmax(r->right);
  }
node *Delete (node *r, int key)
{
    if (r== NULL)
        return 0;
   if (key < r->date)
        r->left = Delete( r->left, key);
        else if (key > r->date)
          r->right = Delete( r->right, key);
          else
    {
        if (r->left == NULL && r->right == NULL)
            r= NULL;
        else if (r->left != NULL && r->right== NULL)           // one child
        {
            r->date = r->left->date;
            delete r->left;
            r->left= NULL;
        }
            else if (r->left == NULL && r->right!= NULL)           // one child
        {
            r->date = r->right->date;
            delete r->right;
            r->right =NULL;
    }
    else   //two child
    {
       node *Max =  findmax(r->left);
       r->date = Max->date;
      r->left =  Delete (r->left,Max->date);
    }
    }
    return r;
}
};
int main()
{
    BST btree;
    btree.Insert(45);
     btree.Insert(15);
     btree.Insert(79);
    btree.Insert(90);
      btree.Insert(10);
    btree.Insert(55);
     btree.Insert(12);
        btree.Insert(20);
        btree.Insert(50);
    cout << "Display" << endl;
        btree.preorder(  btree.root);
        cout<<"---------------------------------"<<endl;
        /*
              btree.INorder(  btree.root);
        cout<<"---------------------------------"<<endl;
              btree.postorder(  btree.root);
        cout<<"---------------------------------"<<endl;
        */
        int key;
        cout<<"Enter Item for Search"<<endl;
        cin>>key;
        if( btree.Search(key))
            cout<<"Item Found"<<endl;
        else

            cout<<"Item Not Found"<<endl;

            cout<<"Find Miniuim"<<endl;
            node *Min = btree.findmin( btree.root);
            if (Min ==0)
                cout<<"NO Items Exist"<<endl;
            else
                 cout<<"Miniuim This = "<<Min->date<<endl;
                  cout<<"---------------------------------"<<endl;

             cout<<"Find Maxinim"<<endl;
            node *Max = btree.findmax( btree.root);
            if (Max ==0)
                cout<<"NO Items Exist"<<endl;
            else
                 cout<<"Maxinim This = "<<Max->date<<endl;
                    cout<<"---------------------------------"<<endl;

           cout<<"Delete Item"<<endl;
           node *result =   btree.Delete(btree.root, 12) ;
           cout<<"preorder after Delete 12"<<endl;
              btree.preorder( result);
                     cout<<"---------------------------------"<<endl;
              result =   btree.Delete(btree.root, 15) ;
           cout<<"preorder after Delete 15"<<endl;
              btree.preorder( result);
                     cout<<"---------------------------------"<<endl;
    return 0;
}
