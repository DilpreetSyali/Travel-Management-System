#include <iostream>
#include <fstream>
#include <iomanip>
#include <bits/stdc++.h>
#include <cstring>
#include <string>
#include <queue>
using namespace std;
queue<string> q1;
queue<int> q2;
queue<string> q3;
queue<int> q4;
queue<int> q5;
queue<int> q6;
static int p = 0;
void menu();

class ManageMenu
{
protected:
    string userName; // hide admin name

public:
    ManageMenu()
    {
        cout << "\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        cout << "\n\t\t\t WELCOME \n\n\n";
        menu(); // call to main function to load after executing the constructor
    }

    ~ManageMenu() {}
};

class Customer
{
public:
    // char name[100];
    string name, gender, address, uid, mobileNo;
    int age, menuBack, f = 0;
    static int cusID;
    char all[999];

    void getDetails()
    {
        // static float lastCabCost = 0.0;
        // static float hotelCost = 0.0;
        f = 0;
        ofstream fout("cusid.txt", ios::app); // open file using append mode to write customer details
        {
            cout << "\nEnter Customer ID: ";
            cin >> cusID;
        }
        // fout << cusID << endl;
        uid = to_string(cusID);
        fout.close();
        ifstream fin("cusid.txt");
        {
            if (!fin)
            {
                cout << "File Error!" << endl;
            }
            while (!(fin.eof()))
            {
                fin.getline(all, 999);
                if (all == uid)
                {
                    f = 1;
                    break;
                }
                f = 0;
            }
            if (f == 1)
            {
                cout << "Not Unique Id .... Re-enter details : " << endl;
                getDetails();
            }
            fin.close();
        }
        ofstream gout("cusid.txt", ios::app); // open file using append mode to write customer details
        gout << cusID << endl;
        gout.close();
        ofstream out("old-customers.txt", ios::app); // open file using append mode to write customer details
        {
            cout << "Enter Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Age: ";
            cin >> age;
            do
            {
                cout << "Enter valid Mobile Number: ";
                cin >> mobileNo;
            } while (mobileNo.length() != 10);
            // cout << "Enter Mobile Number: ";
            // cin >> mobileNo;
            cout << "Address: ";
            cin >> address;
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nPlease wait while we save your record!!\n"
             << endl;
        cout << "Saved!!" << endl;
        menu();
    }
    void showDetails() // function to show old customer records
    {
        ifstream in("old-customers.txt");
        {
            if (!in)
            {
                cout << "File Error!" << endl;
            }
            while (!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

int Customer::cusID;

class Cabs
{
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastCabCost;

    void cabDetails()
    {
        cout << "We collaborated with fastest, safest, and smartest cab service arround the country" << endl;
        cout << "-----------GEU Cabs-----------\n"
             << endl;
        cout << "1. Rent a Standard Cab - Rs.15 for 1KM" << endl;
        cout << "2. Rent a Luxury Cab - Rs.25 per 1KM" << endl;

        cout << "\nEnter another key to back or," << endl;

        cout << "\nTo calculate the cost for your journey.." << endl;
        cout << "Enter which kind of cab you need: ";
        cin >> cabChoice;
        cout << "Enter Kilometers you have to travel: ";
        cin >> kilometers;

        int hireCab;

        if (cabChoice == 1)
        {
            cabCost = (kilometers * 15);
            cout << "\nYour tour will cost " << cabCost << " rupees for a standard cab" << endl;
            cout << "Press 1 to hire this cab: or " << endl;
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired standard cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                system("CLS");
                cabDetails();
            }
        }
        else if (cabChoice == 2)
        {
            cabCost = (kilometers * 25);
            cout << "\nYour tour will cost " << cabCost << " rupees for a luxury cab" << endl;
            cout << "Press 1 to hire this cab: or " <<endl;
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired luxury cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                cabDetails();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab;
        if (hireCab == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
};

float Cabs::lastCabCost;

class Booking
{
public:
    int choiceHotel;
    int packChoice1;
    int gotoMenu;
    static float hotelCost;

    void hotels()
    {
        string hotelNo[] = {"Avendra", "ChoiceYou", "ElephantBay"};
        for (int a = 0; a < 3; a++)
        {
            cout << (a + 1) << ". Hotel " << hotelNo[a] << endl;
        }

        cout << "\nCurrently we collaborated with above hotels!" << endl;

        cout << "Press any key to back or\nEnter Number of the hotel you want to book or see details: ";
        cin >> choiceHotel;

        if (choiceHotel == 1)
        {
            cout << "-------WELCOME TO HOTEL AVENDRA-------\n"
                 << endl;

            cout << "The Garden, food and beverage. Enjoy all you can drink, Stay cool and get chilled in the summer sun." << endl;

            cout << "Packages offered by Avendra:\n"
                 << endl;

            cout << "1. Standard Pack" << endl;
            cout << "\tAll basic facilities you need just for: Rs.5000.00" << endl;
            cout << "2. Premium Pack" << endl;
            cout << "\tEnjoy Premium: Rs.10000.00" << endl;
            cout << "3. Luxury Pack" << endl;
            cout << "\tLive a Luxury at Avendra: Rs.15000.00" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "\nYou have successfully booked Standard Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "\nYou have successfully booked Premium Pack at Avendra" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 15000.00;
                cout << "\nYou have successfully booked Luxury Pack at Avendra" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 2)
        {
            cout << "-------WELCOME TO HOTEL CHOICEYOU-------\n"
                 << endl;

            cout << "Swimming Pool | Free WiFi | Family Rooms \n Fitness Center | Restaurant & Bar" << endl;

            cout << "Packages Offered by ChoiceYou:\n"
                 << endl;

            cout << "1. Family Pack" << endl;
            cout << "\t Rs.15000.00 for a day" << endl;
            cout << "2. Couple Pack" << endl;
            cout << "\t Rs.10000.00 for a day" << endl;
            cout << "3. Single Pack" << endl;
            cout << "\t 5000.00 for a day" << endl;

            cout << "\nPress another key to back or\nEnter Package number you want to book: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 15000.00;
                cout << "You have successfully booked Family Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 2)
            {
                hotelCost = 10000.00;
                cout << "You have successfully booked Couple Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else if (packChoice1 == 3)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked Single Pack at ChoiceYou" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                hotels();
            }

            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else if (choiceHotel == 3)
        {
            cout << "-------WELCOME TO HOTEL ELEPHANTBAY-------\n"
                 << endl;
            cout << "Set in tropical gardens on the banks of the Maha Oya river While Seeing Elephants" << endl;
            cout << "Amazing offer in this summer: Rs.5000.00 for a one day!!!" << endl;

            cout << "\nPress another key to back or\nPress 1 to book this special package: ";
            cin >> packChoice1;

            if (packChoice1 == 1)
            {
                hotelCost = 5000.00;
                cout << "You have successfully booked ElephantBay Special Pack" << endl;
                cout << "Goto Menu and take the receipt" << endl;
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                hotels();
            }
            cout << "\nPress 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            menu();
        }
    }
};
float Booking::hotelCost;

class a
{
  char busn[5], driver[10], arrival[5], depart[5], from[10], to[10], seat[8][4][10];

public:

  void install();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);
  double money();

}bus[10];

void vline(char ch)

{

  for (int i=80;i>0;i--)
  cout<<ch;
}

void a::install()
{

  cout<<"Enter Vehicle no: ";
  cin>>bus[p].busn;
  cout<<"\nEnter Vehicle Driver's name: ";
  cin>>bus[p].driver;
  cout<<"\nVehicle Arrival time: ";
  cin>>bus[p].arrival;
  cout<<"\nVehicle Departure: ";
  cin>>bus[p].depart;
  cout<<"\nFrom: \t\t\t";
  cin>>bus[p].from;
  cout<<"\nTo: \t\t\t";
  cin>>bus[p].to;
  bus[p].empty();
  p++;

}

void a::allotment()

{
  int seat;
  char number[5];
  top:
  cout<<"Vehicle no: ";
  cin>>number;
  int n;
  for(n=0;n<=p;n++)
  {

    if(strcmp(bus[n].busn, number)==0)
    break;

  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this vehicle.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
        cout<<"Enter passanger's name: ";
        cin>>bus[n].seat[seat/4][(seat%4)-1];
        break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
      }

    if(n>p)
    {
      cout<<"Enter correct Vehicle no.\n";
      goto top;
    }
  }

void a::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}

void a::show()
{
  int n;
  char number[5];
  cout<<"Enter vehicle no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  vline('*');
  cout<<"Vehicle no: \t"<<bus[n].busn
  <<"\nDriver: \t"<<bus[n].driver<<"\t\tArrival time: \t"
  <<bus[n].arrival<<"\tDeparture time:"<<bus[n].depart
  <<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t"<<
  bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
      if(strcmp(bus[n].seat[i][j],"Empty")!=0)
      cout<<"\nThe seat no "<<(a-1)<<" is reserved for "<<bus[n].seat[i][j]<<".";
    }
  }
  break;
  }
  if(n>p)
    cout<<"Enter correct vehicle no: ";
}
void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
        {
          cout.width(5);
          cout.fill(' ');
          cout<<s<<".";
          cout.width(10);
          cout.fill(' ');
          cout<<bus[l].seat[i][j];
          p++;
        }
        else
        {
        cout.width(5);
        cout.fill(' ');
        cout<<s<<".";
        cout.width(10);
        cout.fill(' ');
        cout<<bus[l].seat[i][j];
        }
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Vehicle No: "<<bus[l].busn;
  }
void a::avail()
{
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<"Vehicle no: \t"<<bus[n].busn<<"\nDriver: \t"<<bus[n].driver
    <<"\t\tArrival time: \t"<<bus[n].arrival<<"\tDeparture Time: \t"
    <<bus[n].depart<<"\nFrom: \t\t"<<bus[n].from<<"\t\tTo: \t\t\t"
    <<bus[n].to<<"\n";
    vline('*');
    vline('_');
  }

}
double a::money()
{
    double dist;
    cout << "enter distance in km to travel from bus (if any ,else enter 0)" << endl;
    cin >> dist;
    cout << "amount to be paid :" << dist * 150 << endl;
    // Add a return statement, for example:
    return dist * 150;
}

class train
{
    public:
    char name[20], food[10];
    int ticket, mob, noc, fid, pid, dep, arr, time;
    static int s;
    static float bil;

