#include <iostream>

using namespace std;


class account{
protected:
    string name;
	string DOB;
	string Aadhar_num="\0";
	string pan_num="\0";
	long long phn_num;
    int deposit;
    int acc_no;
    static int T_acc;









public:
    account(int aNo = 0, string Name = "Nill", int dep = 0) {
		acc_no = aNo;
		name = Name;
		deposit = dep;
		T_acc++;
    }




    bool valid_date(string);
	void create_account();
	void show_account(int) ;
	void show_balance(int);
	void modify(int);
	void close(int);
	void deposits(int, int);
	void withdraws(int, int);
	int getDep() ;
	int getA_no() ;

static int getT_acc();

};



bool account::valid_date(string date){
       string str1,str2,str3;

       int dd,mm,yy;
       dd=stoi(date.substr(0,2));
       mm=stoi(date.substr(3,2));
       yy=stoi(date.substr(6,4));
       if(date[2]!='-'||date[5]!='-'){
           return false;
       }
      if(yy>0&&yy<2023)
       {
         if(mm==1 || mm==3 || mm==5|| mm==7|| mm==8||mm==10||mm==12 && dd>0 && dd<=31)
         return true;
         else
          if(mm==4 || mm==6 || mm==9|| mm==11 && dd>0 && dd<=30)
            return true;
         else
            if(mm==2)
               {
               if((yy%400==0 || (yy%100!=0 && yy%4==0)) && dd>0 && dd<=29)
                 return true;
               else if(dd>0 && dd<=28)
                  return true;
               else{
                  return false;
               }
               }
         else{
              return false;
         }

      }
    else{
              return false;
    }

  }


void account::create_account() {
	cout << "Automatically Generated Account No: ";
	acc_no = (rand() % 500) + 1;
	cout << acc_no;
	cout << endl << endl;
	cout << "Enter Name of Account Holder: ";
	cin >> name;
	cout << endl;
	cout << "Enter date-of-birth of Account Holder in the format of (dd-mm-yyyy): ";
	string Date;
	do{
		cin>>Date;
		if(!valid_date(Date)){
			cout << "Enter correct Date-of-Birth..";
		}
		else{
			DOB=Date;

			break;
		}
	}while(1);


	 cout << "Enter your Phone Number: ";
                long long phone;

                do{
                    cin>>phone;
                    cout<<endl;
                    int int_length = to_string(phone).length();
                    if(int_length!=10){
                      cout<<"Please enter valid phone number.."<<endl;
                    }
                    else{
                       phn_num=phone;
                       break;
                    }
                }while(1);

	 cout << "Enter your AadharNumber: ";
                string adhar;
                do{
                    cin>>adhar;
                    cout << endl;
                    if(adhar.length()!=12){
                       cout<<"plese enter valid AadharNumber.."<<endl;
                    }
                    else{
                        Aadhar_num=adhar;
                        break;
                    }
                }while(1);
     cout << "Enter your PAN Number: ";
     string pan;
                do{
                    cin>>pan;
                    cout <<endl;
                    if(pan.length()!=10){
                       cout << "plese enter valid PAN Number"<<endl;
                    }
                    else{
                        pan_num=pan;
                        break;
                    }
                }while(1);






	cout << "Enter Initial Amount: ";
	cin >> deposit;
	cout << endl;

	cout << "Account Created Successfully... " << endl;
	cout << endl << endl;


}
void account::show_account(int j)  {
	if (j == acc_no) {
		cout << endl;
		cout << "Account Holder Name: " << name << endl;
		cout << "Date of Birth: " <<DOB<<endl;
		cout << "Phone Number: "<<phn_num<<endl;
		cout << "Aadhar Number: "<<Aadhar_num<<endl;
		cout << "Pan Number: "<<pan_num<<endl;

		cout << "Account Balance: " << deposit << endl;
	}

	cout << endl << endl;
}

void account::show_balance(int j){
    if(j==acc_no){
        cout <<endl;
        cout << "Account Balance: "<< deposit <<endl;
    }
   cout <<endl;

}


void account::deposits(int x, int j) {
	if (j == acc_no) {
		deposit = deposit + x;
	}
    cout <<endl;
}

void account::withdraws(int x, int j){
    if (j == acc_no) {
		if (x > deposit) {
			cout << "Entered Amount is More Than Amount in Bank Account" << endl ;
			cout << "Amount Can Not be Withdrawn..." << endl;
			cout << endl;
		}
		else if (x <= deposit) {
			deposit = deposit - x;
			cout << "Amount Withdrawn Successfully..." << endl;
		}

	}
	cout <<endl;
}

