#include<iostream> //library for the input out 
#include<stdlib.h>
#include<stdio.h>
#include<math.h> //library for mathematical manipulations
#include<ctype.h>
#include<stdarg.h>
#include<stddef.h>
#include<time.h>//for automatic date

using namespace std;

void temp_file_clear();//for clearing temp file
void copy_content(string a,string b); //global declaration
void number_system_put(int n1);//function that takes one variable
int number_system_get();//account number automation 
void user_menu(int);
void clrscr();

void clrscr()
    {
    cout << string( 100, '\n' );
    }
//User interface manual
//class one

class manual
{
	public:
		void userguide();
		
};
void manual::userguide() //declaring member function outside the class
{
	cout<<string(26, '*');
	cout<<" \n * Water Billing system *\n";
	cout<<string(26, '*');
	cout<<endl;
	cout.setf(ios::left);
	cout<<setw(10)<<"App Name   " <<":"<<setw(20)<<"Water Billing"<<endl;
	cout<<setw(10)<<"Platform   " <<":"<<setw(20)<<"Windows, Microsoft"<<endl;
	cout<<setw(10)<<"Language   " <<":"<<setw(20)<<"c++"<<endl;
	cout<<setw(10)<<"Compiled by" <<":"<<setw(20)<<"Timothy Kipchumba"<<endl;
	cout<<endl<<endl<<endl;
	cout<<"* Related Topics:"<<endl;
	cout<<string(26,'-')<<endl;
	cout<<"1. How to Open new Acount ?"<<endl;
	cout<<"-> use second option \"Create new Account\" "<<endl;
}
//User manual class start
//class two

class user 
{
	public:
	
	char fname[10],lname[10];//name of the user
	string phone;
	string ID;

		user()
		{
			phone = '\0';
			ID = '\0';
		}
		~user()
		{}	
};
class Account : public user
{
	int accountNumber ;
	int passcode ;
	int balance;
	
	public:
	Account()
	{
		accountNumber = 0;
		balance = 0;
		passcode = 0;
	}
	~Account(){}
	
	void CurrentBalance(int);	//bal check
	void createAccount(); 		//function for registering new account
	void showDetails(); 		//function for showing account details
	void searchDetails(int);	//function to search details of perticular user
	void delete_details();		//function for deleting record
	void update_details(int); 	//function for updating record
	void login_user(int,int);	//login function
	void add(int,int);          //Add Money
	void deduct(int,int);	 	//Deduct Money
	
