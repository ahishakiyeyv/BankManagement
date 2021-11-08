#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

//account management

typedef struct Accountmanagement{
	int Number;
	float Amount;
	string Kind;
}acc;

//munber of customer

int EnterSize(){
	int size;
	do{
		cout<<"\n How much  account you want to create : ";
		cin>>size;
	}while(size<0);
	
	return size;
}
int EnterNumber(){
	int number;
	do{
		cout<<"\n Enter the number: ";
		cin>>number;
	}while(number<1000 || number>9999);
	return number;
}
float EnterAmount(){
	float amount;
	cout<<"\n Enter the amount: ";
	cin>>amount;
	return amount;
}
string EnterKind(){
	string kind;
	int i;
	cout<<"\n Enter the kind (choose 1 or 2)"<<"\n"<<"1.curent"<<"\n"<<"2.saving"<<"\n";
	cout<<"type your choice here: ";
	cin>>i;
	switch(i){
		case 1:
		kind="curent";
		cout<<"kind choosen: curent";
		break;
		case 2:kind="saving";
		cout<<"kind choosen: saving";
		break;
		default:cout<<"no natch for your choice";break;
	}
//	cin>>kind;
	return kind;
}
acc CreateAccount(){
	acc account;
	cout<<"\n Creation of  account"<<"\n";
	cout<<"";
	cout<<"------------------------";
	account.Number=EnterNumber();
	account.Amount=EnterAmount();
	account.Kind=EnterKind();

	return account;
}
void DisplayAccount(acc a){
		cout<<"\n	Number : "<<a.Number;
		cout<<"\n	Amount : "<<a.Amount;
		cout<<"\n	kind : "<<a.Kind<<"\n";
}

void CreateNAccount(acc tabac[],int size){
	int i;
	if(size==1){
		cout<<"\n Creation of"<<size<<" Account";
	for(i=0;i<size;i++){
		cout<<"\n Account "<<i+1;
		tabac[i]=CreateAccount();
	}
	}
	
	else{
		cout<<"\n Creation of"<<size<<" Accounts";
	for(i=0;i<size;i++){
		cout<<"\n Account "<<i+1;
		tabac[i]=CreateAccount();
	}
	}
}
void DisplayNAccount(acc tabac[],int s){
	int i;
	cout<<"\n Created account ";
	cout<<"";
	cout<<"\n----------------";
	for(i=0;i<s;i++){
	cout<<"\n| Account number"<<i+1;
	DisplayAccount(tabac[i]);
	}
}

int EnterModifyAmount(){
	int number;
	cout<<"\n Select account to modify : ";
	cin>>number;

	return number;
}
void ModifyNAmount(acc tabac[],int size,int number){
	int i,newamount;
	for(i=0;i<size;i++){
		if((tabac[i].Number)==number){
			cout<<"\n Modify the amount of account "<<tabac[i].Number<<" : ";
			cin>>newamount;
			
			tabac[i].Amount=newamount;
		}
	}
}
float SumAccount(acc tabac[],int size){
	int i;
	float somme=0;
	for(i=0;i<size;i++){
		somme= somme + tabac[i].Amount;
	}

	return somme;
}
void DisplaySumAccount(acc tabac[],int size,float somme){
	if(size==1){
	cout<<"\n The sum of "<<size<<" account is : "<<somme<<"\n";	
	}
	else{
		cout<<"\n The sum of "<<size<<" accounts is : "<<somme<<"\n";
	}
	
}
void DisplayNegativeAmount(acc tabac[],int size){
	int i;
	cout<<"\n negative amount account "<<"\n";
	cout<<""<<"\n";
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~";
	for(i=0;i<size;i++){
		if(tabac[i].Amount<0){
			
		cout<<"\n Account "<<tabac[i].Number;
		DisplayAccount(tabac[i]);
		}
	}
}

//end account management

//about date

typedef struct Date{
	int Day;
	int Month;
	int Year;
}date;
int EnterDay(){
	int day;
	do{
		cout<<"\n Enter a day : ";
		cin>>day;
	}while(day<1 || day>31);
	return day;
}
int EnterMonth(){
	int month;
	do{
		cout<<"\n Enter a month : ";
		cin>>month;
	}while(month<1 || month>12);
	return month;
}
int EnterYear(){
	int year;
	do{
		cout<<"\n Enter a year : ";
		cin>>year;
	}while(year<1950);
	return year;
}