void account::modify( int j) {
	acc_no = j;

	cout << "Modify Account Holder Name: ";
	cin >> name;
	cout << endl;
	cout << "Modify phoneNumber: ";
	long long phone;

                do{
                    cin>>phone;
                    cout<<endl;
                    int int_length = to_string(phone).length();
                    if(int_length!=10){
                      cout<<"Please enter valid phone number.."<<endl;
                    }
                    else{
                       phn_num=phone;
                       break;
                    }
                }while(1);
	cout << endl;
	cout << "Modify Aadhar: ";
	 string adhar;
                do{
                    cin>>adhar;
                    cout << endl;
                    if(adhar.length()!=12){
                       cout<<"plese enter valid AadharNumber.."<<endl;
                    }
                    else{
                        Aadhar_num=adhar;
                        break;
                    }
                }while(1);
	cout << endl;
	cout << "Modify pan: ";
	 string pan;
                do{
                    cin>>pan;
                    cout <<endl;
                    if(pan.length()!=10){
                       cout << "plese enter valid PAN Number"<<endl;
                    }
                    else{
                        pan_num=pan;
                        break;
                    }
                }while(1);

	cout << endl << endl;

}

void account::close(int j) {
	if (j == acc_no) {
		acc_no = 0;
		name = "Nil";
		deposit = 0;
		T_acc = T_acc - 1;
	}
}

int account::getA_no()  {
	return acc_no;
}

int account::getDep()  {
	return deposit;
}

int account::getT_acc() {
	return T_acc;
}


int account::T_acc = 0;

int main()
{
    char select;
    account acc;

    menu:{
    cout << "1.  CREATE ACCOUNTS" << endl;
	cout << "2.  DEPOSIT AMOUNT" << endl;
	cout << "3.  WITHDRAW AMOUNT" << endl;
	cout << "4.  CHECK ACCOUNT BALANCE" << endl;
	cout << "5.  DISPLAY ALL ACCOUNT DETAILS" << endl;
	cout << "6.  MODIFY ACCOUNT DETAILS" << endl;
	cout << "7.  CLOSE ACCOUNT" << endl;
	cout << "8.  EXIT" << endl;
	cout << endl;
	cout << "SELECT OPTION (1-8): ";
	cin>>select;

	switch(select)
	  {

      case '1':
        acc.create_account();
        goto menu;
        break;

      case '2':

         if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "No Account Created Yet" << endl << endl << endl;
		}
         else{
        int j,amnt;
        cout << "Enter Account Number to Deposit Amount:  ";
        cin >> j;
        cout << endl;
        cout << "Enter Deposit Amount:  ";
        cin >> amnt;
        cout << endl;
        acc.deposits(amnt,j);
        cout<<endl<<endl;
         }
         goto menu;
        break;

      case '3':
          if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "No Accounts Created Yet" << endl << endl << endl;
		}
		else{
            int j, amnt;
            cout << "Enter Account Number to Withdraw Amount:  ";
            cin >> j;
            cout << endl;
            cout << "Enter Amount To Be Withdrawed:  ";
            cin >> amnt;
            cout << endl;
            acc.withdraws(amnt,j);
            cout<<endl<<endl;
		}
		goto menu;
        break;

      case '4':
         if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "No Accounts Created Yet" << endl << endl << endl;
		}

		else{
            int j;

            cout << "Enter Account Number to Check Balance:  ";
            cin >> j;
            acc.show_balance(j);
            cout<<endl<<endl;

		}
		goto menu;
		break;

		case '5':
		if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "No Accounts Created Yet" << endl << endl << endl;
		}
		else{
		    int j;
		    cout << "Enter  Account Number to display Details:";
		    cin >>j;
            acc.show_account(j);
            cout<<endl<<endl;
		}
		goto menu;
		break;

		case '6':
			if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "No Accounts Created Yet" << endl << endl << endl;
		}

		else{
		    int j;
		    cout << "Enter  Account Number to Modify details :";
		    cin >> j;
		    if(j==acc.getA_no()){
		    acc.modify(j);
		    }
		    else{
		        cout << "Invalid Account Number"<<endl;
		    }
		    cout<<endl;
		    cout << "Account Modified Successfully..." <<endl;
		    cout<<endl<<endl;
		}
		goto menu;
		break;

		case '7':
		if (account::getT_acc() == 0) {
			cout << endl << endl << endl;
			cout << "No Accounts Created Yet" << endl << endl << endl;
		}
		else{
		    int j;

		    cout << "Enter your Account Number to close Account:";
		     cin >> j;
		    cout << endl;

		    acc.close(j);
		    cout << "Account closed Successfully.."<<endl;
		    cout<<endl<<endl;
		}
		goto menu;
		break;

		case '8':
		cout << endl;
		cout << "SYSTEM EXIT.."<< endl;
		cout << "THANK YOU"<<endl;

		break;

	  }
    }






    return 0;
}
