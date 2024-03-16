#include<iostream>
#include<fstream>
using namespace std;
struct bank
{
	fstream file1,file2,file3;
	int ano,account;
	float balance ;
	char name[20];

public:
	void open();
	void deposit(int);
	void withdraw(int);
	void search(int);
	void display();

};
// FOR OPENING AN ACCOUNT
void bank::open(){

	file1.open("NEW ACCOUNTS.txt",ios::app);
	while(!file1.eof())
	{
	cout<<"ENTER THE USER NAME: ";
	cin>>name;
	file1<<"NAME: "<<name<<"\n";
	cout<<"ENTER YOUR NEW ACCOUNT PIN: ";
	cin>>account;
	file1<<"ACCOUNT PIN: "<<account<<"\n";
    balance=1000;
    cout << "YOUR ACCOUNT HAS BEEN CREATED SUCCESSFULLY \n YOU HAVE 1000 RS IN YOUR ACCOUNT \n THANK YOU \n \n";
	file1<<"Rs. "<<balance<<"\n";
	cout<<"\n";
	file1<<"\n";
	file1.close();
	break;
}
//FOR DEPOSIT OF MONEY
	}
void bank::deposit(int j)
{
	
	file2.open("DEPOSIT.txt",ios::out);
	int bnc,r;

	
	if (account == j)
	{
		cout<<"ENTER THE AMOUNT OF MONEY YOU WANT TO DEPOSIT: ";
		cin>>bnc;
		file2<<bnc<<" IS DEPOSITED IN ACCOUNT# "<<account<<endl;
		balance+=bnc;
		cout<<"YOUR AMOUNT HAS BEEN DEPOISTED SUCCESSFULLY  \n";

		file2<<"NEW BALANCE IN ACCOUNT# "<<account<<" is: "<<balance;
	}
	file2.close();
	
}
// FOR WITHDRAW OF MONEY

void bank::withdraw(int k)
{
	file3.open("WITHDRAW.txt" , ios :: out);
	int blnc,p;
	if(account == k)
	{
		cout<<"YOUR CURRENT BALANCE IS: "<<balance<<"\n";
		cout<<"ENTER AMOUNT OF MONEY YOU WANT TO WITHDRAW: ";
		cin>>blnc;
		if (blnc>500)
		{
		
		p=balance-blnc;
		cout<<"\n";
		
		
		if(p<0)
		{
			cout<<"SORRY YOU DONT HAVE ENOUGH MONEY IN YOUR ACCOUNT \n \n";
		}
		
		else if(p>=0)
		{
			cout<<"YOUR AMOUNT HAS BEEN WITHDRAWN SUCCESSFULLY  \n";
			file3<<blnc<<" MONEY HAS BEEN WITHDRAWN FROM ACCOUNT# "<<account<<endl;
			balance=p;
			file3<<"REMAINING BALANCE IS Rs: "<<balance;
			
		}
	}
	else
	  cout<<"SORRY CAN NOT WITHDRAW LESS THAN 500 \n";
	}
	file3.close();
}

void bank::display(void)
{
	file1.open("NEW ACCOUNT.txt", ios::in);


				cout<<"NAME: "<<name<<"\n"<<"ACCOUNT NO. : "<<account<<"\n"<<"BALANCE :"<<balance<<"\n";


file1.close();
}
void bank::search(int m)
{
	if (account == m)
	{
		file1.open("NEW ACCOUNT.txt",ios::in);
		cout<<"			ACCOUNT HOLDER's INFO				\n";
		cout<<"NAME: "<<name<<"\n"<<"ACCOUNT NO. : "<<account<<"\n"<<"BALANCE :"<<balance<<"\n";
		cout<<"........................................................................\n";
	}
	else
	{
		cout<<"SORRY NO ACCOUNT FOUND FROM THIS INFO ";
	}
}

int main ()
{
	int j,k,m,l,y=0;
	bank b[20];
	int opt;
	cout<<"\n                                         WELCOME TO MY BANK  \n \n \n" ;
	
	do
	{
		cout<"                MAIN MENU \n \n ";
		cout<<"TO OPEN A NEW ACCOUNT PRESS...............1  \n\n";
		cout<<"TO DEPOSIT MONEY PRESS....................2  \n\n";
		cout<<"TO WITHDRAW MONEY PRESS...................3  \n\n";
		cout<<"FOR INFORMATION OF ALL ACCOUNTS PRESS.....4  \n\n";
		cout<<"TO SEARCH ANY ACCOUNT PRESS ..............5         \n \n";
		cout<<"TO EXIT...................................6 \n \n";
		cout<<"                                    PLEASE  SELECT AN OPTION FROM 1-6 :: \n "<<endl;
		cin>>opt;
		switch (opt)
		{
		 case 1:
			{
				cout<<"\n";
					cout<<"HOW MANY ACCOUNTS U WANT TO OPEN: ";
					cin>>y;
					for (int i=0 ; i<y ; i++)
					{
						
						b[i].open();
						cout<<"PLEASE ENTER INFROMATION FOR NEXT ACCOUNT \n";
					}
					cout<<"\n";
					break;
			}
			
			case 2:
				{cout<<"\n";
					cout<<"ENTER YOUR ACCOUNT PIN. :";
					cin>>j;
					for (int i=0 ; i<y ; i++)
					{
						b[i].deposit(j);
						
					}
					cout<<"\n";
					break;
				}
			
			case 3:
				{cout<<"\n";
				    cout<<"ENTER YOUR  ACCOUNT PIN. :";
					cin>>k;
					
					for (int i=0 ; i<y ; i++)
					{
						b[i].withdraw(k);
					}
					cout<<"\n";
					break;
				}
			
			case 4:
				{cout<<"\n";
					for (int i=0 ; i<y ; i++)
					{
						b[i].display();
						
					}
					cout<<"\n";
					break;
				}
			
			case 5:
				{cout<<"\n";
					cout<<"ENTER ACCOUNT PIN :";
					cin>>m;
					for (int i=0 ; i<y ; i++)
					{
						b[i].search(m);
					}
					cout<<"\n";					
					break;
				}
			case 6:
				{ 
				  cout<< "                                      THANKS FOR BANKING WITH US \n ";
				  cout<< "                                          HAVE A GOOD DAY \n"; 
				  cout<< "                                             ALLAH HAFIZ :)\n";
				} 
			
			
		}
	}while(opt<6);
	
	system("pause");
}

