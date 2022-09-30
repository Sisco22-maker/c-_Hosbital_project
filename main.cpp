/*
(اللهم صلْ وسلم وزد وبارك على سيدنا محمد )

꧁IslaM_SobhY꧂

 */
#include <bits/stdc++.h>
using namespace std;
#define SUPERPOWER ios_base::sync_with_stdio(false); cout.tie(0);
#define ll long long
#define  el "\12"
//Start the global containers
string Names[100][100];
bool Statuses[100][100];
int Specializations[21] = {0};
int Deleted[21] = {0};
//End the global containers

//Declaring the functions
//----------------------------------------------------------//
int PrintOptions()
{
    cout << "Enter your choice : " << el;
    cout << "1) Add new patients" << el;
    cout << "2) Print all patients" << el;
    cout << "3) Get Next patient " << el;
    cout << "4) Exit" << el;
     int choice;
     cin >> choice;
     return choice;
}
//---------------------------------------------------------//

void PlacePatient(int pos ,string name, bool status,int special)
{
    Names[pos][special] = name;
    Statuses[pos][special] = status;
}

//--------------------------------------------------------//
void AddNewPatient()
{

    cout << "Enter specialization, name, status : ";
    int special;
    string name;
    bool status;
    cin >> special>> name >> status;
     if(Specializations[special] >= 5)
    {
        cout << "Can't Accept Any More Patients !" << el;
        return;
    }
    //----------------------------//
    PlacePatient(Specializations[special],name,  status,  special);
    Specializations[special]++;
}
//------------------------------------------------------//

void PrintPatient()
{
    //------The aurgent  cases ---//
    for(int i = 0; i < 21; i++)
    {
        if(Specializations[i] > 0)
        cout << "SpecializaTion number : " << i << " Has : " << el;
        //-------------------------------//
        int startOne = Deleted[i] + Specializations[i] - 1 ;
        for(int j = startOne ; j >= 0; j--)
        {
            if(Names[j][i] != "null" && Statuses[j][i] == 1)
            {
                cout << Names[j][i] << " " << "Aurgent";
                cout << el;
            }

        }


        //-------------------------//
        int startTwo = Deleted[i] + Specializations[i] - 1 ;
        for(int j = 0; j <= startTwo; j++)
        {
             if(Names[j][i] != "null" && Statuses[j][i] == 0)
            {
                cout << Names[j][i] << " " << "Regular";
                cout << el;
            }
        }

        //---------------------------//
    }
}

//-------------------------------------------------//

void CheckIfAurgent(int choice)
{
    //-------------------------------------------//
      if(Specializations[choice] == 0)
    {
        cout  << "Not Patient At The Moment Have Rest ,Doctor" << el;
        return;
    }
//-------------------------------------------------//
    for(int i = 0; i < 21; i++)
        {
            if(i != choice)continue;
         int startOne = Deleted[i] + Specializations[i] - 1 ;
        for(int j = startOne ; j >= 0; j--)
        {
            if(Statuses[j][i] == 1)
            {
                cout << Names[j][i] << ", Please go With The Doctor!" << el;
                Names[j][i] = "null";
                Specializations[i]--;
                  Deleted[choice]++;
                return;
            }
        }
        }
        //-------------------------------------//

        for(int i = 0; i < 21; i++)
        {
             if(i != choice)continue;
         int startOne = Deleted[i] + Specializations[i] - 1 ;
        for(int j = startOne ; j >= 0; j--)
        {
            if(Statuses[j][i] == 0)
            {
                cout << Names[j][i] << ", Please go With The Doctor!" << el;
                Names[j][i] = "null";
                  Specializations[i]--;
                  Deleted[choice]++;
                return;
            }
        }
        }
        //-------------------------------------------//
}

//-------------------------------------------------//

void GetNextPatient()
{
    cout << "Enter Specialization : ";
    int choice;
    cin >> choice;
    CheckIfAurgent(choice);

}

//-------------------------------------------------//

void MainControle()
{
    while(1)
{
   int ret =  PrintOptions();
   if(ret == 1)
   {
    AddNewPatient();
   }else if(ret == 2)
   {
       PrintPatient();
   }else if(ret == 3)
   {
       GetNextPatient();
   }else if(ret == 4)
   {
     break;
   }
   cout << "*******************************************" << el;
}
}
//End declaring the functions
int main() {
     SUPERPOWER;
int t = 1;//cin >> t;
while(t--)
{
    //write the code here
    //int n;cin >> n;
    MainControle();


}
  return 0;
}





