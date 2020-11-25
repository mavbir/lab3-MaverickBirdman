#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
	int unsigned static liczbaZaglowcow=0;
	int unsigned static licznikPrzetransportowanegoSumarycznieTowaru;
	//#1
	Stocznia s{};
	Statek* s1 = s();
	//#dod
	Zaglowiec* za = dynamic_cast<Zaglowiec*>(s1);
	if (za != nullptr)
	{
		liczbaZaglowcow = ++liczbaZaglowcow;
	}
	//#2 + #3
	licznikPrzetransportowanegoSumarycznieTowaru = licznikPrzetransportowanegoSumarycznieTowaru + s1->transportuj();
	//#4
	delete s1;
	//#5
	if (towar == 0)
	{
		cout << "Brak towaru do transportu" << endl;
	}
	else
	{
		while (licznikPrzetransportowanegoSumarycznieTowaru < towar)
		{
			//#1
			Stocznia s{};
			Statek* s1 = s();
			//#2 + #3
			licznikPrzetransportowanegoSumarycznieTowaru = licznikPrzetransportowanegoSumarycznieTowaru + s1->transportuj();
			//#4
			delete s1;
		}
	}


	return liczbaZaglowcow;
    
    
    
    //return 0;
}
