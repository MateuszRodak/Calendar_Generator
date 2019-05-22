#include "pch.h"
#include <iostream>
#include <string.h>
#include <string>
#include <linguist>

using namespace std;

int main()
{

	int miesiac,rok,dzien;
	int wskazany_miesiac;
	long przesuniecie_dni = 0;
	int dodane_lata = 0;
	int c = 0;
	int p = 1;
	int reszta = 0;
	int dni = 0;
	int ilosc_dni = 0;
	int poczatek_tygodnia = 0;
	int dni_tygodnia = 0;
	int liczba = 1;
	int numer = 0;
	int numeracja,podany_rok;
	string DANY_MIESIAC= " ";

	cout << "podaj numer miesiaca:" << endl;
	cin >> miesiac;

	cout << "podaj rok" << endl;
	cin >> rok;

	//.zamiana miesiêcy na lata+miesi¹ce gdy wpiszesz 13 misiêcy bedzie to styczeñ roku nastepnego
	if (miesiac > 12)
	{
		do {
			rok = rok + 1;
			miesiac = miesiac - 12;
			dodane_lata = dodane_lata + 1;
		} while (miesiac > 12);
	}
	podany_rok = rok;
	//. dostosowanie nazw miesiąca
	switch (miesiac) {
	case 1: DANY_MIESIAC = "STYCZEN";
		break;
	case 2: DANY_MIESIAC = "LUTY";
		break;
	case 3: DANY_MIESIAC = "MARZEC";
		break;
	case 4: DANY_MIESIAC = "KWIECIEN";
		break;
	case 5: DANY_MIESIAC = "MAJ";
		break;
	case 6: DANY_MIESIAC = "CZERWIEC";
		break;
	case 7: DANY_MIESIAC = "LIPIEC";
		break;
	case 8: DANY_MIESIAC = "SIERPIEN";
		break;
	case 9: DANY_MIESIAC = "WRZESIEN";
		break;
	case 10: DANY_MIESIAC = "PAZDZIERNIK";
		break;
	case 11: DANY_MIESIAC = "LISTOPAD";
		break;
	case 12: DANY_MIESIAC = "GRUDZIEN";
		break;
	default: DANY_MIESIAC = "error#404 ";
		break;
	}
	if (dodane_lata > 0)
	{
		cout << "liczba dodanych lat ze wzgledu na liczbe miesiecy: " << dodane_lata << endl;
		cout << "PODANE DANE: rok:" << rok << "  miesiac:" << miesiac << " (" << DANY_MIESIAC << ")" << endl;
	}
	//.zamiana roku na przedzia³ 2001-2028
	if (rok < 2001)
	{
		do {
			rok = rok + 28;
		} while (rok < 2001);
	}
	if (rok > 2028)
	{
		do {
			rok = rok - 28;
		} while (rok > 2028);
	}
	//.przerabianie przesuniêtego roku na przesuniêty miesi¹c wzglêdem stycznia 2001
	rok = rok - 2001;
	wskazany_miesiac = (rok * 12 + miesiac - 1);
	//.ka¿de 4 lata maj¹ 1461 dni tak¿e mo¿na sobie uproœciæ: 2009= 4lata+4lata+reszta
	if (wskazany_miesiac > 48)
	{
		do {
			wskazany_miesiac = wskazany_miesiac - 48;
			przesuniecie_dni = przesuniecie_dni + 1461;
		} while (wskazany_miesiac > 48);
	}
	//.zamiana tej reszty z miesiêcy na dnie
	for (wskazany_miesiac; wskazany_miesiac > 0; wskazany_miesiac--)
	{
		reszta++;
		++c;
		// tu by³ b³¹d bo p ma rosn¹c co rok a nie co miesi¹c xD
		if (c == 13)
		{
			p++;
			c = 1;
		}
		if (p == 4)p = 0;

		if (c == 1 || c == 3 || c == 5 || c == 7 || c == 8 || c == 10 || c == 12)
		{
			przesuniecie_dni = przesuniecie_dni + 31;
		}
		if (c == 4 || c == 6 || c == 9 || c == 11)
		{
			przesuniecie_dni = przesuniecie_dni + 30;
		}
		if ((c == 2) & (p == 0))
		{
			przesuniecie_dni = przesuniecie_dni + 29;
		}
		if ((c == 2) & (p != 0))
		{
			przesuniecie_dni = przesuniecie_dni + 28;
		}
	}
	//  cout << endl << "przesuniecie roku:" << rok << endl <<
	//  "wskazany_miesiac:" << wskazany_miesiac << endl <<
	//  "przesunieto o miesiecy:" << reszta << endl <<
	//  "przesuniecie_dni:" << przesuniecie_dni << endl;

//.modulo z przesuniêtych dni, reszta to przesuniêcie, 1 styczeñ 2001 roku to Poniedzia³ek +(7*dowolne'k') daje poniedzia³ek
	dzien = przesuniecie_dni % 7;
	cout << endl << "pierwszy dzien miesiaca to:  ";
	switch (dzien) {
	case 0: cout << "poniedzialek" << endl;
		break;
	case 1: cout << "wtorek" << endl;
		break;
	case 2: cout << "sroda" << endl;
		break;
	case 3: cout << "czwartek" << endl;
		break;
	case 4: cout << "piatek" << endl;
		break;
	case 5: cout << "sobota" << endl;
		break;
	case 6: cout << "niedizela" << endl;
		break;
	}
	//.wyliczanie iloœci dni nastêpnego miesi¹ca
	c++;
	if (c == 13) c = 1;

	if (c == 1 || c == 3 || c == 5 || c == 7 || c == 8 || c == 10 || c == 12)
	{
		ilosc_dni = 31;
	}
	if (c == 4 || c == 6 || c == 9 || c == 11)
	{
		ilosc_dni = 30;
	}
	if ((c == 2) && (p == 0))
	{
		ilosc_dni = 29;
	}
	if ((c == 2) && (p != 0))
	{
		ilosc_dni = 28;
	}
	//.chyba wiadome pytania, podawanie i tytu³ tabeli
			//cout << "c jest rowne:" << c << endl
	cout << "wybrany miesiac to: " << DANY_MIESIAC << ", ktory ma: " << ilosc_dni << "dni" << endl;
	cout << endl << "kalendarz powinien zaczynac sie od jakiego dnia tygodnia?" << endl << "1-Pon, 2-Wt, 3-Sr, 4-Czw, 5-Pt, 6-Sob, 7-Nd" << endl;
	cin >> poczatek_tygodnia;
	cout << endl << "(1)-format '0X' |czy| (2)- format 'X'?" << endl;
	cin >> dni;
	cout << endl << "(1)- bez numeracji tygodni |czy| (2)- z numeracja tygodni ?" << endl;
	cin >> numeracja;
	//.WYŚWIETLANIE, tytuły tabelki
	cout << endl << endl << "          " << DANY_MIESIAC << ": " << podany_rok << endl;
	cout << "------------------------------------" << endl;
	switch (poczatek_tygodnia) {
	case 1: cout << "| Pn | Wt | Sr | Cz | Pt | Sb | Nd |" << endl;
		break;
	case 2: cout << "| Wt | Sr | Cz | Pt | Sb | Nd | Pn |" << endl;
		break;
	case 3: cout << "| Sr | Cz | Pt | Sb | Nd | Pn | Wt |" << endl;
		break;
	case 4: cout << "| Cz | Pt | Sb | Nd | Pn | Wt | Sr |" << endl;
		break;
	case 5: cout << "| Pt | Sb | Nd | Pn | Wt | Sr | Cz |" << endl;
		break;
	case 6: cout << "| Sb | Nd | Pn | Wt | Sr | Cz | Pt |" << endl;
		break;
	case 7: cout << "| Nd | Pn | Wt | Sr | Cz | Pt | Sb |" << endl;
		break;
	}
	cout << "------------------------------------" << endl;
	//.ustawianie iloœci pustych kratek przed dniem pierwszym
	for (int b = 1; dzien != (poczatek_tygodnia - 1); b++)
	{
		cout << "|    ";
		dni_tygodnia = dni_tygodnia + 1;
		dzien = dzien - 1;
		if (dzien == -1)
		{
			dzien = 6;
		}
	}
	//.wstawianie dni do tabelki
	for (int liczba = 1; liczba < (ilosc_dni + 1); liczba++)
	{

		if (dni_tygodnia < 7 & liczba < 10 & dni == 1)

		{
			cout << "| 0" << liczba << " ";
			dni_tygodnia = dni_tygodnia + 1;
		}

		if (dni_tygodnia < 7 & liczba < 10 & dni == 2)
		{
			cout << "|  " << liczba << " ";
			dni_tygodnia = dni_tygodnia + 1;
		}
		if (dni_tygodnia < 7 & liczba >= 10)

		{
			cout << "| " << liczba << " ";
			dni_tygodnia = dni_tygodnia + 1;
		}

		//.Przejœcie do nowego wiersza
		if (dni_tygodnia == 7)
		{
			numer++;
			if (numeracja == 1)
				cout << "|" << endl;
			if (numeracja == 2)
				cout << "|" << " " << numer << endl;
			cout << "------------------------------------" << endl;
			dni_tygodnia = 0;
		}
	}
	//.Uzupe³nienie tabeli pustymi miejscami oraz uzupe³nienie brakuj¹cych kresek
	for (int b = 1; (dni_tygodnia < 7 & dni_tygodnia>0); b++)
	{
		cout << "|    ";
		dni_tygodnia = dni_tygodnia + 1;
	}
	//.gdy tabela jest ca³a nie uzupe³niaj kresek bo ju¿ s¹
	if (dni_tygodnia == 7 || dni_tygodnia == 1)
	{
		numer++;
		if (numeracja == 1)
			cout << "|" << endl;
		if (numeracja == 2)
			cout << "|" << " " << numer << endl;
		cout << "------------------------------------" << endl;
	}
	return 0;
}
