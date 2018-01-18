#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<process.h>
class sale;
class stock
{
 int item_no;
 char item_name[20];
 float cost_price,sell_price;
 int warr_period;
 int stock_status;
public:
 void getdata();
 void showdata();
 int stock_search(stock &,int);
 void stock_update(int);
 void show_all_stock();
 int get_no();
 int item_noo()
  {
    return item_no  ;
  }
 int sell_pricee()
  {
   return sell_price;
  }
 int stock_statuss()
  {
   return stock_status;
  }
 void item()
  {
   cout<<item_name;
  }
 void stock_reduce(sale);
 void quan_up(int a)
  { 
    stock_status-=a;
  }
};
class sale
{
 int item_no;
 int quantity;
 public:
 void getdata();
 int item_noo()
  {
    return item_no;
  }
 int quantityy()
  {
    return quantity;
  }
};
class invoice
{
 int invoice_no;
 char customer_name[20];
 float bill_amount;
 int items_purchased;
 int d1,d2,m1,m2,y1,y2,y3,y4,dd,mm,yyyy;
public:
 invoice()
 {
   bill_amount=items_purchased=0;
 }
 void getdata(sale[],int);
 void showdata();
 int total_purchase()
  {
   return items_purchased;
  }
 int get_inv_no();
 int invoice_noo()
  {
    return invoice_no;
  }
 int invoice_fetch(invoice&,int);
};
void stock :: getdata()
{
 clrscr();
 cout<<"Enter item no. ";cin>>item_no;
 cout<<"\nEnter item name ";gets(item_name);
 cout<<"\nEnter cost price ";cin>>cost_price;
 cout<<"\nEnter Selling Price ";cin>>sell_price;
 cout<<"\nEnter Warranty duration in years ";cin>>warr_period;
 cout<<"\nEnter no. of articles in stock ";cin>>stock_status;
}
void stock::showdata()
{
 cout<<"\nItem no.                      ";cout<<item_no;
 cout<<"\nItem name                     ";puts(item_name);
 cout<<"Cost price                    ";cout<<cost_price;
 cout<<"\nSelling Price                 ";cout<<sell_price;
 cout<<"\nWarranty duration in years    ";cout<<warr_period;
 cout<<"\nNo. of articles in stock      ";cout<<stock_status;
}
int stock :: stock_search(stock &o1,int n)
{
 int flag=0;
 ifstream f1("stock.dat" ,ios::binary);
 while(f1.read((char *)&o1,sizeof(o1)))
   if(o1.item_no==n)//*************************************************************
     {
       flag=1;
       f1.close();
       break;
     }
 return flag;
}
void stock :: stock_update(int n)
{
 stock o1;char ch;
 ifstream f1("stock.dat",ios::binary);
 while(f1.read((char *)&o1,sizeof(o1)))
  {
   if(o1.item_no==n)//**************************************************************
     {
       f1.close();
        break;
     }
   } 
 clrscr();
 o1.showdata();
 cout<<"\n\nDo you want to update this Product data??(Y/N) ";
 do
   {
     ch=getch();
   }while(!(ch=='n'||ch=='N'||ch=='y'||ch=='Y'));
 if(ch=='y'||ch=='Y')
  {
    stock a;
    clrscr();
    ifstream f1("stock.dat",ios::binary);
    ofstream f2("temp1.dat",ios::binary);
    while(f1.read((char *)&a,sizeof(a)))
     {
       if(a.item_no==n)
        {
          cout<<"Enter new data\n\n";
           a.getdata();
          f2.write((char *)&a,sizeof(a));
        }
       else
        {
          f2.write((char *)&a,sizeof(a));
        }
    }
 f1.close();f2.close();
 remove("stock.dat");
 rename("temp1.dat","stock.dat");
 cout<<"\n\nUpdation Completed Sucessfully!!!\n\n";
  }
}
int stock::get_no()
 {
   ifstream f1("stock.dat",ios::binary);
   f1.seekg(0,ios::end);
   int n=f1.tellg()/sizeof(stock);
   f1.close();
   return n;
}
void stock :: show_all_stock()
{
  stock o1;
  ifstream f1("stock.dat",ios::binary);
  f1.seekg(0,ios::end);
  if((f1.tellg())/(sizeof(o1))==0) 
   {
     cout<<"NO RECORDS FOUND!!!";return;
   }
 f1.seekg(0);
 while(f1.read((char *)&o1,sizeof(o1)))
    {
      o1.showdata();
      cout<<endl;
    }
 f1.close();
}

void sale :: getdata()
{
 clrscr();
 cout<<"Enter item no. ";cin>>item_no;
 cout<<"Enter Quantity ";cin>>quantity;
}
void stock :: stock_reduce(sale o)
{
  stock a;
  ifstream f1("stock.dat",ios::binary);
  ofstream f2("temporary.dat",ios::binary);
  while(f1.read((char*)&a,sizeof(a)))
   {
     if(o.item_noo()==a.item_noo())
      {
       a.quan_up(o.quantityy());
      }
      f2.write((char*)&a,sizeof(a));
   }
 f1.close();
 f2.close();
 remove("stock.dat");
 rename("temporary.dat","stock.dat");
}

