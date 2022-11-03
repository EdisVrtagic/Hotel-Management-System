#ifndef GOSTI_H_INCLUDED
#define GOSTI_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

void pocetnilogin();
/***********KLASA GOST**********/
class Gost
{
	private:
    string ime,prezime,username,password,pansion,usluge;
    int id,sobica,cijena,prezerv,krezerv;
/***********PUBLIC FUNKCIJE**********/
public:
void gostform();
void showlist();
void sgost();
void editgost();
void brisanje();
friend class Soba;
/***********GETTERI I SETTERI**********/
/***********GETTER I SETTER ZA IME GOSTA**********/
public:
void setIme(string nIme)
{
nIme = ime;
}
string getIme()
{
return ime;
}
/***********GETTER I SETTER ZA PREZIME GOSTA**********/
void setPrezime(string nPrezime)
{
nPrezime = prezime;
}

string getPrezime()
{
return prezime;
}
/***********GETTER I SETTER ZA USERNAME GOSTA**********/
void setUName(string nUname)
{
nUname = username;
}

string getUName()
{
return username;
}
/***********GETTER I SETTER ZA PASSWORD GOSTA**********/
void setPass(string nPass)
{
nPass = password;
}

string getPass()
{
return password;
}
/***********GETTER I SETTER ZA VRSTU PANSIONA**********/
void setPansion(string nPans)
{
nPans = pansion;
}

string getPansion()
{
return pansion;
}
/***********GETTER I SETTER ZA VRSTU USLUGE**********/
void setUsluga(string nUsluga)
{
nUsluga = usluge;
}

string getUsluga()
{
return usluge;
}
/***********GETTER I SETTER ZA ID GOSTA**********/
void setID(int nID)
{
id = nID;
}

int getID()
{
return id;
}
/***********GETTER I SETTER ZA SOBU GOSTA**********/
void setSobica(int nSoba)
{
sobica = nSoba;
}

int getSobica()
{
return sobica;
}
/***********GETTER I SETTER ZA CIJENU SOBE**********/
void setCijena(int nCijena)
{
cijena = nCijena;
}

int getCijena()
{
return cijena;
}
/***********GETTER I SETTER ZA POCETNI DATUM REZERVACIJE**********/
void setpRezer(int npRezer)
{
prezerv = npRezer;
}

int getpRezer()
{
return prezerv;
}
/***********GETTER I SETTER ZA KRAJNJI DATUM REZERVACIJE**********/
void setkRezer(int nkRezer)
{
krezerv = nkRezer;
}

int getkRezer()
{
return krezerv;
}
/***********KONSTRUKTOR**********/
Gost(string nIme, string nPrezime, string nUname, string nPass, string nPans, string nUsluga, int nID, int nSoba, int nCijena, int npRezer, int nkRezer)
{
ime = nIme;
prezime = nPrezime;
username = nUname;
password = nPass;
pansion = nPans;
usluge = nUsluga;
id = nID;
sobica = nSoba;
cijena = nCijena;
prezerv = npRezer;
krezerv = nkRezer;
}
/***********PRAZAN KONSTRUKTOR**********/
Gost()
{
}
};
/***********GOST LOGIN**********/
void Gost::gostform()
{
    system("CLS");
    fstream file;
    file.open("Gosti.txt", ios::in);
    string gostpass,gostuname;
    cout << "**********GUEST LOGIN**********";
    cout << "\nUnesite username: ";
    cin>>gostuname;
    cout << "\nUnesite password: ";
    cin>>gostpass;
    system("CLS");
    while(file >> ime >> prezime >> username >> password >> pansion >> usluge >> id >> sobica >> cijena >> prezerv >> krezerv)
    {
    if(gostuname == username && gostpass == password)
    {
        while(true)
        {
            int unos;
            cout << "\n**********Welcome Guest**********";
            cout << "\n1.) Pregled profila";
            cout << "\n2.) Log out";
            cout << "\nUnesite vas odabir: ";
            cin>>unos;
            switch(unos)
            {
                case 1:
                system("CLS");
                cout << "\n*****Profil*****";
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
                break;
                case 2:
                system("CLS");
                cout<<"Odjavili ste se!"<<endl;
                pocetnilogin();
                break;
                default:
                cout<<"Pogresan izbor!"<<endl;
                break;
            }
        }
        file.close();
        return;
    }
    }
    cout << "\nNetacan username ili password!" <<endl;
    file.close();
}

#endif // GOSTI_H_INCLUDED
