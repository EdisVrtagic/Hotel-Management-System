#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include "Gosti.h"
#include "Admin.h"
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
/***********FUNKCIJA ZA POCETNI LOGIN**********/
void pocetnilogin()
{
    system("CLS");
    /***********LOGIN MENU**********/
    Gost form;
    Radnik formss;
	int unesi;
	while(true)
	{
	cout << "\n**********HOTEL**********";
    cout << "\n1.) Guest login";
    cout << "\n2.) Radnik login";
    cout << "\n3.) Admin login";
    cout << "\n4.) Exit";
    cout << "\nUnesite vas odabir: ";
	cin>>unesi;
	switch(unesi)
	{
		case 1:
        form.gostform();
        break;
        case 2:
        formss.radnikform();
        break;
        case 3:
        adminform();
        break;
		case 4:
        cout << "\nIzasli ste!" << endl;
        break;
		default:
        cout<<"Pogresan izbor!"<<endl;
        break;
	}
  }
}
main ()
{
    pocetnilogin();
    return 0;
}