    void show ()
    {
        cout << "\n\t\t\t---- WELCOME TO GEU RAILWAYS ----   \n\n";
    }

    void list()
    {
        cout << "\t     ** TRAIN DEPARTURE AND ARRIVAL TABLE **\n\n";
        cout << "\tSno | Pack Id  |  train Id  |  Departure   |   ARRIVAL    | Price |\n\n";
        cout << "\t 1  |   1001   |  TN-1235   |  DEHRADUN    | ROORKEE      | 650* \n";
        cout << "\t 2  |   1002   |  TN-1250   |  DEHRADUN    | KOTA         | 1500* \n";
        cout << "\t 3  |   1003   |  TN-3243   |  DEHRADUN    | PATNA        | 2000* \n";
        cout << "\t 4  |   1004   |  TN-2786   |  DEHRADUN    | GUJARAT      | 2500* \n";
        cout << "\t 5  |   1005   |  TN-3350   |  DEHRADUN    | TAMILNADU    | 3000* \n";
        cout << "\t *GST included\n\n";
        cout <<"\tPACK ID 1001 = chair car\n \tPACK ID 1002 = chair and sleeper car \n \tPACK ID 1003 = sleeper car \n \tPACK ID 1004= 1st AC sleeper car \n\tpack ID 1005 = 2ND AC sleeper car\n\n\n";
    }