date CreateDate(){
	date dt;
	dt.Day=EnterDay();
	dt.Month=EnterMonth();
	dt.Year=EnterYear();

	return dt;
}
bool CheckDate(date dt){
	if(dt.Year>=1950 && dt.Year<=2021)
     	return true;
	else
		return false;
}
void DisplayDate(date dt,bool checkdate){
	if(checkdate==true)
	cout<<"\n The  created date is "<<dt.Day<<"/"<<dt.Month<<"/"<<dt.Year<<"\n";
	else
	cout<<"\n The created date is not valid \n";
}

//client caracteristique

typedef struct Client{
	string Firstname;
	string Lastname;
	string Address;
	int Registrationumber;
	date dt;
//	int Birthdate[3];
}cl;

string EnterFirstname(){
	string fname;
	cout<<"\n Enter the first name : ";
	cin>>fname;
	return fname;
}
string EnterLastname(){
	string lname;
	cout<<"\n Enter the last name : ";
	cin>>lname;
	return lname;
}
string EnterAddress(){
	string address;
	cout<<"\n Enter the Address : ";
	cin>>address;
	return address;
}
int EnterRegistrationumber(){
	int registration;
	cout<<"\n Enter the registration number : ";
	cin>>registration;
	return registration;
}
cl CreateClient(){
	cl clt;
	cout<<"\n Creation of a client"<<"\n";
	cout<<"";
	cout<<"   ~~~~~~~~~~~~~~~~~~~~";
	clt.Firstname=EnterFirstname();
	clt.Lastname=EnterLastname();
	clt.Address=EnterAddress();
	clt.Registrationumber=EnterRegistrationumber();
	cout<<"\n Enter date of birth ";
	clt.dt=CreateDate();
//	clt.Birthdate[0]=EnterDay();
//	clt.Birthdate[1]=EnterMonth();
//	clt.Birthdate[2]=EnterYear();

	return clt;
}
void DisplayClient(cl client){
	cout<<"\n|~~~~~~~   client created  ~~~~~~~~ ";
	cout<<" ";
	cout<<"\n| Client ";
	cout<<"";
	cout<<"\n	First name : "<<client.Firstname;
	cout<<"\n	Last name : "<<client.Lastname;
	cout<<"\n	Address : "<<client.Address;
	cout<<"\n	Registration number : "<<client.Registrationumber;
	cout<<"\n	Birthdate :"<<client.dt.Day<<"/"<<client.dt.Month<<"/"<<client.dt.Year<<"\n" ;
//	cout<<"\n	Birthdate : "<<c.Birthdate[0]<<"/"<<c.Birthdate[1]<<"/"<<c.Birthdate[2]<<"\n";
}
void ModifyClient(cl client){
	cout<<"\n Change client'characteristics ";
	CreateClient();
}
void ModifyNClient(cl tabcl[],int size){
	int i;
	cout<<"\n Change client characteristics ";
	for(i=0;i<size;i++){
		tabcl[i]=CreateClient();
	}
}
int EnterClientSize(){
	int sizeclient;
	do{
		cout<<"\n Enter the number of client to create: ";
		cin>>sizeclient;	
	}while(sizeclient<1);
	
	return sizeclient;
}
void CreateNClient(cl tabcl[],int sizeclient){
	int i;
	cout<<"\n Create a Client";
	for(i=0;i<sizeclient;i++){
		tabcl[i]=CreateClient();
	}
}
void DisplayNClient(cl tabcl[],int sizeclient){
	int i;
	for(i=0;i<sizeclient;i++){
		DisplayClient(tabcl[i]);
	}
}



//bank management