	void viewTr(int); //view all transections 
	void fund_tr(int); //for paying the water bills
	void ministatement(int); //function for showing receipt and statement
};
void Account :: login_user(int user, int pass)
{	
	int flag = 0;

	//getting data from file
	ifstream file_read("cus_details.txt" ,ios::in);
	while(!file_read.eof())
	{

		file_read >> fname;
		file_read >>lname;
		file_read >>phone;
		file_read >>ID;
		file_read >>accountNumber;
		file_read >>passcode;
		file_read >>balance;
		if(file_read.eof())
		{
			break;
		}
		if(user == accountNumber && pass == passcode)
		{
			cout<<"\n Login sucessful !"<<endl;
			user_menu(user);
			flag = 1;
		}
	
	}
	
	if(flag == 0 )
	{
		cout<<"\n User name & Passcode Not matched !"<<endl;
		
	}
	file_read.close();
	
}
void Account :: createAccount()
{
	
	cout << "\n\tEnter your First name :";
	cin >>fname;
	cin.clear();

	cout << "\n\tEnter Last name :";
	cin >>lname;
	cin.clear();

	string temp_phone;
	cout << "\n\tEnter phone number :";
	cin >>temp_phone;
	cin.clear();
	if(temp_phone.length()==10)
	{
		phone = temp_phone;
		
	}
	else
	{
	
		while(temp_phone.length() != 10)
		{
			cout<<"phone number must be 10 digit\n";
			cout<<"\n input chone number:";
			cin >> temp_phone;
			phone = temp_phone;	
		}
	}

	
	
	cout << "\n\tEnter ID Number :";
	cin >>ID;
	cin.ignore();
	
	
	accountNumber = number_system_get();
	
	cout << "\n\t Your Account Number :"<<accountNumber;

	cout << "\n\t Enter 4 digit Passcode ::";
	cin >> passcode;
	
	cout <<"\n\t Enter Primary Balance :";
	cin >>balance;

	ofstream file("cus_details.txt",ios::out | ios :: app);
	file << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
	
	number_system_put(accountNumber);
	file.close();
}
void Account :: CurrentBalance(int user_no)
{
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	while(file_read)
	{
		
	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>ID;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;

	if(file_read.eof())
	{
		break;
	}

	if(user_no == accountNumber)
	{
		
		cout<<"\n\tCurrent Balance           :"<<balance<<"/Ksh.";
		cout<<"\n\n\n";
	}
	
	
	}
	
	file_read.close();
}
void Account :: searchDetails(int user_no) //user_no for user session for only specified user can show
{
	int ch;
	int flag = 0;
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	//cout <<"\n\tEnter account  number:";
	//cin >>ch;
	//cin.clear();
	
	while(file_read)
	{
		
	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>ID;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;

	if(file_read.eof())
	{
		break;
	}

	if(user_no == accountNumber)
	{
		cout<<"\n\tAccount Number is :"<<accountNumber;
		cout<<"\n\tName              :"<<fname<<" "<<lname;
		cout<<"\n\tPhone             :"<<phone;
		cout<<"\n\tID Number         :"<<ID;
		cout<<"\n\tBalance           :"<<balance<<"/Ksh.";
		cout<<"\n\n\n";
		flag  = 1;
	}
	
	
	}
	if(flag != 1)
	{
		cout << "\n\tNo record found";
		
	}
	file_read.close();
	
}
void Account ::delete_details()
{
	char ch[10];
	char buff;
	int flag = 0;
	string a = "cus_details.txt";
	string b = "temp.txt";
	
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	ofstream file_temp("temp.txt",ios::out |ios::app);
	cout <<"\n\tEnter name:";
	cin >>ch;
	cin.clear();
	
	while(!file_read.eof())
	{
		
	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>ID;
	file_read >>accountNumber;
	file_read >>balance;
	
	if(file_read.eof())
	{
		break;
	}
		if(strcmp(fname,ch) == 0)
		{
			cout <<fname<<" "<<lname<<"\t"<<ID<<"\t"<<phone<<"\t"<<accountNumber<<"\t"<<balance<<endl;
			flag  = 1;
		}
		else{
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
		}
	
	}
	if(flag != 1)
	{
		cout << "\n\tNo record found";
		
	}
	file_temp.close();
	file_read.close();
	copy_content(b,a);
	
	cout<<"\n\t Done Account Is Removed !\n\n";
	temp_file_clear();
	
}
/*start operator overloading (depositing money to the account)*/
void Account :: add(int user_no,int amt)
{
	string a = "cus_details.txt";
	string b = "temp.txt";
	char tr_date[9];
	
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	ofstream file_temp("temp.txt",ios::out |ios::app);
	ofstream tr_write("transec.txt",ios::out | ios::app);
	while(!file_read.eof())
	{
		
	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>ID;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;
	
	if(file_read.eof())
	{
		break;
	}
	
	if(user_no == accountNumber)
	{
			balance = balance + amt;
			_strdate(tr_date);

			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
			
			tr_write<<accountNumber<<" "<<tr_date<<" "<<amt<<" "<<"Ksh"<<endl; 

	}	
	else
	{
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
	}
	
	}
	
	file_temp.close();
	file_read.close();
	copy_content(b,a);
	cout<<"\n\t Done ! Amount Added\n";
	temp_file_clear();
	
}
void Account :: deduct(int user_no,int amt)
{
	string a = "cus_details.txt";
	string b = "temp.txt";
	char tr_date[9];
	
	int flag = 0;
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	ofstream file_temp("temp.txt",ios::out |ios::app);
	ofstream tr_write("transec.txt",ios::out | ios::app);
	while(!file_read.eof())
	{
		
	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>ID;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;
	
	if(file_read.eof())
	{
		break;
	}
	
	if(user_no == accountNumber)
	{
			if(balance != 0 && balance > amt)
			{
			
				balance = balance - amt;
				_strdate(tr_date); //saving current date

				file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
					
				tr_write<<accountNumber<<" "<<tr_date<<" "<<amt<<" "<<"KSh."<<endl; 

				flag = 1;
			}
			else
			{
				
				cout<<"\nyour transection can not be completed balance is Zero or Less than wuthdrawal amount\n! ";
				file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
			}
	}
		
	else
	{
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
	}
	
	}
	
	file_temp.close();
	file_read.close();
	copy_content(b,a);
	if(flag == 1)
	{
		cout<<"\n\t Done ! WATER BILL PAID\n";
		
	}
	
	temp_file_clear();
	
}
/*end operator overload*/
/*Start receipt and statement function  */
void Account::ministatement(int user_no)
{
	int number,amount,flag = 0,pbalance = 0;
	string date,status;
	char today[9];
	_strdate(today);
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);

	while(file_read)
	{
		
	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>ID;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;

	if(file_read.eof())
	{
		break;
	}

		if(user_no == accountNumber)
		{
			pbalance = balance;
		}
	}
	
	file_read.close();
	//transection part
	
	cout<<"\n\n\n\n\n\n\n\n\n\n"<<endl;
	cout<<"\n\t Mini statement for "<<today<<endl;
	cout<<"\n";
	cout<<"\n\tAccount Number : "<<accountNumber<<endl;
	cout<<"\n\n";	
	
	ifstream tr_file_read("transec.txt" ,ios::in);
	//cin.clear();
	cout<<"\n\t"<<"Date"
	<<" | "<<"Amount"<<" | "<<"KSh "<<endl;
	
	while(tr_file_read)
	{
		tr_file_read >>number;
		tr_file_read >>date;
		tr_file_read >>amount;
		tr_file_read >>status;	
	if(tr_file_read.eof())
	{
		break;
	}

	if(user_no == number)
	{
		cout<<"\t"<<date<<" | "<<amount
				<<" | "<<status<<" | "<<endl ;
		flag  = 1;
	}
	
	
	}
	if(flag != 1)
	{
		cout << "\n\tNo record found";	
	}
	cout<<"\n\n";
	cout<<"Total Primary Balance :"<<pbalance<<"/."<<endl;
	tr_file_read.close();
	
}
/*End mini statement function */
/*Start Fund transfer function */
void Account::fund_tr(int user_no)
{
	int user2_no ,amt =0,flag = 0;
	char ans;
	
	cout <<"\nEnter the paybill number: ";
	cin >> user2_no;
	
	cout <<"\nEnter Amount to pay: ";
	cin >> amt;
	
	string a = "cus_details.txt";
	string b = "temp.txt";
	char tr_date[9];
	
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	ofstream file_temp("temp.txt",ios::out |ios::app);
	ofstream tr_write("transec.txt",ios::out | ios::app);
	while(!file_read.eof())
	{
		
	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>ID;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;
	
	if(file_read.eof())
	{
		break;
	}
	
	if(user2_no == accountNumber)
	{
		cout << "\nAccount Holder's name :"<<fname<< " "<<lname<<endl;
		cout<<"enter(Y/N): ";
		cin >>ans;
		
		if(ans == 'n')
		{
			flag = 1;
			break;
		}
		
		
			balance = balance + amt;
			_strdate(tr_date);

			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
			
			tr_write<<accountNumber<<" "<<tr_date<<" "<<amt<<" "<<"KSh"<<endl; 

	}	
	else
	{
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
	}
	
	}
	
	if(flag == 1)
	{
		cout <<"\n NO Account Found";
	}
	file_temp.close();
	file_read.close();
	copy_content(b,a);
	cout<<"\n\t Done ! Amount Transferred\n";
	temp_file_clear();
	
	//now time for deducting amount from main user
	deduct(user_no,amt);
	cout << "\n Transaction Successfully \n !";	
}
/* Start View All Transection */
void Account::viewTr(int user_no)
{
	
	int number,amount,flag = 0;
	string date,status;
	
	ifstream tr_file_read("transec.txt" ,ios::in);
	//cin.clear();
	cout<<"\n\t"<<"AccountNumber"<<"|\t "<<"Date"<<"     |\t "<<"Amount"<<" |\t "<<"Currency "<<endl;
	
	while(tr_file_read)
	{
		tr_file_read >>number;
		tr_file_read >>date;
		tr_file_read >>amount;
		tr_file_read >>status;	
	if(tr_file_read.eof())
	{
		break;
	}

	if(user_no == number)
	{
		cout<<"\t"<<number<<"\t    |\t "<<date<<"    | \t"<<amount<<"    |\t "<<status<<" |\t "<<endl ;
		flag  = 1;
	}
	
	
	}
	if(flag != 1)
	{
		cout << "\n\tNo record found";	
	}
	tr_file_read.close();
}