void invoice :: getdata(sale o1[],int n)
{
 clrscr();
 ifstream f1("invoice.dat",ios::binary);
 f1.seekg(0,ios::end);
 invoice_no=((f1.tellg()/sizeof(invoice))+1);
 f1.close();
 cout<<"\nEnter Customer name ";gets(customer_name);
 cout<<"Enter date of purchase(dd/mm/yyyy) ";
 d1=(getche()-'0');d2=(getche()-'0');cout<<"/";
 m1=(getche()-'0');m2=(getche()-'0');cout<<"/";
 y1=(getche()-'0');y2=(getche()-'0');y3=(getche()-'0');y4=(getche()-'0');cout<<endl;
 dd=d1*10+d2;
 mm=m1*10+m2;
 yyyy=y1*1000+y2*100+y3*10+y4;
 for(int i=0;i<n;i++)
  {
    stock o2;
    ifstream f2("stock.dat",ios::binary|ios::app);
    while(f2.read((char *)&o2,sizeof(o2)))
       if(o2.item_noo()==o1[i].item_noo())
         break;
    f2.close();//------------------------------------------------
    if((o2.stock_statuss())==0)
     {
       cout<<"\n\nTHE ITEM ";o2.item();cout<<" IS CURRENTLY OUT OF STOCK!!!\nHit any key to continue\n";
       getch();
     }

   else if(((o2.stock_statuss())<o1[i].quantityy()))
           {
              cout<<"\n\nSORRY!! Requested Quantity is Not Available in stock!!!\n\nHit any key to continue with purchase!!!";
              getch();
           } 
   else
    { 
      items_purchased++;
      bill_amount+=((o2.sell_pricee())*(o1[i].quantityy()));
      o2.stock_reduce(o1[i]);
    }
 f2.close();
 }
}
void invoice::showdata()
 {
 clrscr();
 cout<<"\nInvoice No.                 ";cout<<invoice_no;
 cout<<"\nInvoice date                ";printf("%d/%d/%d",dd,mm,yyyy);
 cout<<"\nCustomer Name.              ";puts(customer_name);
 cout<<"\nTotal amount to be paid: RS.";cout<<bill_amount;
 cout<<"\n                  Thanks For Shopping With Us!!!";
 }
int invoice :: get_inv_no()
{
 ifstream f1("invoice.dat",ios::binary);
 f1.seekg(0,ios::end);
 int n=f1.tellg()/sizeof(invoice);
 f1.close();
 return n;
}
int invoice::invoice_fetch(invoice &o1,int n)
 {
  int flag=0;
  ifstream f1("invoice.dat" ,ios::binary);
  while(f1.read((char *)&o1,sizeof(o1)))
  if(o1.invoice_noo()==n)
   {
    flag=1;
    f1.close();
    break;
   }
 return flag;
}
void main()
{
 clrscr();
 char a;int i,n;char ch='y';
 do
  {
   clrscr();
   cout<<"                           WELCOME!!!!!!\n\n";
   cout<<"1.Add new item to stock\n2.Sale\n3.Get stock info\n";
   cout<<"4.Update Stock info\n5.Total items in stock\n";
   cout<<"6.Display All items in stock\n7.Fetch Invoice Data\n";
   cout<<"8.Get total no. of invoices generated\n9.Exit\n\n";
    do
      {
        a=getch();a=a-'0';
      }while(!(a==1||a==2||a==3||a==4||a==5||a==6||a==7||a==8||a==9));
 switch(a)
   {
    case 1:
     {
       clrscr();
       stock o1;
       o1.getdata();
       ofstream f1("stock.dat",ios::binary|ios::app);
       f1.write((char *)&o1,sizeof(o1));
       f1.close();break;
     }
   case 2:
    {
     clrscr();
     invoice o3;sale o2[10];
     clrscr();
     cout<<"How many Distinct items are there in basket(Max 10)?";cin>>n;
     for(i=0;i<n;i++)
      {
       clrscr();
       o2[i].getdata();
      }
    o3.getdata(o2,n);clrscr();
    ofstream f3("invoice.dat",ios::binary|ios::app);
    if((o3.total_purchase())==0)
       {
         cout<<"\nNO PURCHASE MADE!!Sorry for inconvinience!\n";
         break;
       }
   f3.write((char *)&o3,sizeof(o3));
   f3.close();
   clrscr();
   o3.showdata();
   break;
   }  
   case 3:  
    {
     stock o1;
     clrscr();
     int flag;
     cout<<"Enter item no. of product whose data is to be fetched ";
     cin>>n;
     flag=o1.stock_search(o1,n);
     if(flag==1)
      {
        clrscr();
        o1.showdata();
      }
     else
     cout<<"\nProduct Not Found!!!\n";
     break;
    }
   case 4:
    {
      clrscr();
      cout<<"Enter Product no. of item to be updated ";
      int n;
      cin>>n;
      stock o5;
      o5.stock_update(n);break;
    }
   case 6:
     {
      clrscr();
      stock o1;
      o1.show_all_stock();
      break;
     }
  case 5:
     {
      stock o1;
      clrscr();
      int g=o1.get_no();
      cout<<"No.of items are "<<g;
      break;
    }
  case 7:
     {
      invoice o1;
      clrscr();
      int flag;
      cout<<"Enter invoice no. of whose data is to be fetched ";
      cin>>n;
      flag=o1.invoice_fetch(o1,n);
      if(flag==1)
       {
        clrscr();
        o1.showdata();
      }
      else
       cout<<"Invoice Data Not Found!!!\n";
     break;
    }
  case 8:
   {
      invoice o1;
      clrscr();
      int a=o1.get_inv_no();
      cout<<"Total no of invoices generated are  "<<a;
      break;
   }
 case 9: exit(0);
 }
  cout<<"\n\n\nDo you Wanna Continue(Y/N)? " ;
  do
    {
      ch=getch();
    }while(!(ch=='y'||ch=='Y'||ch=='n'||ch=='N'));
 }while(ch=='y'||ch=='Y');
}