typedef struct Bankmanagement{
	cl client;
	acc account;
}bank;
bank CreateBank(){
	bank bk;
	bk.client=CreateClient();
	bk.account=CreateAccount();
	
	return bk;
}
void DisplayBank(bank b){
	DisplayClient(b.client);
	cout<<"\n|     Account "<<"\n";
	cout<<"        ~~~~~~";
	DisplayAccount(b.account);
}
int EnterBankSize(){
	int sizebank;
	do{
		cout<<"\n Enter the number of Client to create: ";
		cin>>sizebank;	
	}while(sizebank<1);
	
	return sizebank;
}
void CreateNBank(bank tbank[],int sizebank){
	int i;
	cout<<"\n Create "<<sizebank<<" Bank Account";
	for(i=0;i<sizebank;i++){
		cout<<"\n Client "<<i+1;
		tbank[i]=CreateBank();
	}
}
void DisplayNBank(bank tbank[],int sizebank){
	int i;
	for(i=0;i<sizebank;i++){
		cout<<"\n|Bank acount no  "<<i+1<<"\n";
		DisplayBank(tbank[i]);
	}
}
void DisplaySumBankAmount(bank tbank[],int sizebank){
	int i;
	for(i=0;i<sizebank;i++){
	cout<<"\n The sum amount of Client "<<i+1<<" is : "<<tbank[i].account.Amount<<"\n";
	}
}
float GreaterSumAmount(bank tbank[],int sizebank){
	float greatsum=tbank[0].account.Amount;
	int i;
	for(i=0;i<sizebank;i++){
		if(tbank[i].account.Amount>greatsum)
		greatsum=tbank[i].account.Amount;
	}
	return greatsum;
}
void DisplayGreaterSum(bank tbank[],int sizebank,float a){
	int i;
	for(i=0;i<sizebank;i++){
		if(tbank[i].account.Amount==a){
			cout<<"\n|~~~~~~~~~ bank account "<<i+1<<"";
			DisplayBank(tbank[i]);	
		}
	}	
}
float LowerSumAmount(bank tbank[],int sizebank){
	float b=tbank[0].account.Amount;
	int i;
	for(i=0;i<sizebank;i++){
		if(tbank[i].account.Amount<b && tbank[i].account.Amount>0)
		b=tbank[i].account.Amount;
	}
	return b;
}
void DisplayLowerSum(bank tbank[],int sizebank,float a){
	int i;
	for(i=0;i<sizebank;i++){
		if(tbank[i].account.Amount==a){
			cout<<"\n|~~~~~~~~~ bank account "<<i+1<<"";
			DisplayBank(tbank[i]);
		}
	}	
}
void DisplayNegSumAmount(bank tbank[],int sizebank){
	int i;
	for(i=0;i<sizebank;i++){
		if(tbank[i].account.Amount<0){
		cout<<"\n|~~~~~~~~~~ bank account "<<i+1<<"";
		DisplayBank(tbank[i]);
		}
	}
}
void DisplaySort(bank b){
	cout<<"\n|~~~~~~ Client~~~~~~~~~ ";
	cout<<"";
	cout<<"\n	First name : "<<b.client.Firstname;
	cout<<"\n	Last name : "<<b.client.Lastname<<"\n";
	cout<<"\n|~~~~~~~~ Account ";
	cout<<"\n	Amount : "<<b.account.Amount<<"\n";
}
void SortDescSum(bank tbank[],int sizebank){
	int i,j;
	bank b;
	for(i=0;i<sizebank;i++){		
		for(j=i+1;j<sizebank;j++){
			if(tbank[i].account.Amount<tbank[j].account.Amount){
				b=tbank[i];
				tbank[i]=tbank[j];
				tbank[j]=b;
			}
		}
	}
	cout<<"\n|~~~~~~~~~~ Sort starting by the greater sum amount \n";
	for(i=0;i<sizebank;i++){
		cout<<"\n|~~~~~~~~~ bank account NUMBER"<<i+1<<"";
		DisplaySort(tbank[i]);
	}
}

//popup menu
void bankaccountMenu(){
	cout<<"\n ~~~~~~~~~~~ Bank account management ~~~~~~";
	cout<<"\n|                                         |";
	cout<<"\n|                                         |";
	cout<<"\n|          1.Account Management           |";
	cout<<"\n|          2.Client Management            |";
	cout<<"\n|          3.Bank Management              |";
	cout<<"\n|          0.Exit                         |";
	cout<<"\n ------------------------------------------";
}
void accountMenu(){
	cout<<"\n ~~~~~~~~~~Accant management ~~~~~~~~~~~~~";
	cout<<"\n|                                         |";
	cout<<"\n|                                         |";
	cout<<"\n|   1.Display Account                     |";
	cout<<"\n|   2.Modify Amount Of Selected Account   |";
	cout<<"\n|   3.Display The Sum Of Account          |";
	cout<<"\n|   4.Display Account With Neg Amount     |";
	cout<<"\n|   0.Exit                                |";
	cout<<"\n ------------------------------------------";
}
void clientMenu(){
	cout<<"\n ~~~~~~~~~~   Client management  ~~~~~~~~~~";
	cout<<"\n|                                         |";
	cout<<"\n|                                         |";
	cout<<"\n|  1.Display Date                         |";
	cout<<"\n|  2.Display Client Characteristics       |";
	cout<<"\n|  3.Change Client Characteristics        |";
	cout<<"\n|  4.Display Client And Its Bank Account  |";
	cout<<"\n|  5.Modify Amount Of Selected Account    |";
	cout<<"\n|  6.Display The Sum Of Client Account    |";
	cout<<"\n|  0.Exit                                 |";
	cout<<"\n -----------------------------------------";
}
void bankMenu(){
	cout<<"\n ~~~~~~~~~~~~~~~ Bank management ~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\n|                                                        |";
	cout<<"\n|                     0.Exit                             |";
	cout<<"\n|  1.Display Client And Its Bank Account                 |";
	cout<<"\n|  2.Display The Sum Amount Of Each Client               |";
	cout<<"\n|  3.Display The Client With The Greater Sum amount      |";
	cout<<"\n|  4.Display The Client With The Lower Sum amount        |";
	cout<<"\n|  5.Display The Client With Negative Sum amount         |";
	cout<<"\n|  6.Display Clients Starting By The Greater Sum Amount  |";
	cout<<"\n|   												      |";
	cout<<"\n|   		                                              |";
	cout<<"\n --------------------------------------------------------";
}
int Operation(){
	int op;
	cout<<"\n|--------- Choose an operation ----------";
	cout<<"\n ";
	cout<<"make your choice here---> ";
	cin>>op;
	return op;
}




