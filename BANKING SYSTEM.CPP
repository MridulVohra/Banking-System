
/*         ##################################################
	   ################################################## */


#include<fstream.h>     //To create input and output streams
#include<conio.h>       //To use clrscr and getch functions
#include<string.h>      //To handle sting functions
#include<stdio.h>       //To use gets()
#include<process.h>     //To use Exit function
#include<dos.h>         //To use delay function

//Global Data Members
long id;
long acc;
struct ddate
{int dd;int mm;int yyyy;};
//_______________________________________________________________________


class bank            //Base Class
{ protected:
	     char name[20];
	     char add[30];
	     char pwd[10];
	     char no[11];
	     ddate dob;

   public:
	   bank()   //Constructor
	       { strcpy(name," ");
		 strcpy(add," ");
		 dob.dd=0;
		 dob.mm=0;
		 strcpy(no," ");
		  }



      };   //Base Class Ends
//_______________________________________________________________________

	//Derived Class

class customer : protected bank
{long accno; float fd;
 float bal;
 public: customer()      //Constructor
	 {accno=0;
	  bal=0.0;
	  fd=0.0;
	  }

	int geta()     //To Access acc.dat and return a new Account Number
	 { ifstream mf; int a;
	   mf.open("acc.dat");
	    int temp;
	      mf>>temp;
	      a=temp;
	      mf.close();
	    ofstream mf1;
	    mf1.open("acc.dat");
	      temp+=1;
	      mf1<<temp;
	      mf1.close();
	    return a;
	     }

	 void getcdata()    //To input Account Details
	 {cout<<"\n\tEnter Name : ";
	  gets(name);
	  cout<<"\n\tEnter Address : ";
	  gets(add);
	  accno=geta();
	  cout<<"\n\tAccount Number : "<<accno;
	  cout<<"\n\tEnter Date of Birth (dd/mm/yyyy)";
	  cin>>dob.dd;
	  cin>>dob.mm;
	  cin>>dob.yyyy;
	  cout<<"Enter Opening Balance " ;
	  cin>>bal;
	  cout<<"Enter the Mobile Number : ";
	  gets(no);
	  cout<<"Enter Password : ";
	  gets(pwd);

	  }

	  void showdata()    //To show account details
	  {
	    cout<<"\n\n\tName : "<<name;
	    cout<<"\n\tAddress : "<<add;
	    cout<<"\n\tAccount Number : "<<accno;
	    cout<<"\n\tDate of Birth : "<<dob.dd<<"/"<<dob.mm<<"/"<<dob.yyyy;
	    cout<<"\n\tAvailable Balance : "<<bal;
	    cout<<"\n\tFixed Deposit : "<<fd;
	    cout<<"\n\tMobile Number : "<<no<<'\n';
	   }

	  int getaccno()
	  {return accno;}

	  char* getname()
	  {return name;}

	  char* getadd()
	  {return add;}

	  char* getpwd()
	  {return pwd;}

	  void setmon(float mon)
	  {bal=bal+mon;
	    }

	  void setfd(float mon)
	  {fd=fd+mon;
	  }

	  void subfd(float mon)
	  {fd=fd-mon;}

	  float getfd()
	  {return fd;}

	  float getbal()
	  {return bal;}

	  void submon(float mon)
	  {bal -= mon ;}

	  void inadd()
	  {gets(add);
	   }

	    char* get_no()
	    {return no;}

	    void inno()
	    {cin>>no;}

	    void inpwd()
	    {gets(pwd);}

	   void preset()     //To load default value when program is reset
	    {
	      ofstream mf;
	      mf.open("acc.dat");
	      mf<<101;
	      mf.close();
	       }

	   };
			//Derived Class Ends
//______________________________________________________________________

		  //Second Derived Class

