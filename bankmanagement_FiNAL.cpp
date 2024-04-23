#include<iostream>
#include<fstream>
#include<cctype>
#include<iomanip>
#include<vector>
using namespace std;

void write_account();
void display_sp(int);
void modify_account(int);
void delete_account(int);
void display_all();
void deposit_withdraw(int, int);
void deposit_withdraw(int n, int option,int k);
int returnAccno(int ph);
int returnAmount(int ph);

class RBI{	
public:
	int acno;
	char name[50];
	char type;
	int phonenumber;
	int deposit;
	
	virtual void modify() = 0;
	virtual void dep(int) = 0;
	virtual void draw(int) = 0;
};

class Bank1:public RBI{
public:
	Bank1(){
	}
	Bank1(int y);
	void modify();
	void dep(int);
	void draw(int);
	void operator+(Bank1 obj){
		this->deposit += obj.deposit;
		delete_account(obj.acno);
	}
	void show_account() const;
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
};
class Bank2:public RBI{
public:
	Bank2(){
	}
	Bank2(int y);
	void modify();
	void dep(int); 
	inline void draw(int);
	inline void show_account() const;
	void report() const;
	int retacno() const;
	int retdeposit() const;
	char rettype() const;
};

vector<Bank1> v1;

template<typename h>
class UPI:virtual public Bank1,virtual public Bank2{
	public:
	h UPI;
	
	friend bool check(int p,int y);
};

bool check(int p,int y=0){
	if(y==1){
		for(int i=0;i<v1.size();i++){
			if(v1[i].phonenumber == p){
				return true;
			}
		}
	}
	else{
		for(int i=0;i<v1.size();i++){
			if(v1[i].acno == p){
				return true;
			}
		}
	}
	return false;
}


Bank1::Bank1(int y)
{
	system("CLS");
	cout<<"\n\t\t\tEnter the Account No. : ";
	cin>>acno;
	cout<<"\n\n\t\t\tEnter the Name of the Account holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tEnter Type of the Account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tEnter The Initial amount : ";
	cin>>deposit;
	cout<<"\n\t\t\tEnter The Linked Phone Number : ";
	cin>>phonenumber;
	cout<<"\n\n\t\t\tAccount Created..";
}

void Transfer(int phS,int Dph){
	int z,y;
	z = returnAccno(phS);
	if(z){
		y = returnAccno(Dph);
		if(y){
		cout<<"Enter the amount to transfer:- ";
		int n;
		cin>>n;
		deposit_withdraw(z,2,n);
		deposit_withdraw(y,1,n);
		}
		else{
			cout<<"The destination number doesn't exist."<<endl;
			return;
		}
	}
	else{
		cout<<"The phone number is not connected to a bank account."<<endl;
	}
}

void Transfer(int phS,int Dph,int l){
	cout<<"Enter the amount to transfer:- ";
	int n;
	cin>>n;
	deposit_withdraw(phS,2,n);
	deposit_withdraw(Dph,1,n);
}

void Transfer(int phS,int Dph,int l,int k){
	cout<<"Enter the amount to transfer:- ";
	int n = returnAmount(Dph);
	if(!n){
		cout<<"Account not found."<<endl;
		return;
	}
	deposit_withdraw(phS,1,n);
}

void Bank1::show_account() const
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tAccount Holder Name : ";
	cout<<name;
	cout<<"\n\t\t\tType of Account : "<<type;
	cout<<"\n\t\t\tBalance amount : "<<deposit;
}

void Bank1::modify()
{
	cout<<"\n\t\t\tAccount No. : "<<acno;
	cout<<"\n\t\t\tModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\t\t\tModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\t\t\tModify Balance amount : ";
	cin>>deposit;
}

void Bank1::dep(int x)
{
	deposit+=x;
}

void Bank1::draw(int x)
{
	deposit-=x;
}

void Bank1::report() const
{
	cout<<setw(5)<<acno<<setw(10)<<name<<"\t\t"<<setw(2)<<type<<setw(10)<<deposit<<"\t"<<setw(10)<<phonenumber<<endl;
}

int Bank1::retacno() const
{
	return acno;
}

int Bank1::retdeposit() const
{
	return deposit;
}

char Bank1::rettype() const
{
	return type;
}

void menu(){
	int num;
	system("CLS");
	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MENU::\n";
		cout<<"\n\t\t\t\t1. Bank 1";
		cout<<"\n\t\t\t\t2. Bank 2";
		cout<<"\n\t\t\t\t3. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-3): ";
		cin>>num;
		return;
}

