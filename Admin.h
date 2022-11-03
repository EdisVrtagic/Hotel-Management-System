#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Gosti.h"
#include "Radnici.h"
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
void upisradnika();
void radnikform();
void rshowlist();
void editradnik();
void rbrisanje();
void radnikMenu();
void sbrisanje();
/***********ADMIN PODACI ZA LOGIN**********/
string adminUser = "admin";
string adminPass = "admin123";
/***********FUNKCIJA ZA POZIVANJE LOGIN FORMI**********/
void pocetnilogin();
void adminform();
void adminMenu();
/***********LISTA SVIH GOSTIJU**********/
void Gost::showlist()
{
    system("CLS");
    fstream gostFile;
    gostFile.open("Gosti.txt", ios::in);
    if (!gostFile)
    {
        cout << "\nFajl nije otvoren jer je prazan!";
        gostFile.close();
    }
    else
    {
        gostFile >> ime >> prezime >> username >> password >> pansion >> usluge >> id >> sobica >> cijena >> prezerv >> krezerv;
        while (!gostFile.eof())
        {
            cout << "\n*****Gost info*****";
            cout << "\nID: " << id;
            cout << "\nIme: " << ime;
            cout << "\nPrezime: " << prezime;
            cout << "\nUsername: " << username;
            cout << "\nPassword: " << password;
            cout << "\nBroj sobe: " << sobica;
            cout << "\nPansion: " << pansion;
            cout << "\nUsluge: " << usluge;
            cout << "\nDatum rezervacije: " << prezerv;
            cout << "\nIstek rezervacije: " << krezerv;
            cout << "\nCijena: " << cijena;
            gostFile >> ime >> prezime >> username >> password >> pansion >> usluge >> id >> sobica >> cijena >> prezerv >> krezerv;
        }
    }
    gostFile.close();
}
/***********PRETRAZIVANJE GOSTA**********/
void Gost::sgost()
{
    system("CLS");
    fstream file;
    int brojac = 0;
    file.open("Gosti.txt", ios::in);
    if (!file)
    {
        cout << "\nFajl nije otvoren jer je prazan!"<<endl;
    }
    else
    {
        int ids;
        cout << "\nUnesite ID: ";
        cin>>ids;
        file >> ime >> prezime >> username >> password >> pansion >> usluge >> id >> sobica >> cijena >> prezerv >> krezerv;
        while (!file.eof())
        {
            if (ids == id)
            {
                cout << "\n*****Gost info*****";
                cout << "\nID: " << id;
                cout << "\nIme: " << ime;
                cout << "\nPrezime: " << prezime;
                cout << "\nUsername: " << username;
                cout << "\nPassword: " << password;
                cout << "\nBroj sobe: " << sobica;
                cout << "\nPansion: " << pansion;
                cout << "\nUsluge: " << usluge;
                cout << "\nDatum rezervacije: " << prezerv;
                cout << "\nIstek rezervacije: " << krezerv;
                cout << "\nCijena: " << cijena;
                brojac++;
            }
            file >> ime >> prezime >> username >> password >> pansion >> usluge >> id >> sobica >> cijena >> prezerv >> krezerv;
        }
        if (brojac == 0)
        {
            cout << ("Gost sa tim ID ne postoji!");
        }
        file.close();
    }
}
/***********EDIT GOST**********/
void Gost::editgost()
{
    system("CLS");
    fstream baza,baza1;
    int unID;
    baza.open("Gosti.txt", ios::in);
    if (!baza)
    {
        cout << "\nFajl nije otvoren jer je prazan!"<<endl;
    }
    else
    {
        cout << "\nUnesi ID: ";
        cin >> unID;
        baza1.open("record.txt", ios::app | ios::out);
        baza >> ime >> prezime >> username >> password >> pansion >> usluge >> id >> sobica >> cijena >> prezerv >> krezerv;
        while (!baza.eof())
        {
            if (unID != id)
                baza1 << "" << ime << "  " << prezime << "  " << username << "  " << password << "  " << pansion << "  " << usluge << "  " << id << "  " << sobica << "  " << cijena << "  " << prezerv << "  " << krezerv <<"\n";
            else
            {
                cout << "Unesite novo ime: ";
                cin>>ime;
                cout << "\nUnesite novo prezime: ";
                cin>>prezime;
                cout << "\nUnesite novi username: ";
                cin>>username;
                cout << "\nUnesite novi password: ";
                cin>>password;
                cout << "\nUnesite novi ID: ";
                cin>>id;
                cout << "\nUnesite vrstu pansiona: ";
                cin>>pansion;
                cout << "\nUnesite dodatne usluge: ";
                cin>>usluge;
                cout << "\nUnesite novu cijenu: ";
                cin>>cijena;
                cout << "\nUnesite novi datum rezervacije: ";
                cin>>prezerv;
                cout << "\nUnesite novi krajnji datum rezervacije: ";
                cin>>krezerv;
                baza1 << "" << ime << "  " << prezime << "  " << username << "  " << password << "  " << pansion << "  " << usluge << "  " << id << "  " << sobica << "  " << cijena << "  " << prezerv << "  " << krezerv <<"\n";
            }
            baza >> ime >> prezime >> username >> password >> pansion >> usluge >> id >> sobica >> cijena >> prezerv >> krezerv;
        }
        baza1.close();
        baza.close();
        remove("Gosti.txt");
        rename("record.txt", "Gosti.txt");
    }
}
/***********DELETE GOST**********/
void Gost::brisanje()
{
    system("CLS");
    fstream file, file1;
    int uneID;
    file.open("Gosti.txt", ios::in);
    if (!file)
    {
        cout << "\nFajl nije otvoren jer je prazan!"<<endl;
        file.close();
    }
    else
    {
        cout << "\nUnesi ID: ";
        cin >> uneID;
        file1.open("record.txt", ios::app | ios::out);
        file >> ime >> prezime >> username >> password >> pansion >> usluge >> id >> sobica >> cijena >> prezerv >> krezerv;
        while (!file.eof())
        {
            if (uneID != id)
            {
                file1 << "" << ime << "  " << prezime << "  " << username << "  " << password << "  " << pansion << "  " << usluge << "  " << id << "  " << sobica << "  " << cijena << "  " << prezerv << "  " << krezerv <<"\n";
            }
            else
            {
                cout << "\nKorisnicki profil uspjesno izbrisan iz baze!";
            }
            file >> ime >> prezime >> username >> password >> pansion >> usluge >> id >> sobica >> cijena >> prezerv >> krezerv;
        }
        file1.close();
        file.close();
        remove("Gosti.txt");
        rename("record.txt", "Gosti.txt");
    }
}
/***********ADMIN LOGIN**********/
void adminform()
{
        system("CLS");
        string pass,uname;
        cout << "**********ADMIN LOGIN**********";
        cout << "\nUnesite username: ";
        cin>>uname;
        cout << "\nUnesite password: ";
        cin>>pass;
        if(uname == adminUser && pass == adminPass)
        {
            cout << "\n*****Welcome Admin*****" <<endl;
            adminMenu();
        }
        else
        cout << "\nNetacan username ili password!" <<endl;
}
/***********ADMIN MENU**********/
void adminMenu()
{
	int unos;
	Gost op;
	Radnik ops;
	Soba so;
	while(true)
	{
	cout << "\n**********ADMIN MENU**********";
    cout << "\n\n1.) Kreiraj gosta";
    cout << "\n2.) Lista gostiju";
    cout << "\n3.) Info gost";
    cout << "\n4.) Edit gost";
    cout << "\n5.) Izbrisi gosta";
    cout << "\n6.) Kreiraj radnika";
    cout << "\n7.) Lista radnika";
    cout << "\n8.) Edit radnik";
    cout << "\n9.) Izbrisi radnika";
    cout << "\n10.) Lista soba";
    cout << "\n11.) Izbrisi sobu";
    cout << "\n12.) Log out";
    cout << "\nUnesite vas odabir: ";
	cin>>unos;
	switch(unos)
	{
		case 1:
        so.dsobu();
        break;
		case 2:
        op.showlist();
        break;
		case 3:
        op.sgost();
        break;
        case 4:
        op.editgost();
        break;
        case 5:
        op.brisanje();
        break;
        case 6:
        ops.upisradnika();
        break;
		case 7:
        ops.rshowlist();
        break;
		case 8:
        ops.editradnik();
        break;
        case 9:
        ops.rbrisanje();
        break;
        case 10:
        so.sobelist();
        break;
        case 11:
        so.sbrisanje();
        break;
        case 12:
        cout<<"Odjavili ste se!"<<endl;
        pocetnilogin();
        break;
		default:
        cout<<"Pogresan izbor!"<<endl;
        break;
	}
  }
}

#endif // ADMIN_H_INCLUDED
