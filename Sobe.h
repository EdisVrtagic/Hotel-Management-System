#ifndef SOBE_H_INCLUDED
#define SOBE_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Gosti.h"
#include "Radnici.h"

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
/***********KLASA SOBA**********/
class Soba : public Gost
{
	private:
    bool reserved;
/***********PUBLIC FUNKCIJE**********/
public:
void dsobu();
void sobelist();
int provjera(int);
void sbrisanje();
/***********GETTER I SETTER ZA REZERVACIJU SOBE**********/
void setReserv(bool Res)
{
reserved = Res;
}

bool getReserv()
{
return reserved;
}
/***********KONSTRUKTOR**********/
Soba(bool Res)
{
reserved = Res;
}
/***********PRAZAN KONSTRUKTOR**********/
Soba()
{
}
};
/***********KREIRANJE SOBE**********/
void Soba::dsobu()
{
    system("CLS");
    fstream sobaFile;
    sobaFile.open("Sobe.txt", ios::app | ios::out);
    int usob,greska;
    cout << "\n****ADD GUEST****";
    cout << "\nUnesite broj sobe: ";
    cin>>usob;
    while(usob < 100 || usob > 300)
	{
		cout<<"\nBroj sobe ne moze biti manji od 100 ni veci od 300!";
		cout << "\nUnesite broj sobe: ";
		cin>>usob;
	}
    greska = provjera(usob);
    if(greska)
    cout<<"\nSoba je vec rezervisana!";
    else
    {
    sobica = usob;
    cout << "\nUnesite ime: ";
    cin>>ime;
    cout << "\nUnesite prezime: ";
    cin>>prezime;
    cout << "\nUnesite username: ";
    cin>>username;
    cout << "\nUnesite password: ";
    cin>>password;
    cout << "\nUnesite ID: ";
    cin>>id;
    cout << "\nUnesite vrstu pansiona: ";
    cin>>pansion;
    cout << "\nUnesite usluge: ";
    cin>>usluge;
    cout << "\nUnesite poceti datum rezervacije: ";
    cin>>prezerv;
    while(prezerv < 1 || prezerv > 31)
	{
		cout<<"\nDatum ne moze biti manji od 1 ni veci od 31!";
		cout << "\nUnesite poceti datum rezervacije: ";
        cin>>prezerv;
	}
    cout << "\nUnesite krajnji datum rezervacije: ";
    cin>>krezerv;
    while(krezerv < 1 || krezerv > 31)
	{
		cout<<"\nDatum ne moze biti manji od 1 ni veci od 31!";
        cout << "\nUnesite krajnji datum rezervacije: ";
        cin>>krezerv;
	}
    cout << "\nUnesite cijenu apartmana: ";
    cin>>cijena;
    while(cijena < 50 || cijena > 200)
	{
		cout<<"\nCijena ne moze biti manja od 50$ ni veca od 200$!";
		cout << "\nUnesite cijenu apartmana: ";
        cin>>cijena;
	}
    fstream gostFile;
    gostFile.open("Gosti.txt", ios::app | ios::out);
    gostFile << "" << ime << "  " << prezime << "  " << username << "  " << password << "  " << pansion << "  " << usluge << "  " << id << "  " << sobica << "  " << cijena << "  " << prezerv << "  " << krezerv <<"\n";
    gostFile.close();
    reserved = 1;
    sobaFile << "" << sobica << "  " << reserved << "\n";
    }
    sobaFile.close();
}
/***********PROVJERA ZAUZETOSTI SOBE**********/
int Soba::provjera(int usob)
{
int greska = 0;
fstream sobaFile;
sobaFile.open("Sobe.txt", ios::in);
while(!sobaFile.eof())
{
sobaFile >> sobica >> reserved;
if(sobica == usob)
{
greska = 1;
break;
}
}

sobaFile.close();
return(greska);
}
/***********LISTA SVIH SOBA**********/
void Soba::sobelist()
{
    system("CLS");
    fstream sobaFile;
    sobaFile.open("Sobe.txt", ios::in);
    if (!sobaFile)
    {
        cout << "\nFajl nije otvoren jer je prazan!";
        sobaFile.close();
    }
    else
    {
        sobaFile >> sobica >> reserved;
        while (!sobaFile.eof())
        {
            cout << "\n*****Soba info*****";
            cout << "\nBroj sobe: " << sobica;
            cout << "\nRezervisana: " << reserved;
            sobaFile >> sobica >> reserved;
        }
    }
    sobaFile.close();
}
/***********DELETE GOST**********/
void Soba::sbrisanje()
{
    system("CLS");
    fstream file, file1;
    int usoID;
    file.open("Sobe.txt", ios::in);
    if (!file)
    {
        cout << "\nFajl nije otvoren jer je prazan!"<<endl;
        file.close();
    }
    else
    {
        cout << "\nUnesi broj sobe: ";
        cin >> usoID;
        file1.open("recordss.txt", ios::app | ios::out);
        file >> sobica >> reserved;
        while (!file.eof())
        {
            if (usoID != sobica)
            {
                file1 << "" << sobica << "  " << reserved << "\n";
            }
            else
            {
                cout << "\nSoba uspjesno izbrisana!";
            }
            file >> sobica >> reserved;
        }
        file1.close();
        file.close();
        remove("Sobe.txt");
        rename("recordss.txt", "Sobe.txt");
    }
}
#endif // SOBE_H_INCLUDED
