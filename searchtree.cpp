#include <iostream>
using namespace std;

class node
{
 string key,mean;
 node* lchild;
 node* rchild;
 public:
 node(string x, string y){
     key=x; mean=y;
     lchild=rchild=NULL;
     
 } 
 friend class BST;  
};
 class BST
 {
     node* root;
     public:
     BST(){
         root=NULL;
     }
     void create(string x, string y);
     void inorder(node* t);
     void inorder(){inorder(root);};
     
     void updatemean(string word, string upd, node* t);
     void updatemean(string word, string upd){updatemean(word,upd,root);};
     
     void updatekey(string m, string upd, node* t);
     void updatekey(string m, string upd){updatekey(m,upd,root);};

     void Revinorder(node* t);
     void Revinorder(){Revinorder(root);};

     void FindM(string x, node* t);
     void FindM(string x){FindM(x,root);};


 };

 void BST::create(string x, string y)
     {
         if(root==NULL)
         {
             root=new node(x,y);
         }
         else{
             node* p;
             node* q;
             node* t;
             p=q=root;
             while(p!=NULL)
             {
                 q=p;
                 if(x < p->key)
                 {
                     p=p->lchild;
                 }
                 else{
                     p=p->rchild;
                 }
             }
             if(x< q->key)
             {
                 t=new node(x,y);
                 q->lchild=t;
             }
             else if(x>q->key)
             {
                 t=new node(x,y);
                 q->rchild=t;
             }
             else{
                 cout<<"Duplicate data"<<endl;
             }
         }
     }
void BST::inorder(node* t)
{
    if(t!=NULL)
    {
        inorder(t->lchild);
        cout<<t->key<<": "<<t->mean<<endl;
        inorder(t->rchild);
    }
}

void BST::updatemean(string word, string upd, node* t)
{
    
    if(t!=NULL)
    {
        updatemean(word,upd,t->lchild);
        if(t->key==word){t->mean=upd; return;}
        updatemean(word,upd,t->rchild);
        if(t->key==word){t->mean=upd; return;}
            
    }
}
void BST::updatekey(string m, string upd, node* t)
{
    
    if(t!=NULL)
    {
        updatekey(m,upd,t->lchild);
        if(t->mean==m){t->key=upd; return;}
        updatekey(m,upd,t->rchild);
        if(t->mean==m){t->key=upd; return;}
            
    }
}

void BST::Revinorder(node* t)
{
    if(t!=NULL)
    {
        Revinorder(t->rchild);
        cout<<t->key<<": "<<t->mean<<endl;
        Revinorder(t->lchild);
        
    }
}

void BST::FindM(string x, node* t)
{
    if(t!=NULL)
    {
        FindM(x,t->lchild);
        if(t->key==x)
        {
            cout<<"Meaning of the key is: "<<t->mean<<endl;
            return;
        }
        FindM(x,t->rchild);
        if(t->key==x)
        {
            cout<<"Meaning of the key is: "<<t->mean<<endl;
            return;
        }
    }
}




int main()
{
    BST obj;
    int n;
    cout<<"enter number of nodes you want to enter:"<<endl;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string str,mean;
        cout<<"enter key you want to enter:"<<endl;
        cin>>str;
        cout<<"enter the meaning of the key"<<endl;
        cin>>mean;
        obj.create(str,mean);
    }
   
int cho;
    do
    {
    cout<<"enter choice to perform"<<endl;
    cout<<"1. Display all words and meaning alphabetically\n2. Insert a new key\n3. Update meaning\n4. Update key\n5. Descending order\n6. Find the meaning of Key"<<endl;
    
    cin>>cho;

    switch(cho)
    {
        case 1:
        obj.inorder();
        break;

        case 2:
        {string k,m;
        cout<<"enter key and meaning"<<endl;
        cin>>k>>m;
        obj.create(k,m);
        break;}

        case 3:
        {string word,upd;
        cout<<"enter for which key you want to update the meaning:"<<endl;
        cin>>word;
        cout<<"enter new meaning"<<endl;
        cin>>upd;
        obj.updatemean(word,upd);
        break;}
        
        case 4:
        {string m,upd;
        cout<<"enter for which meaning you want to update the key:"<<endl;
        cin>>m;
        cout<<"enter new key"<<endl;
        cin>>upd;
        obj.updatekey(m,upd);
        break;
            
        }

        case 5:
        {
          obj.Revinorder();
          break;
        }

        case 6:
        {
            string k;
            cout<<"enter key of which meaning you want to find"<<endl;
            cin>>k;
            obj.FindM(k);
            break;
        }

    }
    } while(cho!=-1);

    return 0;

}