/* End View All Transection */
void Account ::update_details(int user_no)
{
	int ch;
	char buff;	
	int flag = 0;
	string a = "cus_details.txt";
	string b = "temp.txt";
	
	Account();//constructor call to empty variables;
	ifstream file_read("cus_details.txt" ,ios::in);
	ofstream file_temp("temp.txt",ios::out |ios::app);
	
	while(!file_read.eof())
	{
		
	file_read >> fname;
	file_read >>lname;
	file_read >>phone;
	file_read >>ID;
	file_read >>accountNumber;
	file_read >>passcode;
	file_read >>balance;
	
	if(file_read.eof())
	{
		break;
	}
	
	if(user_no == accountNumber)
	{
			cout <<"\n\tAccount Number is : "<<accountNumber;
			cout <<"\n\tFill up Details with new records :\n";
			
			cout<<"\n\n\t New First name:";
			
			cin >>fname;
			cin.clear();
				
			cout <<"\n\t New Last name:";
			cin >> lname;
			cin.clear();
			
			cout <<"\n\t New  phone:";
			cin >> phone;
			cin.clear();
			
			cout <<"\n\t New ID";
			cin >> ID;
			cin.clear();
			
			
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
			flag  = 1;
	}	
	else
	{
			file_temp << fname <<" "<<lname<<" "<< phone<<" "<<ID<<" "<<accountNumber<<" "<<passcode<<" "<<balance<<endl;
	}
	
	}
	if(flag != 1)
	{
		cout << "\n\tNo record found";
		
	}
	file_temp.close();
	file_read.close();
	copy_content(b,a);
	
	cout<<"\n\t Done ! Details Updated THank You.\n";
	cout<<"\n\n";
	temp_file_clear();
	
}
/*
copy content function for copy text to other file 
*/
void copy_content(string a,string b)
{
		char ch;
		int flag = 0;
	ifstream temp_read(a.c_str(),ios :: in);
	ofstream file_write(b.c_str(),ios::out);
	while(!temp_read.eof())
	{
		temp_read.get(ch);
		file_write.put(ch);
		flag = 1;
	}
	if(flag != 1)
	{
		cout <<"\n\tFile Error !";
	}
	
}
//functions for account number automation
int number_system_get()
{
	int number;
	ifstream number_read("number.txt",ios::in);
	number_read >>number;
	return number;
}

