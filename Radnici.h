#ifndef RADNICI_H_INCLUDED
#define RADNICI_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Gosti.h"
#include "Admin.h"
#include "Sobe.h"

using namespace std;
/***********PUBLIC FUNKCIJE**********/
void gostform();
void showlist();
void sgost();
void editgost();
void adminMenu();
void adminform();
void brisanje();
void radnikMenu();
void pocetnilogin();
/***********KLASA GOST**********/
class Radnik
{
	private:
    string rusername,rpassword;
    int rid;
/***********PUBLIC FUNKCIJE**********/
public:
void upisradnika();
void radnikform();
void rshowlist();
void editradnik();
void rbrisanje();
/***********GETTER I SETTER ZA USERNAME RADNIKA**********/
void setRName(string nRname)
{
nRname = rusername;
}

string getRName()
{
return rusername;
}
/***********GETTER I SETTER ZA PASSWORD RADNIKA**********/
void setRPass(string nrPass)
{
nrPass = rpassword;
}

string getRPass()
{
return rpassword;
}
/***********GETTER I SETTER ZA ID RADNIKA**********/
void setRID(int nrID)
{
rid = nrID;
}

int getRID()
{
return rid;
}
/***********KONSTRUKTOR**********/
Radnik(string nRname, string nrPass, int nrID)
{
rusername = nRname;
rpassword = nrPass;
rid = nrID;
}
/***********PRAZAN KONSTRUKTOR**********/
Radnik()
{
}
};
/***********KREIRANJE RADNIKA**********/
void Radnik::upisradnika()
{
    system("CLS");
    fstream radnikFile;
    cout << "\nUnesite username: ";
    cin>>rusername;
    cout << "\nUnesite password: ";
    cin>>rpassword;
    cout << "\nUnesite ID: ";
    cin>>rid;
    radnikFile.open("Radnici.txt", ios::app | ios::out);
    Radnik radnik(rusername,rpassword,rid);
    radnikFile << "" << rusername << "  " << rpassword << "  " << rid << "\n";
    radnikFile.close();
}
/***********LISTA SVIH RADNIKA**********/
void Radnik::rshowlist()
{
    system("CLS");
    fstream radnikFile;
    radnikFile.open("Radnici.txt", ios::in);
    if (!radnikFile)
    {
        cout << "\nFajl nije otvoren jer je prazan!";
        radnikFile.close();
    }
    else
    {
        radnikFile >> rusername >> rpassword >> rid;
        while (!radnikFile.eof())
        {
            cout << "\n*****Radnik info*****";
            cout << "\nID: " << rid;
            cout << "\nUsername: " << rusername;
            cout << "\nPassword: " << rpassword;
            radnikFile >> rusername >> rpassword >> rid;
        }
    }
    radnikFile.close();
}
/***********EDIT RADNIK**********/
void Radnik::editradnik()
{
    system("CLS");
    fstream bazar,bazar1;
    int unrID;
    bazar.open("Radnici.txt", ios::in);
    if (!bazar)
    {
        cout << "\nFajl nije otvoren jer je prazan!"<<endl;
    }
    else
    {
        cout << "\nUnesi ID: ";
        cin >> unrID;
        bazar1.open("temp.txt", ios::app | ios::out);
        bazar >> rusername >> rpassword >> rid;
        while (!bazar.eof())
        {
            if (unrID != rid)
                bazar1 << "" << rusername << "  " << rpassword << "  " << rid << "\n";
            else
            {
                cout << "\nUnesite username: ";
                cin>>rusername;
                cout << "\nUnesite password: ";
                cin>>rpassword;
                cout << "\nUnesite ID: ";
                cin>>rid;
                bazar1 << "" << rusername << "  " << rpassword << "  " << rid << "\n";
            }
            bazar >> rusername >> rpassword >> rid;
        }
        bazar1.close();
        bazar.close();
        remove("Radnici.txt");
        rename("temp.txt", "Radnici.txt");
    }
}
/***********DELETE RADNIK**********/
void Radnik::rbrisanje()
{
    system("CLS");
    fstream rfile, rfile1;
    int unerID;
    rfile.open("Radnici.txt", ios::in);
    if (!rfile)
    {
        cout << "\nFajl nije otvoren jer je prazan!"<<endl;
        rfile.close();
    }
    else
    {
        cout << "\nUnesi ID: ";
        cin >> unerID;
        rfile1.open("temp.txt", ios::app | ios::out);
        rfile >> rusername >> rpassword >> rid;
        while (!rfile.eof())
        {
            if (unerID != rid)
            {
                rfile1 << "" << rusername << "  " << rpassword << "  " << rid << "\n";
            }
            else
            {
                cout << "\nRadnicki profil uspjesno izbrisan iz baze!";
            }
            rfile >> rusername >> rpassword >> rid;
        }
        rfile1.close();
        rfile.close();
        remove("Radnici.txt");
        rename("temp.txt", "Radnici.txt");
    }
}
/***********RADNIK LOGIN**********/
void Radnik::radnikform()
{
    system("CLS");
    fstream rfile;
    rfile.open("Radnici.txt", ios::in);
    string radnikpass,raduname;
    cout << "**********EMPLOYEE LOGIN**********";
    cout << "\nUnesite username: ";
    cin>>raduname;
    cout << "\nUnesite password: ";
    cin>>radnikpass;
    while(rfile >> rusername >> rpassword >> rid)
    {
    if(raduname == rusername && radnikpass == rpassword)
    {
        cout << "\n*****Welcome Employee*****" <<endl;
        radnikMenu();
        rfile.close();
        return;
    }
    }
    cout << "\nNetacan username ili password!" <<endl;
    rfile.close();
}
/***********ADMIN MENU**********/
void radnikMenu()
{
    system("CLS");
	int unoss;
	Gost un;
	Soba uni;
	while(true)
	{
	cout << "\n**********EMPLOYEE MENU**********";
    cout << "\n\n1.) Kreiraj gosta";
    cout << "\n2.) Lista gostiju";
    cout << "\n3.) Info gost";
    cout << "\n4.) Edit gost";
    cout << "\n5.) Izbrisi gosta";
    cout << "\n6.) Lista soba";
    cout << "\n7.) Log out";


    cout << "\nUnesite vas odabir: ";
	cin>>unoss;
	switch(unoss)
	{
		case 1:
        uni.dsobu();
        break;
		case 2:
        un.showlist();
        break;
		case 3:
        un.sgost();
        break;
        case 4:
        un.editgost();
        break;
        case 5:
        un.brisanje();
        break;
        case 6:
        uni.sobelist();
        break;
        case 7:
        cout<<"Odjavili ste se!"<<endl;
        pocetnilogin();
        break;
		default:
        cout<<"Pogresan izbor!"<<endl;
        break;
	}
  }
}
#endif // RADNICI_H_INCLUDED