int main()
{ 
	menu();
	int ch;
	int num;
	do{
	system("CLS");
	cout<<"\n\n\t\t\t\t======================\n";
	cout<<"\t\t\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t\t\t======================\n";

		cout<<"\t\t\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t\t\t1. NEW ACCOUNT";
		cout<<"\n\t\t\t\t2. DEPOSIT AMOUNT";
		cout<<"\n\t\t\t\t3. WITHDRAW AMOUNT";
		cout<<"\n\t\t\t\t4. TRANSFER AMOUNT";
		cout<<"\n\t\t\t\t5. BALANCE ENQUIRY";
		cout<<"\n\t\t\t\t6. ALL ACCOUNT HOLDER LIST";
		cout<<"\n\t\t\t\t7. CLOSE AN ACCOUNT";
		cout<<"\n\t\t\t\t8. MODIFY AN ACCOUNT";
		cout<<"\n\t\t\t\t9. UPI TRANSFER";
		cout<<"\n\t\t\t\t10.MERGE ACCOUNT";
		cout<<"\n\t\t\t\t0. EXIT";
		cout<<"\n\n\t\t\t\tSelect Your Option (1-10): ";
		cin>>ch;

		switch(ch){
		case 1:
			write_account();
			break;
		case 2:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 1);
			break;
		case 3:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			deposit_withdraw(num, 2);
			break;
		case 4:
			system("CLS");
			int num,nu;
			cout<<"\n\n\t\t\tEnter The account Source Account No. : "; cin>>num;
			cout<<"\n\n\t\t\tEnter The account Destination Account No. : "; cin>>nu;
			Transfer(num,nu,1);
			break;
		case 5:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			display_sp(num);
			break;
		case 6:
			display_all();
			break;
		case 7:
			system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			delete_account(num);
			break;
		case 8:
		 	system("CLS");
			cout<<"\n\n\t\t\tEnter The account No. : "; cin>>num;
			modify_account(num);
			break;
		case 9:
			system("CLS");
			cout<<"\n\n\t\t\tEnter your Phone No. : "; cin>>num;
			cout<<"\n\n\t\t\tEnter the receiver Phone No. : "; cin>>nu;
			Transfer(num,nu);
			break;
		case 10:
			system("CLS");
			cout<<"\n\n\t\t\tEnter the source account : "; cin>>num;
			cout<<"\n\n\t\t\tEnter the account you want merge with source : "; cin>>nu;
			Transfer(num,nu,2,8);
			delete_account(nu);
			break;
		case 0:
		 	system("CLS");
			return 0;
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='0');
	return 0;
}


void write_account()
{
	Bank1 ac(5);
	v1.push_back(ac);
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank1));
	outFile.close();
}

void display_sp(int n)
{
	Bank1 ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\t\t\tBALANCE DETAILS\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank1)))
	{
		if(ac.retacno()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\t\t\tAccount number does not exist";
}

void modify_account(int n)
{
	bool found=false;
	Bank1 ac;
	fstream File;
    File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank1));
		if(ac.retacno()==n)
		{
			ac.show_account();
			cout<<"\n\n\t\t\tEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(Bank1));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(Bank1));
		    cout<<"\n\n\t\t\tRecord Updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}

void delete_account(int n)
{
	Bank1 ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank1)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank1));
		}
	}
    inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\nRecord Deleted ..";
}


void display_all()
{
	system("CLS");
	Bank1 ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.    NAME        Type    Balance   Phone Number\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank1)))
	{
		ac.report();
	}
	inFile.close();
}


void deposit_withdraw(int n, int option)
{
	int amt;
	bool found=false;
	Bank1 ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank1));
		if(ac.retacno()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\t\t\tTO DEPOSIT AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\t\t\tTO WITHDRAW AMOUNT";
				cout<<"\n\n\t\t\tEnter The amount to be withdraw: ";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if(bal<0)
					cout<<endl<<"Insufficience balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Bank1));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}

void deposit_withdraw(int n, int option,int k)
{
	int amt;
	bool found=false;
	Bank1 ac;
	fstream File;
    File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank1));
		if(ac.retacno()==n){
			ac.show_account();
			if(option==1)
			{
				ac.dep(k);
			}
		    if(option==2)
			{
				int bal=ac.retdeposit()-k;
				if(bal<0)
					cout<<"Insufficience balance";
				else
					ac.draw(k);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);//fn1353
			File.write(reinterpret_cast<char *> (&ac), sizeof(Bank1));
			cout<<"\n\n\t\t\tRecord Updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\t\t\tRecord Not Found ";
}

int returnAccno(int ph){
	bool found = false;
	Bank1 ac;
	fstream FILE;
	FILE.open("account.dat",ios::binary|ios::in);
	if(!FILE){
		cout<<"File could not be open !! Press any Key..."<<endl;
		return 0;
	}
	while(!FILE.eof() && found==false){
		FILE.read(reinterpret_cast<char *> (&ac), sizeof(Bank1));
		if(ac.phonenumber == ph){
			int x = ac.acno;
			FILE.close();
			return x;
		}
	}
	FILE.close();
	return 0;
}

int returnAmount(int ph){
	bool found = false;
	Bank1 ac;
	fstream FILE;
	FILE.open("account.dat",ios::binary|ios::in);
	if(!FILE){
		cout<<"File could not be open !! Press any Key..."<<endl;
		return 0;
	}
	while(!FILE.eof() && found==false){
		FILE.read(reinterpret_cast<char *> (&ac), sizeof(Bank1));
		if(ac.acno == ph){
			int x = ac.deposit;
			FILE.close();
			return x;
		}
	}
	FILE.close();
	return 0;
}