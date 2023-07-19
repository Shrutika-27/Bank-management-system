#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
class bank
{
 public:
  
  char fullname[50];
  char address[100];
  string mobileno;
  int balance,a,b;
  char atype[10];
  string password;
  string s;
  string accnumber;
  
 public:
  
  void setdata();
 	void createaccount();
 	void  login();
 	void  moneydeposit();
 	void moneywithdraw();
 	void viewdetail();
 	void updateaccount();
 
 };
void bank::setdata()
   	{
   cout<<"\nEnter your full name:";
   cin>>ws;
   cin.getline(fullname,50);
   cout<<"\nEnter your address :";
   cin>>ws;
   cin.getline(address,100);
   string temphone;
   cout<<"\n Enter your contact number :";
   cin>>temphone;
   cin.clear();
   
   if(temphone.length()==10)
   {
  	mobileno=temphone;
   }
   else{
    
    while(temphone.length()!=10)
    {
     cout<<"Phone number must be 10 digit";
     cout<<"\nenter the mobile number";
     cin>>temphone;
     mobileno=temphone;
    }
 	 }
   cout<<"\nEnter the account type Saving or current :";
   cin>>ws>>atype;
   
   cout<<"\nEnter your account number :";
  	cin>>ws>>accnumber;
   
   cout<<"\nEnter the password :";
   cin>>ws>>password;
   
   cout<<"\nEnter the initial amount to your account :";
   cin>>balance;
   
 	ofstream of("mybankfile.txt",ios::out |ios::app);
 	of<<"\n\nName of account holder :"<<fullname<<"\nAddress :"<<address<<"\nContact no:"<<mobileno<<"\nAccount type:"<<atype<<"\n Account no:"<<accnumber
 	<<"\n initial amount :"<<balance;
	
 
	of.close();
  }
 
void bank ::login()
   {
 string temp_acc;
 string temp_password;
 cout<<"\nplease enter account number and password ";
 cin>>temp_acc>>temp_password;
 
   if((temp_acc.compare(accnumber)==0) && (temp_password.compare(password)==0))
 	{
   accnumber=temp_acc;
   password=temp_password;
	 }
   else
   {
	while((temp_acc.compare(accnumber)!=0) && (temp_password.compare(password)!=0))
    	{
	
 	cout<<"It is invalid";
 	cout<<"\nplease enter valid account number and password :";
   	 cin>>temp_acc>>temp_password;
	 accnumber=temp_acc;
 	password = temp_password;
       	}
   	}
	 cout<<"\nyou have logged in successfully";
}
void bank :: createaccount()
{
 
  setdata();
  cout<<"your account is successfully created";
 
}
void bank::moneydeposit ()
{
	login();
 cout<<"\nenter the amount you want to deposit :";
 cin>>a;
 balance+=a;
 
 cout<<"\nmoney is successfully deposited :";
 cout<<"\nyour total balance :"<<balance;
 
  ofstream oof("mybankfile.txt",ios::out |ios::app);
  oof<<"\n\nmoney is deposited";
  oof<<"\ncurrent balance :"<<balance;
  oof.close();
}
void bank :: moneywithdraw()
{
 login();
 cout<<"\nenter the amount you want to withdraw";
 cin>>b;
 
 if(balance>=b)
 {
 balance-=b;
 cout<<"\nmoney is successfully withdrawed";
	}
  else
  {
    cout<<"\nyou dont have enough money to withdraw";
    cout<<"try again";
    cin>>b;
    balance-=b;
  }
 cout<<"\nyour total balance :"<<balance;
 
   ofstream off("mybankfile.txt",ios::out |ios::app);
   off<<"\n\nmoney is withdrawed";
   off<<"\ncurrent balance :"<<balance;
   off.close();
}
  
 void bank:: viewdetail()
 {
  
  cout<<"\n\nDetails of account holder";
   cout<<"\nName of account holder :"<<fullname
   <<"\nAddress :"<<address
   <<"\nContact no:"<<mobileno
   <<"\nAccount type:" <<atype
   <<"\npassword: "<<password
   <<"\n Account no:"  <<accnumber
   <<"\n  balance :"<<balance;
  
 }  
void bank::updateaccount()
{
   cout<<"enter the details";
   setdata();
   cout<<"your account is updated";
}  
  
  
 int main()
 {
   int c;
   bank b;
   cout<<endl<<setw(30);
   for(int i=1;i<=14;i++)
   {
  	 for(int j=1;j<=i;j++)
    {
     cout<<"*";
            	}
        	}
   
   cout<<endl<<setw(95)<<"WELCOME TO OUR BANK MANAGEMENT SYSTEM";
   cout<<endl<<setw(30);
   for(int i=1;i<=14;i++)
   {
  	 for(int j=1;j<=i;j++)
   {
     cout<<"*";
    }
   }
   while(1)
   {
  cout<<endl<<"1)create new account\n\n"
        	<<"2)Money deposit\n\n"
     	<<"3)Money withdraw\n\n"
     	<<"4)account enquiry\n\n"
  	<<"5)update the account\n\n"
     	<<"6)exit"<<"\nselect option you want :";
   cin>>c;
   
   switch(c)
     	  {
    case 1:b.createaccount();break;
    case 2:b.moneydeposit();break;
    case 3:b.moneywithdraw();break;
    case 4:b.viewdetail();break;
    case 5:b.updateaccount();break;
    case 6:exit(0);break;
    default:cout<<"\n invalid case";
    
        	 }
 
 	 }
}