class staff : protected bank
 { protected : int idno;
	       char post[10];
   public :    staff()                  //Constructor
	       {
		 strcpy(post," ");
		  }



	 int geti()  //To Access id.dat and return New ID Number
	 { ifstream mf; int i;
	   mf.open("id.dat");
	    int temp;
	      mf>>temp;
	      i=temp;
	      mf.close();
	    ofstream mf1;
	    mf1.open("id.dat");
	      temp+=1;
	      mf1<<temp;
	      mf1.close();
	    return i;
	     }


	 void getsdata()   //Input Details
	 {cout<<"\n\tEnter Name : ";
	  gets(name);
	  cout<<"\n\tEnter Address : ";
	  gets(add);
	  idno = geti();
	  cout<<"\n\tId Number Number : "<<idno;
	  cout<<"\n\tEnter Date of Birth (dd/mm/yyyy) : ";
	  cin>>dob.dd;
	  cin>>dob.mm;
	  cin>>dob.yyyy;
	  cout<<"\n\tEnter Post : ";gets(post);
	  cout<<"Entrer Mobile Number : ";gets(no);
	  cout<<"\n\tEnter Password : ";
	  gets(pwd);

	  }

	  void showdata1()    //Display Details
	  {
	    cout<<"\n\n\tName : "<<name;
	    cout<<"\n\tAddress : "<<add;
	    cout<<"\n\tID Number : "<<idno;
	    cout<<"\n\tDate of Birth : "<<dob.dd<<"/"<<dob.mm<<"/"<<dob.yyyy;
	    cout<<"\n\tMobile Number : "<<no;
	   }




	 int getid()
	 {return idno;}

	 char* getname()
	 {return name;}

	 char* getpost()
	 {return post;}

	 char* getadd()
	 {return add;}

	 char* getpwd()
	 {return pwd;}

	 char* get_no()
	 {return no;}

	 void inno()
	 {cin>>no;}

	  void inpwd()
	   {gets(pwd);}

	void inadd()
	  {gets(add);
	   }
   void preset()         //To load Default Vaule when program is reset

  {
   ofstream mf;
   mf.open("id.dat");
   mf<<101;
   mf.close();

   }


   };                  //Second Derived Class Ends
//______________________________________________________________________





void createstaff()
{ ofstream mf;char ch;
   mf.open("staff.dat",ios::binary | ios::app);
   if(!mf)
    {cout<<"Stream Not Creted";
     getch();
     exit(0);
     }
   staff s;
	s.getsdata();
	mf.write((char*) & s,sizeof(s));
	cout<<"\nCreated";
	getch();

	mf.close();
	}

void displaystaff()
{ifstream mf("staff.dat",ios::binary|ios::in);
 if(!mf)
  {cout<<"Stream Not Created ";
   getch();
   exit(0);
   }
 staff s;
 mf.read((char*)& s,sizeof(s));
 while(mf)
 {s.showdata1();
  mf.read((char*) &s,sizeof(s));
  }
  mf.close();
  }

int stafflogin()
{char p[10];
 staff s;
 ifstream mf("staff.dat",ios::binary|ios::in);
 if(!mf)
  {cout<<"Stream not Created ";
   getch();
   exit(0);
   }
 cout<<"Enter Id Number : ";cin>>id;
 cout<<"Enter Password : ";gets(p);
  int f=0;
 mf.read((char *) &s,sizeof(s));
 while(mf && f==0)
 { if(id == s.getid() && strcmp(p,s.getpwd())==0 )
   {f=1;
    long pos= mf.tellg();
    pos-= sizeof(s);
    mf.seekg(pos,ios::beg);
    s.showdata1();
    }
   mf.read((char *) &s,sizeof(s));
   }

 if(f==1)
   return 1;
   else
     return 0;
       }

void staffshowcust()
 { ifstream mf("cust1.dat",ios::binary|ios::in);
   customer c; char psd[10];
   if(!mf)
    {cout<<"Stream not Created";
     getch();
     exit(0);}
     mf.read((char*) &c,sizeof(c));
     while( mf && acc!=c.getaccno())
     mf.read((char*) &c,sizeof(c));
     if( acc== c.getaccno())
	     {	long pos= mf.tellg();
		pos-= sizeof(customer);
		mf.seekg(pos,ios::beg);
		c.showdata();
		strcpy(psd,c.getpwd());
		cout<<"\n\t\tPassword : "<<psd;
		}
		else
		cout<<"\nWrong Account Number";
		mf.close();
		}

void iddetails()
 { clrscr();
   ifstream mf("staff.dat",ios::binary|ios::in);
   staff s; char psd[10];
   if(!mf)
    {cout<<"Stream not Created";
     getch();
     exit(0);}
     mf.read((char*) &s,sizeof(s));
     while( mf && id!=s.getid())
     mf.read((char*) &s,sizeof(s));
     if( id== s.getid())
	     {	long pos= mf.tellg();
		pos-= sizeof(customer);
		mf.seekg(pos,ios::beg);
		s.showdata1();
		strcpy(psd,s.getpwd());
		cout<<"\n\t\tPassword : "<<psd;
		}
		else
		cout<<"\nWrong ID Number";
		mf.close();
		}


