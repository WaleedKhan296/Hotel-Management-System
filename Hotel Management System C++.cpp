#include<iostream>
#include<fstream>
using namespace std;

void Create_Account(int &s,double (&am)[20], int (&roll)[20], int (&account)[20], char (&name)[20][30]){
	if(s<20){
		char ch='\0';
		int i=0;
		cout <<"             Welcome to our Hotel"<<endl;
		cout <<"To register your Room kindly fill the following information :"<<endl;
		cout <<"Enter your name:";	
		getchar();
		while((ch=getchar())!='\n'){
			name[s][i]=ch;
			++i;
		}
		cout <<"Enter your phone#";		cin >>roll[s];
		cout <<"Enter the amount you want to deposit initially:";		cin >> am[s];
		account[s]=s+1;
		cout <<"\nCongratulations your room has been alloted"<<endl<<"your room number is "<<s+1<<".\n\n";
		++s;
	}
	else{
		cout<<"There is no space in the hotel. Our limit is full\n\n";
	}
}

void Display(int s,double amount[20], int roll[20], int account[20], char name[20][30]){
	int acc;
	cout<<"Enter your room number:";	cin>>acc;	cout<<endl;
	for(int i=0;i<s;i++){
		if(account[i]==acc){
			cout<<"Your Room Information\n";
			cout<<"Phone Number : "<<roll[i]<<endl;
			cout<<"Name:"<<name[i]<<endl;
			cout<<"Room Number : "<<account[i]<<endl;
			cout<<"Amount:"<<amount[i]<<endl<<endl;
			return;
		}
	}
	cout<<"Sorry!No such record found!\n\n";
}

void Deposit_Amount(int size, double (&am)[20], int account[20]){
	int acc;
	double amount;
	cout<<"Enter your Room number:";	cin>>acc;	cout<<endl;
	for(int i=0;i<size;i++){
		if(account[i]==acc){
			cout<<"Enter Amount:";	cin>>amount;
			am[i]+=amount;
			cout<<"Your amount has been successfully added for your Room expenditures\n\n";
			return;
		}
	}
	cout<<"Sorry! No such record found!\n\n";
}

void Purchase_Item(int size, double (&am)[20], int account[20]){
	bool inList=false;
	int acc,i;
	cout<<"Enter Your Room number to order food:";		cin>>acc;
	for(i=0;i<size;i++){
		if(account[i]==acc){
			inList=true;
			break;
		}
	}
	if(inList){
		int choice,items=0;
		double amount=0.0;
		while(1){
			cout<<"\n  Item   Cost in PKR\n";
			cout<<"1.Lunch     150\n";
			cout<<"2.Snack     100\n";
			cout<<"3.Drink     50\n";
			
			cout<<"Enter Choice or 0 to exit : ";	cin>>choice;
			
			if(choice==0){
				break;
			}
			else if(choice==1){
				amount+=150;
				++items;
			}
			else if(choice==2){
				amount+=100;
				++items;
			}
			else if(choice==3){
				amount+=50;
				++items;
			}
			else{
				cout<<"\nEnter a valid Choice\n\n";
			}
		}
		if(amount==0){
			cout<<"You have purchased nothing\n\n";
			return;
		}
		else if(amount>am[i]){
			cout<<"\nWe can not proceed beacause you have purchased more than your account balance.\n";
			cout<<"Try Again with less orders\n\n";
		}
		else{
			am[i]-=amount;
			cout<<"\nYou have successfully purchased "<<items<<"Amount has been deducted from your Money\n\n";
		}
	}
	else{
		cout<<"Sorry! No such record found!\n\n";
	}
}

void Store_in_File(int size, int roll[20], int account[20], char name[20][30], double amount[20]){
	ofstream file("Record_sys.txt");
	for(int i=0;i<size;i++){
	file<<"Room no : "<<account[i]<<endl<<"Phone no : "<<roll[i]<<endl<<"Name : "<<name[i]<<endl<<"amount : "<<amount[i]<<endl<<endl<<endl;
	}
	file.close();
	cout<<"\nInformation is successfully stored in the file\n\n";
}
void sorted_array(int x,double d[20],int y[20],int z[20],char a[20][30])
{
	int u = y[0],t = z[0], f, r = d[0];
	char b[20][30];
	for (int e=0;e<x;e++)
	{
		for (int o=e+1;o<x;o++)
		{
			if (y[e]>y[o])
			{
				u = y[e];
				y[e]=y[o];
				y[o]=u;
				r = d[e];
				d[e] = d[o];
				d[o]=r;
				t = z[e];
				z[e]=z[o];
				z[o]=t;
				for (int j=0;j<30;j++)
				{
					b[e][j]=a[e][j];
				}
				for (int k=0;k<30;k++)
				{
					a[e][k]=a[o][k];
				}
				for (int l=0;l<30;l++)
				{
					a[o][l]= b[e][l];
				}
				
			}
		}
	}
	for (int q=0;q<x;q++)
	{
		cout <<"Room No:"<<z[q]<<endl;
		cout <<"Phone No:"<<y[q]<<endl;
		cout <<"Name:"<<a[q]<<endl;
		cout <<"Balance:"<<d[q]<<endl<<endl<<endl;
	}	
}
void read_from_file()
{
	char data[100];
	char t;
	ifstream fin;
	fin.open("Record_sys.txt");
	fin.getline(data,100);
	while(!fin.eof())
	{
		cout <<data<<endl; 
		fin.getline(data,100);
	}
	fin.close();
}
int main(){
	double amount[20]={0.0};
	int account_number[20]={0}, roll_number[20]={0}, size=0;
	char student_name[20][30];
	int choice=0;
	
	while(1){
		cout<<"1.Room Alloted\n";
		cout<<"2.Display Room Information\n";
		cout<<"3.Deposit Money into Hotel\n";
		cout<<"4.Purchase Item\n";
		cout<<"5.Store Data in File\n";
		cout<<"6.Display Sorted Data\n";
		cout<<"7.Read Data from the File\n";
		cout<<"0.Exit\n";
		
		cout<<"\nEnter Choice: ";		cin>>choice;	cout<<endl;
		
		if(choice==0){
			break;
		}
		else if(choice==1){
			Create_Account(size, amount, roll_number, account_number, student_name);
		}
		else if(choice==2){
			Display(size, amount, roll_number, account_number, student_name);
		}
		else if(choice==3){
			Deposit_Amount(size, amount, account_number);
		}
		else if(choice==4){
			Purchase_Item(size, amount, account_number);
		}
		else if(choice==5){
			Store_in_File(size, roll_number, account_number, student_name, amount);
		}
		else if(choice==6){
			sorted_array(size,amount,roll_number,account_number,student_name);
		}
		else if(choice==7){
			read_from_file();
		}
		else{
			cout<<"\nEnter a valid Choice\n\n";
		}
	}
	cout<<"\nGood bye, Have a nice day !\n";
return 0;
}
