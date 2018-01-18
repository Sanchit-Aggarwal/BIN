#include<iostream.h>
#include<conio.h>
class node
{
public:
 int data;
 node* left;
 node* right;
node()//Constructor
{
  this->left=this->right=NULL;
}
};
void Preorder(node* n)
{
  if(n==NULL)
  return;
  else
  {
    cout<<n->data<<" ";        // Parent
    Preorder(n->left);   //Left
    Preorder(n->right); //Right
  }
}

void Inorder(node* n)
{
  if(n==NULL)
  return;
  else
  {
    Inorder(n->left);   //Left
    cout<<n->data<<" ";        // Parent

    Inorder(n->right); //Right
  }

}
void Postorder(node* n)
{
  if(n==NULL)
  return;
  else
  {
     Postorder(n->left);   //Left
     Postorder(n->right); //Right
     cout<<n->data<<" ";        // Parent


  }

}
void main()
{
clrscr();
node *Root;
char ch;
int val;
while(1)
{
cout<<"DO you want to add node to BST(y/n)?"<<endl;
ch=getch();
if(ch=='y'||ch=='Y')
 {
   node *p=new node();
   cout<<"Enter Data";
   cin>>p->data;
   if(Root==NULL)
   {
    Root=p;
   }
   else
   {
     node *loc=Root;
     while(1)
     {
       if((loc->data<=p->data) && loc->right!=NULL)
       {
	  loc=loc->right;
       }
       else if((loc->data >= p->data) && loc->left!=NULL)
       {
	  loc=loc->left;
       }
       else
       {
	  if(loc->data<=p->data)
	   {
		  loc->right=p; break;
	   }
	   else if(loc->data>=p->data)
	   {
		  loc->left=p;break;
	   }

       }
   }

 }

}
else break;
}
cout<<"INORDER:";Inorder(Root);cout<<endl;
cout<<"PRERDER:";Preorder(Root);cout<<endl;
cout<<"POSTORDER:";Postorder(Root);cout<<endl;
getch();
}