//main function

int main(){
		int menu;
	do{
		bankaccountMenu();
		menu=Operation();
	switch(menu){
		case 0:{	break;}
		case 1:{cout<<"\n|--------- Create account to manage  ------------";
					int menuacc;
					int size=EnterSize();
					acc tabac[size];
					CreateNAccount(tabac,size);
				do{
					accountMenu();
					menuacc=Operation();
					switch(menuacc){
						case 0:{	break;}
						case 1:{
								DisplayNAccount(tabac,size);	
						}break;
						case 2:{
								DisplayNAccount(tabac,size);
								int a=EnterModifyAmount();
								ModifyNAmount(tabac,size,a);
						}break;
						case 3:{
								int sum=SumAccount(tabac,size);
								DisplaySumAccount(tabac,size,sum);
							break;
						}
						case 4:{
								DisplayNegativeAmount(tabac,size);
							break;
						}
						default: cout<<"\n Not in the operations!!! \n";break;
					}
				}while(menuacc!=0);
		}break;
		case 2:{cout<<"\n|-------------- Creation of the date ----------------";
				int menucl;
				date dt=CreateDate();
				cout<<"\n";
				cout<<"\n Create a client to manage and it account";
				cout<<"\n";
				cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
				int c=1;
				cl tabcl[c];
				CreateNClient(tabcl,c);
				int a=EnterSize();
				acc tabac[a];
				CreateNAccount(tabac,a);
				do{
					clientMenu();
					menucl=Operation();
					switch(menucl){
						case 0:{
						cout<<"Thank you"<<"\n";
						cout<<"     "<<"\n";
						cout<<"GOOD BYE !!!";
							break;}
						case 1:{
								bool check=CheckDate(dt);
		        				DisplayDate(dt,check);
							break;
						}
						case 2:{
						        DisplayNClient(tabcl,c);
							break;
						}
						case 3:{
					        	ModifyNClient(tabcl,c);
							break;
						}
						case 4:{
					        	DisplayNClient(tabcl,c);
						        DisplayNAccount(tabac,a);	
							break;
						}
						case 5:{
								DisplayNAccount(tabac,a);
						        int m=EnterModifyAmount();
								ModifyNAmount(tabac,a,m);
							break;
						}
						case 6:{
								int somme=SumAccount(tabac,a);
								DisplaySumAccount(tabac,a,somme);
							break;
						}
						default: cout<<"\n Not in the operations!!! \n";break;
					}
				}while(menucl!=0);  
			break;
		}
		case 3:{cout<<"\n--------------- create a bank to manage ----------";
				int menubk;
				int b=EnterBankSize();
				bank tbank[b];
				CreateNBank(tbank,b);
				do{
					bankMenu();
					menubk=Operation();
					switch(menubk){
						case 0:{	break;}
						case 1:{
								DisplayNBank(tbank,b);
							break;
						}
						case 2:{
								DisplaySumBankAmount(tbank,b);
							break;
						}
						case 3:{
								float greater=GreaterSumAmount(tbank,b);
								DisplayGreaterSum(tbank,b,greater);
							break;
						}
						case 4:{
								float lower=LowerSumAmount(tbank,b);
								DisplayLowerSum(tbank,b,lower);
							break;
						}
						case 5:{
								DisplayNegSumAmount(tbank,b);
							break;
						}
						case 6:{
								SortDescSum(tbank,b);
							break;
						}
						default: cout<<"\n invalid operation \n";
						cout<<"thank you !!!!!";break;
					}
				}while(menubk!=0);
			break;
		}
		default:cout<<"\n invalid operation \n";
		cout<<"thank you!!!!";
			break;
			}
	}while(menu!=0);
	if(menu==0){
		cout<<"\n Thank you"<<"\n";
		cout<<"     "<<"\n";
		cout<<"GOOD BYE !!!";
	}
	
		
	
	
	
	
	return 0;
}