void number_system_put(int n1)
{
	n1 = n1+1;
	ofstream number_write("number.txt",ios::out);	
	number_write <<n1;
}
//function for clearing TEMP FILE
void temp_file_clear()
{

	char ch;
	int flag = 0;
	ofstream temp_write("temp.txt",ios :: out);

	temp_write <<" ";
	temp_write.close();
	
}
//menu for register user
void user_menu(int user_session)
{
	int ch;
	int amount = 0;
	Account a;
	start:do{
		
		cout<<"Welcome Your account number is >>  "<<user_session<<endl;
		cout<<"\n\t 1.View Your Account.";
		cout<<"\n\t 2.Update Your Details.";
		cout<<"\n\t 3.Pay bill";
		cout<<"\n\t 4.Add Money.";
		cout<<"\n\t 5.View Transaction.";
		cout<<"\n\t 6.Close Account.";
		cout<<"\n\t 7.MiniStatement";
		cout<<"\n\t 0.Exit";
			
		cout<<"\n\t Enter your Choice (1-7)::";
	if(cin >> ch)
	{
		
		
		switch (ch)
		{
			case 1:
				system("cls");
				a.searchDetails(user_session);
				break;
				
			case 2:
				system("cls");
				a.update_details(user_session);
				break;
				
			case 3:
				system("cls");
				a.fund_tr(user_session);
				break;
				
			case 4:
				cout<<"\n\tEnter Amount to Add :=";
				cin >> amount;
				a.add(user_session,amount);
				a.CurrentBalance(user_session);
				break;
				
			case 5:
				a.viewTr(user_session);
				break;
				
			case 6:
				a.delete_details();
				break;
			
			case 7:
				a.ministatement(user_session);
				break;
			
			default :
				cout<<"\n\tWorng choise \n";		
				break;
		}
	}
		else
		{
			cout<<"\n\t Input only Digits please !";
			getch();
			cin.clear();
		 	cin.ignore();
			ch = 15;
		}
	

	}while(ch != 0);
	
}
int main()
{
	int ch;
	int login_state = 0;
	int user;
	int pass;
	Account a;
	manual m;
	
	do{
		//system("clear");
		system("cls");
		
		cout<<"\n\t\tWater Billing System"<<endl;
		cout<<""<<endl;
		cout<<"\n\t\t"<<endl;
		
		cout <<"\n\t 1.Login To your Account.";
		cout <<"\n\t 2.Open An Account.";
		cout <<"\n\t 3.Help.";
		cout <<"\n\t 0.Exit";
		
		cout<<"\n\n\tEnter your choice ::";
		if(cin >> ch )
		{
			switch (ch)
			{
				case 1:
					cout << "\n\t Enter Account Number:";
					cin >>user;
					cout <<"\n\t Enter 4-digit passcode :";
					cin >>pass;
					system("cls");
					a.login_user(user,pass);
					//cout<<"\n\t\twork in progress";
	
				break;
				case 2:
					a.createAccount();
					break;
					
				case 3:
				//	cout<<"\nWork is in Progress !";
				m.userguide();
				getch();
					break;
					
			}
		}
		else
		{
			cout<<"\n\t Input only Digits please ! Press Enter To continue";
			getch();
			cin.clear();
		 	cin.ignore();
			ch = 15 ;
		}
		

			
	}while(ch !=0);
//	user_menu();
	return 0;
}