void updatecustadd()
{

 fstream mf; long pos;
 mf.open("cust1.dat",ios::binary|ios::in|ios::out);
 if(!mf)
 {cout<<"Stream Not Created"<<'\n';
  exit(0);         }

   customer c;
   int f=0;
   mf.read((char *) &c,sizeof(customer));
   while(mf && f==0)
     { if(acc == c.getaccno())
       {f=1;
	long pos= mf.tellg();
	pos-= sizeof(customer);
	mf.seekg(pos,ios::beg);

   cout<<"\nName : "<<c.getname()<<'\n';
   cout<<"\nOld Adress : "<<c.getadd();
   cout<<"\nEnter New Address : ";c.inadd();
  mf.write((char *) &c,sizeof(customer));
			  }
  mf.read((char*) &c,sizeof(c)); }
   if(f==0)
   cout<<"Not found";
    mf.close();
		}
void update_custno()
{
 fstream mf; long pos;
 mf.open("cust1.dat",ios::binary|ios::in|ios::out);
 if(!mf)
 {cout<<"Stream Not Created"<<'\n';
  getch();
  exit(0);         }
   customer c;
   int f=0;
   mf.read((char *) &c,sizeof(customer));
   while(mf && f==0)
     { if(acc == c.getaccno())
       {f=1;
	long pos= mf.tellg();
	pos-= sizeof(customer);
	mf.seekg(pos,ios::beg);

   cout<<"\nName : "<<c.getname()<<'\n';
   cout<<"\nOld Mobile Number : "<<c.get_no();
   cout<<"\nEnter New Mobile Number : ";c.inno();
  mf.write((char *) &c,sizeof(customer));
			  }
  mf.read((char*) &c,sizeof(c)); }
   if(f==0)
   cout<<"Not found";
    mf.close();
		}

void update_custpwd()
{
 fstream mf; long pos;
 mf.open("cust1.dat",ios::binary|ios::in|ios::out);
 if(!mf)
 {cout<<"Stream Not Created"<<'\n';
  getch();
  exit(0);         }
   customer c;
   int f=0;
   mf.read((char *) &c,sizeof(customer));
   while(mf && f==0)
     { if(acc == c.getaccno())
       {f=1;
	long pos= mf.tellg();
	pos-= sizeof(customer);
	mf.seekg(pos,ios::beg);

   cout<<"\nName : "<<c.getname()<<'\n';
   cout<<"\nOld Password : "<<c.getpwd();
   cout<<"\nEnter New Mobile Number : ";c.inpwd();
  mf.write((char *) &c,sizeof(customer));
			  }
  mf.read((char*) &c,sizeof(c)); }
   if(f==0)
   cout<<"Not found";
    mf.close();
		}


void update_staffno()
{
 fstream mf; long pos;
 mf.open("staff.dat",ios::binary|ios::in|ios::out);
 if(!mf)
 {cout<<"Stream Not Created"<<'\n';
  getch();
  exit(0);         }
   staff s;
   int f=0;
   mf.read((char *) &s,sizeof(s));
   while(mf && f==0)
     { if(id == s.getid())
       {f=1;
	long pos= mf.tellg();
	pos-= sizeof(s);
	mf.seekg(pos,ios::beg);

   cout<<"\nName : "<<s.getname()<<'\n';
   cout<<"\nOld Mobile Number : "<<s.get_no();
   cout<<"\nEnter New Mobile Number : ";s.inno();
  mf.write((char *) &s,sizeof(s));
			  }
  mf.read((char*) &s,sizeof(s)); }
   if(f==0)
   cout<<"Not found";
    mf.close();
		}

void update_staffpwd()
{
 fstream mf; long pos;
 mf.open("staff.dat",ios::binary|ios::in|ios::out);
 if(!mf)
 {cout<<"Stream Not Created"<<'\n';
  getch();
  exit(0);         }
   staff s;
   int f=0;
   mf.read((char *) &s,sizeof(s));
   while(mf && f==0)
     { if(id == s.getid())
       {f=1;
	long pos= mf.tellg();
	pos-= sizeof(s);
	mf.seekg(pos,ios::beg);

   cout<<"\nName : "<<s.getname()<<'\n';
   cout<<"\nOld Password : "<<s.getpwd();
   cout<<"\nEnter New Password : ";s.inpwd();
  mf.write((char *) &s,sizeof(s));
			  }
  mf.read((char*) &s,sizeof(s)); }
   if(f==0)
   cout<<"Not found";
    mf.close();
		}


