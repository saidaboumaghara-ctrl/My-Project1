#include<iostream>
#include<iomanip>
#include<vector>
#include<string>
#include <cstdlib>
#include<fstream>
#include <windows.h>
using namespace std;
struct userinfo 
{
    int acountnum;
    int pincode;
    string name;
    int phonenum;
    float blance;

};
vector<userinfo>vuserinfo;
int Mainmenu();
void Showlist();
void Addnew();
void Delete();
void Update();
void Find();
int AtmSys();
void ShowMyMany();
void Addmoney();
void Chekmoney();
void OperType(int num);
void OperationType(int num);
//
int main()
{
    system("color F0");
    while (true)
    {
        int choice = Mainmenu();
        OperationType(choice);
    }
    system("pause");
}
//
int Mainmenu()
{
    system("cls");
    int num = 0; //opertion
    cout << "\n=========================================\n";
    cout << "         WELCOME TO SYRIA BANKS\n";
    cout << "=========================================\n";
    cout << "[1] Show List\n";
    cout << "[2] Add New Client\n";
    cout << "[3] Delete Client\n";
    cout << "[4] Update Client\n";
    cout << "[5] Find Client\n";
    cout << "[6] ATM System\n";
    cout << "[7] Exit\n";
    cout << "=========================================\n";

    cout << "Please enter your operation\n";
    cin >> num;
	return  num ;
    
}
void Showlist()
{
    system("cls");

    string line, accountno, pincode, name, phonenum, balance;

    cout << "==============================================================================\n";
    cout << left
        << setw(15) << "Account No"
        << setw(15) << "Pin Code"
        << setw(20) << "Name"
        << setw(20) << "Phone"
        << setw(15) << "Balance"
        << endl;
    cout << "==============================================================================\n";

    ifstream file("accounts.txt");

    while (getline(file, line))
    {
        accountno = line.substr(0, line.find("#"));
        line.erase(0, line.find("#") + 4);

        pincode = line.substr(0, line.find("#"));
        line.erase(0, line.find("#") + 4);

        name = line.substr(0, line.find("#"));
        line.erase(0, line.find("#") + 4);

        phonenum = line.substr(0, line.find("#"));
        line.erase(0, line.find("#") + 4);

        balance = line.substr(0, line.find("#"));

        cout << left
            << setw(15) << accountno
            << setw(15) << pincode
            << setw(20) << name
            << setw(20) << phonenum
            << setw(15) << balance
            << endl;
    }

    file.close();

    char choice;
    cout << "\nReturn to Main Menu? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        OperationType(Mainmenu());
    }
   
}
void Addnew()
{
    userinfo info;
    cout << "Please enter account number\n";
    cin >> info.acountnum;
    cout << "Please enter pincode\n";
    cin >> info.pincode;
    cout << "Please enter name\n";
    cin.ignore();
    getline(cin, info.name);
    cout << "Please enter phone number\n";
    cin >> info.phonenum;
    cout << "Please enter a Blance\n";
    cin >> info.blance;
    vuserinfo.push_back(info);

    string line =
        to_string(info.acountnum) + "#//#" +
        to_string(info.pincode) + "#//#" +
        info.name + "#//#" +
        to_string(info.phonenum) + "#//#" +
        to_string(info.blance);
    
    ofstream file("accounts.txt", ios::app);
        file << line << endl;
    file.close();

    char cho;

    cout << "\nReturn Add new? (Y/N): ";
    cin >> cho;

    if (cho == 'Y' || cho == 'y')
    {
        Addnew();
    }


    char choice;

    cout << "\nReturn to Main Menu? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        OperationType(Mainmenu());
    }
}
void Delete()
{
    int accountno;
    cout << "Please enter accounts number \n";
    cin >> accountno;
    ifstream file("accounts.txt"); // فتح الملف
    ofstream temp("accounts2.txt");
    string line;
    

    while (getline(file, line))   // قراءة من الملف
    {
        string acc = line.substr(0, line.find("#"));
        
            if (acc!=to_string(accountno))
            {
                temp << line << endl;
            }
        
    }

    file.close();
    temp.close();
    remove("accounts.txt");
    rename("accounts2.txt", "accounts.txt");

    char choice;

    cout << "\nReturn to Main Menu? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        OperationType(Mainmenu());
    }
}
void Update()
{
    int accountno;
    cout << "Please enter a account number ?" << endl;
    cin >> accountno;


    string line;
    ofstream temp("Newfile.txt");
    fstream file("accounts.txt");
    while (getline(file, line))
    {
        string coco = line.substr(0, line.find("#"));
        if (coco!= to_string(accountno))
        {
            temp << line << endl;
        }
        else
        {
            userinfo info;
       
            cout << "Please enter pincode\n";
            cin >> info.pincode;
            cout << "Please enter name\n";
            cin >> info.name;
            cout << "Please enter phone number\n";
            cin >> info.phonenum;
            cout << "Please enter a Blance";
            cin >> info.blance;
           

            string newline =
                to_string(accountno) + "#//#" +
                to_string(info.pincode) + "#//#" +
                info.name + "#//#" +
                to_string(info.phonenum) + "#//#" +
                to_string(info.blance);

            temp << newline << endl;
        }
       
    }
    file.close();
    temp.close();
    remove("accounts.txt");
    rename("Newfile.txt", "accounts.txt");

    char choice;

    cout << "\nReturn to Main Menu? (Y/N): ";
    cin >> choice;

    if (choice == 'Y' || choice == 'y')
    {
        OperationType(Mainmenu());
    }

}
void Find()
{
    int accountno;
    cout << "Please enter a account number ?" << endl;
    cin >> accountno;

    bool found=false;
    string line,targetline;
    fstream file("accounts.txt");
    while (getline(file, targetline))
    {
        string ac = targetline.substr(0, targetline.find("#"));
        if (ac == to_string(accountno))
        {
            found = true;
           line  = targetline; 
            break;
        }
        found = false;

    }
    string acccountno, pincode, name, phonenum, blance;
    file.close();
    if (found == true)
    {
        cout << "Yes account is here" << endl;
        
        fstream file("accounts.txt");

             acccountno = line.substr(0, line.find("#"));
            line.erase(0, line.find("#") + 4);
             pincode = line.substr(0, line.find("#"));
            line.erase(0, line.find("#") + 4);
             name= line.substr(0, line.find("#"));
            line.erase(0, line.find("#") + 4);
             phonenum= line.substr(0, line.find("#"));
            line.erase(0, line.find("#") + 4);
             blance= line.substr(0, line.find("#"));
        
        file.close();
        system("cls");
        cout << "=============================================" << endl;
        cout << "=================USER ACCOUNT================" << endl;
        cout << "ACCOUNT NUMBER :   " << acccountno << endl;
        cout << "PIN CODE :         " << pincode<<endl;
        cout << "NAME :             " << name<<endl;
        cout << "PHONE NUMBER       " << phonenum<<endl;
        cout << "BLANCE :           " << blance<<endl;




    }
    else
    {
        system("cls");
        cout << "No account is not found" << endl;
    }
        char choice;

        cout << "\nReturn to Main Menu? (Y/N): ";
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            OperationType(Mainmenu());
        }
}
int AtmSys()
{
    system("cls");
    int num = 0; //opertion
    cout << "\n=========================================\n";
    cout << "         WELCOME TO ATM\n";
    cout << "=========================================\n";
    cout << "[1] Show My Blanace\n";
    cout << "[2] Add a money\n";
    cout << "[3] chektomany\n";
    cout << "[4] Main menu\n";
    cout << "[5] Exit\n";
    cout << "=========================================\n";

    cout << "Please enter your operation\n";
    cin >> num;
    return  num;

}
void ShowMyMany()
{
    int accountnumber = 0;
    cout << "Please enter account number\n";
    cin >> accountnumber;
    string accountno, pincode, name, phonenum, balance;
    ifstream file("accounts.txt"); // فتح الملف
    
    string line;


    while (getline(file, line))   // قراءة من الملف
    {
        string acc = line.substr(0, line.find("#"));

        if (acc == to_string(accountnumber))
        {

            accountno = line.substr(0, line.find("#"));
            line.erase(0, line.find("#") + 4);

            pincode = line.substr(0, line.find("#"));
            line.erase(0, line.find("#") + 4);

            name = line.substr(0, line.find("#"));
            line.erase(0, line.find("#") + 4);

            phonenum = line.substr(0, line.find("#"));
            line.erase(0, line.find("#") + 4);

            balance = line.substr(0, line.find("#"));

            cout << left
                << "Your Balance is : : > "
                << setw(15) << balance
                <<"$ "
                << endl;
            break;
        }
    }

    file.close();
    int yorn=0;
    cout << "Do you want to  go Atm menu[1]\nDo yo want go for system menu[2]\nDo You want exit [3]\n";
    cin >> yorn;
    if (yorn == 1)
        AtmSys();
    else if (yorn == 2)
        Mainmenu();
    else if (yorn == 3)
        exit(0);



}
void Addmoney() 
{
    int accountnum = 0;
    cout << "Please enter account number\n";
    cin >> accountnum;
    ofstream temp("acc2.txt");
    ifstream file("accounts.txt"); // فتح الملف
    string line;
    while (getline(file, line))
    {
string acc= line.substr(0, line.find("#"));
      if (acc == to_string(accountnum))
      {
          string tempLine = line;

          string accountno = tempLine.substr(0, tempLine.find("#"));
          tempLine.erase(0, tempLine.find("#") + 4);

          string pincode = tempLine.substr(0, tempLine.find("#"));
          tempLine.erase(0, tempLine.find("#") + 4);

          string name = tempLine.substr(0, tempLine.find("#"));
          tempLine.erase(0, tempLine.find("#") + 4);

          string phonenum = tempLine.substr(0, tempLine.find("#"));
          tempLine.erase(0, tempLine.find("#") + 4);

          string balance = tempLine;
          // إضافة المال
          double money;
          cout << "Enter amount to add: ";
          cin >> money;

          double newBalance = stod(balance) + money;

          // كتابة السطر الجديد
          temp << accountno << "#//#"
              << pincode << "#//#"
              << name << "#//#"
              << phonenum << "#//#"
              << newBalance << endl;
          cout << "============================================\n";
          cout << "============================================\n";
          cout << "|                                          |\n";
          cout << "Your New Blance is :: " << newBalance << endl;
          cout << "|                                          |\n";
          cout << "============================================\n";
          cout << "============================================\n";
      }



    }

    file.close();
    temp.close();

    remove("accounts.txt");
    rename("acc2.txt", "accounts.txt");
    int yorn = 0;
    cout << "Do you want to  go Atm menu[1]\nDo yo want go for system menu[2]\nDo You want exit [3]\n";
    cin >> yorn;
    if (yorn == 1)
        AtmSys();
    else if (yorn == 2)
        Mainmenu();
    else if (yorn == 3)
        exit(0);

}
void Chekmoney()
{
    int accnum = 0;
    cout << "Please enter account number\n";
    cin >> accnum;

    ofstream temp("acc2.txt");
    ifstream file("accounts.txt"); // فتح الملف
    string line;
    while (getline(file, line))
    {
        string acc= line.substr(0, line.find("#"));
        if (acc ==to_string(accnum))
        {
            string tempLine = line;

            string accountno = tempLine.substr(0, tempLine.find("#"));
            tempLine.erase(0, tempLine.find("#") + 4);

            string pincode = tempLine.substr(0, tempLine.find("#"));
            tempLine.erase(0, tempLine.find("#") + 4);

            string name = tempLine.substr(0, tempLine.find("#"));
            tempLine.erase(0, tempLine.find("#") + 4);

            string phonenum = tempLine.substr(0, tempLine.find("#"));
            tempLine.erase(0, tempLine.find("#") + 4);

            string balance = tempLine;
            // 
            double money;
            cout << "Enter --to add: ";
            cin >> money;

            double newBalance = stod(balance) - money;

            temp << accountno << "#//#"
                << pincode << "#//#"
                << name << "#//#"
                << phonenum << "#//#"
                << newBalance << endl;
            cout << "============================================\n";
            cout << "============================================\n";
            cout << "|                                          |\n";
            cout << "Your New Blance is :: " << newBalance << endl;
            cout << "|                                          |\n";
            cout << "============================================\n";
            cout << "============================================\n";
        }
        
        
        }
    file.close();
    temp.close();
    remove("accounts.txt");
    rename("acc2.txt", "accounts.txt");
    int yorn = 0;
    cout << "Do you want to  go Atm menu[1]\nDo yo want go for system menu[2]\nDo You want exit [3]\n";
    cin >> yorn;
    if (yorn == 1)
        AtmSys();
    else if (yorn == 2)
        Mainmenu();
    else if (yorn == 3)
        exit(0);

}
void OperType(int num)
{
    switch (num)
    {
    case 1:ShowMyMany();
        break;
    case 2:Addmoney();
        break;
    case 3:
        Chekmoney();
        break;
    case 4: Mainmenu();
        break;
    case 5:
        exit(0);
        break;
    default :
        cout << "Invalid Choice!\n";
}





}
void OperationType(int num)
{
    switch (num)
    {
    case 1:
        Showlist();
        break;

    case 2:
        Addnew();
        break;

    case 3:
        Delete();
        break;

    case 4:
        Update();
        break;

    case 5:
        Find();
        break;

    case 6:
        OperType(AtmSys());
        break;
    case 7 :
        exit(0);
        break;
    default:
        cout << "Invalid Choice!\n";
    }


}