    void information ()
    {
            cout<<" \t|  TRAIN ID  | NUMBER OF STOPS |  STOPPAGE  |  DISTANCE            |\n\n";

            cout<<" \t|  TN-1235   |  01(HARIDWAR)   |  5 MINS    |  52KM                |\n";
            cout<<endl;
            cout<<" \t|  TN-1250   |  09(HARIDWAR)   |  5 MINS    |  52KM                |\n";
            cout<<" \t|            |    (ROORKEE)    |  2 MINS    |  93KM                |\n";
            cout<<" \t|            |(MUZAFFARNAGAR)  |  2 MINS    |  177KM               |\n";
            cout<<" \t|            |    (MEERUT)     |  2 MINS    |  232KM               |\n";
            cout<<" \t|            |    (GHAZIABAD)  |  2 MINS    |  280KM               |\n";
            cout<<" \t|            |    (DELHI(NZM)) |  15 MINS   |  302KM               |\n";
            cout<<" \t|            |    (BHARATPUR)  |  2 MINS    |  469KM               |\n";
            cout<<" \t|            |    (GANGAPUR)   |  2 MINS    |  588KM               |\n";
            cout<<endl;
            cout<<" \t|   TN-3243  |   07(HARIDWAR)  |  2 MINS    |   52KM               |\n";
            cout<<" \t|            |    (MORADABAD)  |  2 MINS    |   100KM              |\n";
            cout<<" \t|            |    (BAREILLY)   |  2 MINS    |   250KM              |\n";
            cout<<" \t|            |    (LUCKNOW)    |  15 MINS   |   229KM              |\n";
            cout<<" \t|            |    (SULTANPUR)  |  2 MINS    |   350KM              |\n";
            cout<<" \t|            |    (VARANASI)   |  2 MINS    |   400KM              |\n";
            cout<<" \t|            |    (BUXAR)      |  2 MINS    |   450KM              |\n";
            cout<<" \t|            | (ARA JUNCTION)  |  2 MINS    |   550KM              |\n";
            cout<<endl;
            cout<<" \t|  TN-2786   |  11(HARIDWAR)   |  5 MINS    |  52KM                |\n";
            cout<<" \t|            |    (ROORKEE)    |  2 MINS    |  93KM                |\n";
            cout<<" \t|            |(MUZAFFARNAGAR)  |  2 MINS    |  177KM               |\n";
            cout<<" \t|            |    (MEERUT)     |  2 MINS    |  232KM               |\n";
            cout<<" \t|            |    (GHAZIABAD)  |  2 MINS    |  280KM               |\n";
            cout<<" \t|            |    (DELHI(NZM)) |  15 MINS   |  302KM               |\n";
            cout<<" \t|            |    (GURGAON)    |  2 MINS    |  469KM               |\n";
            cout<<" \t|            |(ALWAR JUNCTION) |  2 MINS    |  588KM               |\n";
            cout<<" \t|            |(AJMER JUNCTION) |  2 MINS    |  93KM                |\n";
            cout<<" \t|            |(RAJKOT JUNCTION)|  2 MINS    |  177KM               |\n";
            cout<<" \t|            |    (HAPA)       |  2 MINS    |  232KM               |\n";
            cout<<" \t|            |    (DWARKA)     |  2 MINS    |  280KM               |\n";
            cout<<endl;
            cout<<" \t|  TN-3350   |  11(HARIDWAR)   |  5 MINS    |  52KM                |\n";
            cout<<" \t|            |    (ROORKEE)    |  2 MINS    |  93KM                |\n";
            cout<<" \t|            |(MUZAFFARNAGAR)  |  2 MINS    |  177KM               |\n";
            cout<<" \t|            |    (MEERUT)     |  2 MINS    |  232KM               |\n";
            cout<<" \t|            |    (GHAZIABAD)  |  2 MINS    |  280KM               |\n";
            cout<<" \t|            |    (DELHI(NZM)) |  15 MINS   |  302KM               |\n";
            cout<<" \t|            |    (GURGAON)    |  2 MINS    |  469KM               |\n";
            cout<<" \t|            |(ALWAR JUNCTION) |  2 MINS    |  588KM               |\n";
            cout<<" \t|            |(AJMER JUNCTION) |  2 MINS    |  93KM                |\n";
            cout<<" \t|            |(RAJKOT JUNCTION)|  2 MINS    |  177KM               |\n";
            cout<<" \t|            |    (HAPA)       |  2 MINS    |  232KM               |\n";
            cout<<" \t|            |    (DWARKA)     |  2 MINS    |  280KM               |\n";
            cout<<endl;
            cout<<" \t|  TN-2786   |  12(HARIDWAR)   |  5 MINS    |  52KM                |\n";
            cout<<" \t|            |    (ROORKEE)    |  2 MINS    |  93KM                |\n";
            cout<<" \t|            |(MUZAFFARNAGAR)  |  2 MINS    |  177KM               |\n";
            cout<<" \t|            |    (MEERUT)     |  2 MINS    |  232KM               |\n";
            cout<<" \t|            |    (GHAZIABAD)  |  2 MINS    |  280KM               |\n";
            cout<<" \t|            |    (DELHI(NZM)) |  15 MINS   |  302KM               |\n";
            cout<<" \t|            |    (GURGAON)    |  2 MINS    |  469KM               |\n";
            cout<<" \t|            |(ALWAR JUNCTION) |  2 MINS    |  588KM               |\n";
            cout<<" \t|            |(AJMER JUNCTION) |  2 MINS    |  93KM                |\n";
            cout<<" \t|            |(RAJKOT JUNCTION)|  2 MINS    |  177KM               |\n";
            cout<<" \t|            |    (HAPA)       |  2 MINS    |  232KM               |\n";
            cout<<" \t|            |    (DWARKA)     |  2 MINS    |  280KM               |\n";
            cout<<" \t|            |    (OKHA)       |  2 MINS    |  93KM                |\n";
            cout<<endl;

    }