void update_staffadd()
{
 fstream mf; long pos;
 mf.open("staff.dat",ios::binary|ios::in|ios::out);
 if(!mf)
 {cout<<"Stream Not Created"<<'\n';
  getch();
  exit(0);         }
   staff s;   int f=0;
   mf.read((char *) &s,sizeof(s));
   while(mf && f==0)
     { if(id == s.getid())
       {f=1;
	long pos= mf.tellg();
	pos-= sizeof(s);
	mf.seekg(pos,ios::beg);

   cout<<"\nName : "<<s.getname()<<'\n';
   cout<<"\nOld Adress : "<<s.getadd();
   cout<<"\nEnter New Adress : ";s.inno();
  mf.write((char *) &s,sizeof(s));
			  }
  mf.read((char*) &s,sizeof(s)); }
   if(f==0)
   cout<<"Not found";
    mf.close();
		}


void deleteid(long num)
 {

  ifstream oldfile; staff s;
  oldfile.open("staff.dat",ios::binary|ios::in);
   if(!oldfile)
    {cout<<"Stream Not Created";getch();exit(0);}
  ofstream newfile;
  newfile.open("staff2.dat",ios::binary|ios::out);
    int f=0;
    oldfile.read((char *) &s,sizeof(s));
    while(oldfile)
      { if(s.getid()!=num)
	  newfile.write((char *) &s,sizeof(s));
	else
	  f=1;
	oldfile.read((char *) &s,sizeof(s));

      }
   oldfile.close();
   newfile.close();
   remove("staff.dat");
   rename("staff2.dat","staff.dat");
    if(f==1)
     cout<<"Deleted";
    else cout<<"Not found";
  }



void createcust()
 { ofstream mf;char ch;
   mf.open("cust1.dat", ios:: binary | ios:: app);
   if(!mf)
    {cout<<"Stream Not Creted";
     getch();
     exit(0);
     }
   customer c;
	c.getcdata();
	mf.write((char*) & c,sizeof(c));
	cout<<"\nCreated";
	getch();

	mf.close();
	}

void displaycust()
{ifstream mf("cust1.dat",ios::binary|ios::in);
 if(!mf)
  {cout<<"Stream Not Created ";
   getch();
   exit(0);
   }
 customer c;
 mf.read((char*)& c,sizeof(c));
 while(mf)
 {c.showdata();
  mf.read((char*) &c,sizeof(c));
  }
  mf.close();
  }

int custlogin()
{char p[10];
 customer c;
 ifstream mf("cust1.dat",ios::binary|ios::in);
 if(!mf)
  {cout<<"Stream not Created ";
   getch();
   exit(0);
   }
 cout<<"Enter Account Number : ";cin>>acc;
 cout<<"Enter Password : ";gets(p);
 int f=0;
 mf.read((char *) &c,sizeof(c));
 while(mf && f==0)
 { if(acc == c.getaccno() && strcmp(p,c.getpwd())==0 )
   { f=1;
		long pos= mf.tellg();
		pos-= sizeof(customer);
		mf.seekg(pos,ios::beg);
		c.showdata();

	}
   mf.read((char *) &c,sizeof(c));
   }

 if(f==1)
 return 1;
  else return 0;
       }


void addmoney()
 { fstream mf;
   mf.open("cust1.dat",ios::binary|ios::in|ios::out);
   if(!mf)
    {cout<<"Strea Not Created";
     getch();
     exit(0);
     }
   customer c;
   mf.read((char*) &c,sizeof(c));
   while(mf && acc!=c.getaccno())
   mf.read((char*) &c,sizeof(c));
   if(acc== c.getaccno())
      {
	long pos= mf.tellg();
	pos-= sizeof(customer);
	mf.seekg(pos,ios::beg);
	float mon;
	cout<<"Enter amount to be Credited : ";
	cin>>mon;
	c.setmon(mon);
	mf.write((char*) &c,sizeof(customer));
	cout<<"Credited!"<<'\n'<<"New Balance = "<<c.getbal();
       }
      else

      cout<<"Account not found";
      mf.close();
      }


void bill()
{
 fstream mf;
   mf.open("cust1.dat",ios::binary|ios::in|ios::out);
   if(!mf)
    {cout<<"Strea Not Created";
     getch();
     exit(0);
     }
   customer c;
    char name1[20];

   mf.read((char*) &c,sizeof(c));
   while(mf && acc!=c.getaccno())
   mf.read((char*) &c,sizeof(c));
   if(acc== c.getaccno())
      {
	long pos= mf.tellg();
	pos-= sizeof(customer);
	mf.seekg(pos,ios::beg);
	float mon;
	cout<<"\nEnter the Name of Organisation : ";
	gets(name1);
	cout<<"\nEnter amount to be Debited : ";
	cin>>mon;
	c.submon(mon);
	mf.write((char*) &c,sizeof(c));
	cout<<"\nDebited!"<<'\n'<<"New Balance = "<<c.getbal();
	cout<<"\nDebited to : "<<name1;
	}
   else
   cout<<"\nAccount Not Found";
  mf.close();
  }

void ft()
{fstream mf;
 mf.open("cust1.dat",ios::binary | ios::in | ios::out);
 customer c;
 long a;
 float mon;
 cout<<"\n\tEnter Account Number to which money is to be transferred : ";cin>>a;
   mf.read((char*) &c,sizeof(c));
   while(mf && a!=c.getaccno())
   mf.read((char*) &c,sizeof(c));
   if(a == c.getaccno())
    {
	long pos= mf.tellg();
	pos-= sizeof(customer);
	mf.seekg(pos,ios::beg);
     cout<<"\nEnter Money to be transferred : ";cin>>mon;
     c.setmon(mon);
     mf.write((char*) &c,sizeof(customer));
     }
    else
    {cout<<"\n\tAccount Number does not exists";
     getch();

     }
     mf.close();
     fstream mf1;
     mf1.open("cust1.dat", ios:: binary| ios::in | ios::out);
     mf1.read((char*) &c,sizeof(c));
     while(mf && acc!=c.getaccno())
     mf1.read((char*) &c,sizeof(c));
     if (acc == c.getaccno())
       {
		long pos= mf.tellg();
		pos-= sizeof(customer);
		mf.seekg(pos,ios::beg);
		c.submon(mon);
		mf.write((char*) &c,sizeof(c));
		cout<<"\nDebited!"<<'\n'<<"New Balance = "<<c.getbal();
		cout<<"\nDebited to : "<<a;
		}
	else cout<<"\nAccount Not Found";
	   mf1.close();
	   }

void enquiry()
 { ifstream mf("cust1.dat",ios::binary|ios::in);
   customer c;
   if(!mf)
    {cout<<"Stream not Created";
     getch();
     exit(0);}
     mf.read((char*) &c,sizeof(c));
     while( mf && acc!=c.getaccno())
     mf.read((char*) &c,sizeof(c));
     if( acc== c.getaccno())
	     {	long pos= mf.tellg();
		pos-= sizeof(customer);
		mf.seekg(pos,ios::beg);
		c.showdata();
		}
		else
		cout<<"\nWrong Account Number";
		mf.close();
		}
void fd()
{fstream mf;
   mf.open("cust1.dat",ios::binary|ios::in|ios::out);
   if(!mf)
    {cout<<"Stream Not Created";
     getch();
     exit(0);
     }
   customer c;
   mf.read((char*) &c,sizeof(c));
   while(mf && acc!=c.getaccno())
   mf.read((char*) &c,sizeof(c));
   if(acc== c.getaccno())
      {
	long pos= mf.tellg();
	pos-= sizeof(customer);
	mf.seekg(pos,ios::beg);
	float mon;
	cout<<"\nEnter Amount for Fixed Deposit";
	cin>>mon;
	c.submon(mon);
	c.setfd(mon);
	mf.write((char*) &c,sizeof(c));
	cout<<"\nDebited!"<<'\n'<<"New Balance = "<<c.getbal();
	cout<<"\nFixed Deposit : "<<mon;
	}
   else
   cout<<"\nAccount Not Found";
 mf.close();

  }

void fdbreak()
{fstream mf;
   mf.open("cust1.dat",ios::binary|ios::in|ios::out);
   if(!mf)
    {cout<<"Stream Not Created";
     getch();
     exit(0);
     }
   customer c;
   mf.read((char*) &c,sizeof(c));
   int f=0;
   while(mf && f==0)
   {if(acc== c.getaccno())
      { f=1;
	long pos= mf.tellg();
	pos-= sizeof(customer);
	mf.seekg(pos,ios::beg);
	float mon; int i;
	mon=c.getfd();
	c.subfd(mon);
	if(mon <= 100000)
	 { mon+= 0.08* mon;
	   i=8;}
	else
	 {mon+= 0.1 * mon;
	  i=10;}
	c.setmon(mon);
	mf.write((char*) &c, sizeof(c));
	cout<<"\n\nFixed Deposit transacted!";
	cout<<"\nNew Balance : "<<c.getbal();
	cout<<"\nAmount Credited : "<<mon;
	cout<<"\nInterest : "<<i<<"%";
	}
	mf.read((char*) &c, sizeof(c)   );
	}

   if(f==0)
     cout<<"Account Not Found";
     mf.close();
      }