    train book()
{
    a:
    cout << "\t\t\t** ! BOOKING ! **\n\n";
    cout << "TICKETS REMAINING: ";
    cout << s << endl
         << endl;
    if (s > 0)
    {
        cout << "Enter the package id : ";
        cin >> pid;
        q6.push(pid);
        if (pid >= 1001 && pid <= 1005)
            cout << "\nPack is available !\n\n";
        else
        {
            cout << "Invalid pack !\n\n";
            goto a;
        }
        cout << "Name      : ";
        cin >> name;
        q1.push(name);
        cout << "Seats     : ";
        cin >> noc;
        if(noc<=10)
        {
        q2.push(noc);
        cout << "Food      : ";
        cin >> food;
        q3.push(food);
        cout << "Departure DATE : ";
        cin >> dep;
        q4.push(dep);
        cout << "Arrival DATE  : ";
        cin >> arr;
        q5.push(arr);
        time = arr - dep;
        if (time < 0)
            cout << "Error ! Enter valid dates !\n\n";
        else
        {
            s -= noc;
            cout << endl;
            cout << "Congrats ! Your ticket has been booked ! Have a safe journey !\n";
            cout << endl;
        }
        }
        else
        {
            cout<<"only 10 people at a time are allowed !"<<endl;
                      cout<<endl;
            cout<<"**you can opt for booking separately for the people left\n\n";
            cout<<"keep in mind that seats alloted in this case might NOT BE IN THE SAME COMPARTMENT"<<endl;
        }
    }

    // Add a return statement, for example:
    return *this;
}
train bill()
{
    if (pid == 1001)
        bil += 650 * noc;
    else if (pid == 1002)
        bil +=  1500* noc;
    else if (pid == 1003)
        bil += 2000 * noc;
    else if (pid == 1004)
        bil += 2500 * noc;
    else if (pid == 1005)
        bil += 3000 * noc;
    else
        cout << "The pack isnt available now !\n";
    // Add a return statement, for example:
    return *this;
}
train details()
{
    bill();
    cout << "\t\t\t** TRAVEL DETAILS **\n\n";
    cout << "Name     : " << q1.front() << endl;
    cout << "Seats    : " << q2.front() << endl;
    cout << "Dep date : " << q4.front() << endl;
    cout << "Arr date : " << q5.front() << endl;
    cout << "Food     : " << q3.front() << endl;
    cout << "Bill     : Rs. " << bil << endl
         << endl;
    // Add a return statement, for example:
    return *this;
}

};

float train::bil = 0.0;
int train::s = 500;

class Chargers : public Booking, Cabs, Customer, train,a // Multiple Inheritance of some other classes to Chargers
{

public:
    void printBill()
    {
        ofstream outf("receipt.txt"); // receipt for bought items
        {
            outf << "--------GEU Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            outf << "Customer ID: " << Customer::cusID << endl
                 << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Hotel cost:\t\t " << fixed << setprecision(2) << Booking::hotelCost << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;
            outf << "Travel (train) cost:\t " << fixed << setprecision(2) << train::bil << endl;
            double busCost = a::money();
            outf << "Travel (bus) cost:\t " << fixed << setprecision(2) << busCost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Booking::hotelCost + Cabs::lastCabCost + train::bil  + busCost<< endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();
        // cout << "Your receipt printed, please get it from the file saved path:D" << endl;
    }

    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File Error!" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};

void menu() // menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * GEU Travels *\n"
         << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;

    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    // cout << "\t|\tAgency System Management -> 0" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tHotel Booking Management -> 3\t|" << endl;
    cout << "\t|\tBus Booking Management-> 4\t|" << endl;
    cout << "\t|\tTrain Booking Management-> 5\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 6\t|" << endl;
    cout << "\t|\tExit                -> 7\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    Customer a2; // creating objects
    Cabs a3;
    Booking a4;
    Chargers a5;
    train t;

    if (mainChoice == 1)
    {
        cout << "------Customers------\n"
             << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;
        cout << "\nEnter choice: ";
        cin >> inChoice;
        if (inChoice == 1)
        {
            a3.lastCabCost = 0.0;
            a4.hotelCost = 0.0;
            t.bil = 0.0;
            a2.getDetails();
        }
        else if (inChoice == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        a3.cabDetails();
    }
    else if (mainChoice == 3)
    {
        cout << "--> Book a Luxury Hotel using the System <--\n"
             << endl;
        a4.hotels();
    }
    else if (mainChoice == 4)
    {
        cout<<"-->---------GEU BUS TRAVELS------- <--"<<endl;
        cout<<"-->book bus tickets for yourself <--"<<endl;
         int w;

while(1)
{
  cout<<"\n\n\n\n\n";
  cout<<"\t\t\t1.Install\n\t\t\t"
  <<"2.Reservation\n\t\t\t"
  <<"3.Show\n\t\t\t"
  <<"4.Vehicles Available. \n\t\t\t"
  <<"5.Exit";
  cout<<"\n\t\t\tEnter your choice:-> ";
  cin>>w;
  switch(w)
  {
    case 1:  bus[p].install();
      break;
    case 2:  bus[p].allotment();
      break;
    case 3:  bus[0].show();
      break;
    case 4:  bus[0].avail();
      break;
    case 5:  menu();
  }
}
    }
    else if (mainChoice == 5)
    {
        t.show();
        int ch;
        cout << "**1. Available trains ** ** 2. Booking ** ** 3. Details ** **4.information** ** 5. Go to main menu ** \n\n";
        cin >> ch;
        while (1)
        {
            switch (ch)
            {
            case 1:
                t.list();
                break;
            case 2:
                t.book();
                break;
            case 3:
                t.details();
                break;
            case 4:
                t.information ();
                break;
            case 5:
                menu();
            }
            cout << "**1. Available trains ** ** 2. Booking ** ** 3. Details ** **4.information** ** 5. Go to main menu ** \n\n";
            cin >> ch;
        }
        cout << "Enter a key to go back to main menu: ";
        cin >> ch;
        menu();
    }
    else if (mainChoice == 6)
    {
        cout << "-->Get your receipt<--\n"
             << endl;
        a5.printBill();
        cout << "Your receipt is already printed you can get it from file path\n"
             << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            a5.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 7)
    {
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        ManageMenu();
    }
    else
    {
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        menu();
    }
}
int main()
{
    ManageMenu startObj;
    return 0;
}