void deleteacc()
 {

  ifstream oldfile; customer c;
  oldfile.open("cust1.dat",ios::binary|ios::in);
   if(!oldfile)
    {cout<<"Stream Not Created";getch();exit(0);}
  ofstream newfile;
  newfile.open("cust2.dat",ios::binary|ios::out);
   int f=0;
    oldfile.read((char *) &c,sizeof(c));
    while(oldfile)
      {if(c.getaccno()!=acc)
	newfile.write((char *) &c,sizeof(c));
       else f=1;
	oldfile.read((char *) &c,sizeof(c));
      }
   oldfile.close();
   newfile.close();
   remove("cust1.dat");
   rename("cust2.dat","cust1.dat");
    if(f==1)
     cout<<"Deleted";
    else cout<<"Not found";
  }

void reset();
void logmenu();
void custmenu();
void staffmenu();

void main()
{  textbackground(WHITE);
   textcolor(RED);
   clrscr();

   cout<<"\n\t ллллллллллллллллллллллллллллллллллллллллллллллллллллл"  ;
   cout<<"\n\t л                                                   л";
   cout<<"\n\t л      л л   л л  ллл    лппл лппл лм  л л м/       л";
   cout<<"\n\t л       л     м   м-п    мппм лммл л пмл лпм        л";
   cout<<"\n\t л      л л    л   ллл    лммп л  л л   л л  п|      л";
   cout<<"\n\t л                                                   л";
   cout<<"\n\t л                                                   л";
   cout<<"\n\t л               Bank on Your tips                   л";
   cout<<"\n\t л                                                   л";
   cout<<"\n\t л                                                   л";
   cout<<"\n\t л                                                   л";
   cout<<"\n\t л                                                   л";
   cout<<"\n\t л                                                   л";
   cout<<"\n\t ллллллллллллллллллллллллллллллллллллллллллллллллллллл"  ;
   delay(1000);

   char a; char b[20];char c[20];
   ifstream mf; ifstream nf; ofstream of;
   mf.open("bank.dat",ios::binary|ios::in);
   mf>>a; mf.close();

   if( a== 'n')
    { nf.open("vkey.dat",ios::binary|ios::in);
      cout<<"\nENTER VALIDATION KEY : ";
       gets(b);nf>>c; customer d;staff s;
       if(strcmp(c,b)==0)
	 {  of.open("bank.dat",ios::binary|ios::out);
	    of<<'y';
	    d.preset();
	    s.preset();
	    cout<<"\nCREATE STAFF ADMIN\n";
	    createstaff();
	    logmenu();
	    of.close(); nf.close();
	    }
       else
	    { cout<<"Wrong Key"; getch(); exit(0);}
	 } // outer if closed
   else logmenu();
   getch();
   } //main closed


void reset()
 { ofstream mf;
   mf.open("bank.dat",ios::binary|ios::out);
   mf<<'n';
   remove("cust1.dat");
   remove("staff.dat");
   }



  void logmenu()
 {  clrscr();
    for(int i=1;i<=50;i++)
    { clrscr();
	cout<<"\n\n\n\n\t\t\t\t   Loading "<<'\n'<<'\t'<<'\t';
	for(int j=1;j<=i;j++)
	cout<<"В";
	cout<<"\n\n\t "<<2*i<<"%";
	if( i > 1 && i < 20)
	cout<<"\n\n\tCreating Temporary files";
	else if( i > 20 && i<40)
	cout<<"\n\n\tAccessing Main Memory";
	else if(i >40 && i<48)
	cout<<"\n\n\tAccessing Cache";
	else cout<<"\n\n\tComplete. Press Enter to Continue ";
	delay(150 - i*3);
	}
  char ch;
     textcolor(BLACK);
 do{
     clrscr(); int a;
     cout<<"\n\t\t";
     textcolor(BLUE);
     cout<<"             Log in Screen";
     cout<<"\n\n\n\n\n\n\t Press 1 for Customer Login";
     cout<<"\n\n\t Press 2 for Employee Login";
     cout<<"\n\n\t Press 3 to Reset PROGRAM COMPLETELY";
     cout<<"\n\n\t Press 4 to Exit "<<'\n';
     cin>>a;
  switch(a)

   { case 1 : { clrscr();
		int b;
		b= custlogin();
		if( b== 0)
		cout<<"Wrong Input.";
		else custmenu();
		} break;

     case 2 : { clrscr();
		int b;
		b=stafflogin();
		if ( b == 0)
		cout<<"Wrong Input. ";
		else staffmenu();
		} break;
     case 3 : {  reset();
		 exit(0);
		 }
     case 4 : {  clrscr();
		 cout<<"\nThankyou For Using";
		 cout<<"\nHave a Great Day";
		 exit(0); }
		 }
		 cout<<"\nWant to go back to Login Screen? ";cin>>ch;
		 } while(ch=='y' || ch=='Y');
 getch();
 }

 void custmenu()
   { getch(); char ch;
   do{  clrscr();int a;
	cout<<"Account Number : "<<acc;
	cout<<"\n\n\tQuick Bill Pay              1";
	cout<<"\n\n\tFund Transfer               2";
	cout<<"\n\n\tAccount Status              3";
	cout<<"\n\n\tOpen Fixed Deposit          4";
	cout<<"\n\n\tClose Fixed Deposit         5";
	cout<<"\n\n\tDelete Account              6";
	cout<<"\n\n\tLOG OUT                     7";
	cout<<"\n\n\tExit program                8";
	cout<<"\n\n\tEnter Choice ";
	cin>>a;
     switch(a)
      { case 1: { clrscr();
		  cout<<"Account Number "<<acc;
		  cout<<"\n________BILL PAY_______\n";
		  bill();
		  } break;
	case 2: { clrscr();
		  cout<<"Account Number "<<acc;
		  cout<<"\n___________FUND TRANSFER___________\n";
		  ft();
		  }break;
	case 3: { clrscr();
		  cout<<"Account Number "<<acc;
		  cout<<"\n_________CHECK STATUS__________\n";
		  enquiry();
		  }break;
	case 4:{ clrscr();
		 cout<<"Account Number "<<acc;
		 cout<<"\n_________OPEN FIXED DEPOSIT________\n";
		 fd();
		 }break;
	case 5:{ clrscr();
		 cout<<"Account Number "<<acc;
		 cout<<"\n_________CLOSE FIXED DEPOSIT_________\n";
		 fdbreak();
		 }break;
	case 6: { clrscr();
		  cout<<"Account Number "<<acc; char ch;
		  cout<<"\n___________DELETE ACCOUNT_________\n";
		  cout<<"\n\nEnter y to confirm delete ";cin>>ch;
		  if(ch=='y' || ch=='Y')
		  deleteacc();
		  exit(0);
		  }break;
	case 7:   logmenu();
	case 8: { clrscr();
		  cout<<"\nThankyou For Using this Software";
		  cout<<"\nHave a Great Day";
		  getch();
		  exit(0); }
	default : continue;
	} cout<<"\nWant to Continue to Main Menu? ";cin>>ch;
	}while(ch=='y' || ch=='Y');
	getch();
	}

void staffmenu()
 { getch(); char ch;
 do{  clrscr();
      int a;
      cout<<"\n\tId Number "<<id;
      cout<<"\n\n\t\tCustomer Options               1";
      cout<<"\n\n\t\tStaff Options                  2";
      cout<<"\n\n\t\tLOG OUT                        3";
      cout<<"\n\n\t\tExit                           4";
      cout<<"\n\n\n\tEnter Choice ";cin>>a;
      switch(a)
       { case 1: { clrscr();
		   int b;cout<<"\t\tId Number : "<<id;
		   cout<<"\n\n\tOpen Account             1";
		   cout<<"\n\n\tDisplay List             2";
		   cout<<"\n\n\tCredit Money             3";
		   cout<<"\n\n\tFixed Deposit Options    4";
		   cout<<"\n\n\tDetails of Customer      5";
		   cout<<"\n\n\tUpdate Options           6";
		   cout<<"\n\n\tDelete an Account        7";
		   cout<<"\n\n\tMain Menu                8";
		   cout<<"\n\n\tEnter Choice : "; cin>>b;
		     switch(b)
		       { case 1: { clrscr();
				   cout<<"ID Number : "<<id;
				   cout<<"\n______Open Account______\n";
				   createcust();
				   }break;
			 case 2: { clrscr();
				   cout<<"ID Number : "<<id;
				   cout<<"\n_____Customer List_____\n";
				   displaycust();
				   }break;
			 case 3: { clrscr();
				   cout<<"ID Number : "<<id;
				   cout<<"\n_____Credit Money_____\n";
				   cout<<"\nEnter the Account Number : ";
				   cin>>acc;
				   addmoney();
				   }break;
			 case 4: { clrscr();
				   cout<<"ID Number : "<<id;
				   cout<<"\n______Fixed Deposit_____\n";
				   cout<<"\nEnter Account Number : ";
				   cin>>acc;
				   int c;
				   cout<<"\nOpen FD     1";
				   cout<<"\nClose FD    2";
				   cout<<"\nEnter Choice ";
				   cin>>c;
				   switch(c)
				    {case 1 : {clrscr();
					       fd();}break;
				     case 2 : {clrscr();
					       fdbreak();}break;
				     }
				   }break;

			 case 5 : { clrscr();
				    cout<<"ID Number : "<<id;
				    cout<<"\n________Customer Detail_________\n";
				    cout<<"Enter Account Number of Customer ";cin>>acc;
				    staffshowcust();
				   }break;

			 case 6 : { clrscr();
				     int d;
				     cout<<"ID Number : "<<id;
				     cout<<"\n_______Customer Update Menu_________\n";
				     cout<<"Enter Account Number ";cin>>acc;
				     cout<<"\nAddress           1";
				     cout<<"\nMobile Number     2";
				     cout<<"\nPassword          3";
				     cout<<"\nEnter Choice ";cin>>d;
				     switch(d)
				      {  case 1: { clrscr();
						   cout<<"ID Number "<<id;
						   cout<<"\n__Address Updation__\n";
						   updatecustadd();
						  }break;
					 case 2: { clrscr();
						   cout<<"ID Number "<<id;
						   cout<<"\n___Number Updation___\n";
						   update_custno();
						 }break;
					 case 3: { clrscr();
						   cout<<"ID Number "<<id;
						   cout<<"\n___Password Updation___\n";
						   update_custpwd();
						   }break;

					    }
					 }break;

			 case 7: {  clrscr();
				    cout<<"ID Number : "<<id; char ch;
				    cout<<"\n_____DELETE ACCOUNT_____\n";
				    cout<<"\n\n\t\Enter the Account Number : ";
				    cin>>acc;
				    cout<<"\nEnter yes to confirm delete ";
				    cin>>ch;
				    if( ch=='y' || ch=='Y')
				    deleteacc();
				  }break;
			 case 8 : break;
			 default : continue;
				}
		    }break;

	 case 2: { clrscr();
		   int e;cout<<"\t\tID Number : "<<id;
		   cout<<"\n\n\tOpen Staff ID       1";
		   cout<<"\n\n\tStaff List          2";
		   cout<<"\n\n\tDetails             3";
		   cout<<"\n\n\tUpdate Menu         4";
		   cout<<"\n\n\tDelete ID           5";
		   cout<<"\n\n\tMain Menu           6";
		   cout<<"\n\n\tEnter Choice  ";cin>>e;
		   switch(e)
		    {case 1:{ clrscr();
			      cout<<"ID Number : "<<id;
			      cout<<"\n_____Creation of ID_____\n";
			      createstaff();
			    }break;
		     case 2:{ clrscr();
			      cout<<"ID Number : "<<id;
			      cout<<"\n____Staff Display List____\n";
			      displaystaff();
			    }break;
		     case 3: { clrscr();
			       cout<<"ID Number : "<<id;
			       cout<<"\n____ID Details____\n";
			       iddetails();
			      }break;
		     case 4: { clrscr();
				int f;
				cout<<"ID Number : "<<id;
				cout<<"\n_______Staff Update Menu_________\n";
				cout<<"\nAddress           1";
				cout<<"\nMobile Number     2";
				cout<<"\nPassword          3";
				cout<<"\nEnter Choice ";cin>>f;
				switch(f)
				 { case 1: { clrscr();
					     cout<<"ID Number "<<id;
					     cout<<"\n__Address Updation__\n";
					     update_staffadd();
					    }break;
				   case 2: { clrscr();
					     cout<<"ID Number "<<id;
					     cout<<"\n___Number Updation___\n";
					     update_staffno();
					    }break;
				   case 3: { clrscr();
					     cout<<"ID Number "<<id;
					     cout<<"\n__Password Updation__\n";
					     update_staffpwd();
					    }break;

				    }

			       }break;

		     case 5: {  if(id!=101)
				 { cout<<"\nNot Authorised. Kindly Contact Admin";
				   cout<<"\nDirecting to Login Screen press Enter";
				   getch();
				   logmenu();}
				 clrscr();
				 cout<<"ID Number : "<<id;
				 char ch; long num;
				 cout<<"\n__________DELETE ID__________\n";
				 cout<<"\n\nEnter Id to be Deleted : ";cin>>num;
				 cout<<"\n\nEnter y to confirm delete ";
				 cin>>ch;
				 if(ch=='y' || ch=='Y')
				 deleteid(num);
			   }break;
		     case 6: break;
		     default : continue;
		     }
	   }break;
	case 3 : logmenu();
	case 4 : { clrscr();
		   cout<<"Thankyou For Using this Software";
		   cout<<"\nHave a Great Day";
		   getch();
		   exit(0);}
	default :continue;

	 } cout<<"\n\tWant to Continue to Main Menu? ";cin>>ch;
	 }while(ch=='y' || ch=='Y');

	 getch();
	 }