// kms.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;

struct Kot
{
	int iKolumna;
	int iWiersz;
	int iStan;
	int iSer;
};

struct Mysz
{
	int iKolumna;
	int iWiersz;
	int iStan;
};

struct Ser
{
	int iKolumna;
	int iWiersz;
	int iStan;
};

int **StworzPlansze(int wymiar)
{
	// tablica na wskazniki
	int ** tablica = new int *[wymiar];

	// generowanie poszczegolnych wymiarów
	for (int i = 0; i<wymiar; i++)
	{
		tablica[i] = new int[wymiar];
	}

	//wpisanie 0 do kazdej komorki
	for (int i = 0; i<wymiar; i++)
	{
		for (int j = 0; j<wymiar; j++)
		{
			tablica[i][j] = 0;
		}
	}

	return tablica;
}

void WyswietlPlansze(int **tablica, int wymiar)
{
	for (int i = 0; i<wymiar; i++)
	{
		for (int j = 0; j<wymiar; j++)
		{
			cout << tablica[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

struct Kot* DodajKota(int **tablica, int wymiar)
{
	struct Kot*  nowykot = new Kot;
	do
	{
		nowykot->iKolumna = rand() % (wymiar - 1);
		nowykot->iWiersz = rand() % (wymiar - 1);
		nowykot->iStan = -1;
		nowykot->iSer = 0;
	} while (tablica[nowykot->iKolumna][nowykot->iWiersz] != 0);
	tablica[nowykot->iKolumna][nowykot->iWiersz] = 3;

	return nowykot;
}

struct Mysz* DodajMysz(int **tablica, int wymiar)
{
	struct Mysz*  nowamysz = new Mysz;
	do
	{
		nowamysz->iKolumna = rand() % (wymiar - 1);
		nowamysz->iWiersz = rand() % (wymiar - 1);
		nowamysz->iStan = -1;
	} while (tablica[nowamysz->iKolumna][nowamysz->iWiersz] != 0);
	tablica[nowamysz->iKolumna][nowamysz->iWiersz] = 2;

	return nowamysz;
}

struct Ser* DodajSer(int **tablica, int wymiar)
{
	struct Ser*  nowyser = new Ser;
	do
	{
		nowyser->iKolumna = rand() % (wymiar - 1);
		nowyser->iWiersz = rand() % (wymiar - 1);
		nowyser->iStan = -1;
	} while (tablica[nowyser->iKolumna][nowyser->iWiersz] != 0);
	tablica[nowyser->iKolumna][nowyser->iWiersz] = 1;


	return nowyser;
}

int RuchKot(struct Kot* akot, int **tablica, int wymiar)
{
	int iNowaKolumna = akot->iKolumna;
	int iNowyWiersz = akot->iWiersz;
	if (akot->iStan == -1)
	{
		int iLosowana = rand() % 7;

		if (iLosowana == 0)
		{
			iNowaKolumna--;
			iNowyWiersz--;
		}
		else if (iLosowana == 1)
		{
			iNowyWiersz--;
		}
		else if (iLosowana == 2)
		{
			iNowaKolumna++;
			iNowyWiersz--;
		}
		else if (iLosowana == 3)
		{
			iNowaKolumna--;
		}
		else if (iLosowana == 4)
		{
			iNowaKolumna++;
		}
		else if (iLosowana == 5)
		{
			iNowaKolumna--;
			iNowyWiersz++;
		}
		else if (iLosowana == 6)
		{
			iNowyWiersz++;
		}
		else if (iLosowana == 7)
		{
			iNowaKolumna++;
			iNowyWiersz++;
		}

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			int tempser = akot->iSer;
			akot->iSer = tablica[iNowaKolumna][iNowyWiersz];
			if (tempser == 1)
			{
				tablica[akot->iKolumna][akot->iWiersz] = tempser;
			}
			else
			{
				tablica[akot->iKolumna][akot->iWiersz] = 0;
			}
			

			tablica[iNowaKolumna][iNowyWiersz] = 3;
			akot->iKolumna = iNowaKolumna;
			akot->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	//detekcja kota
	else if (akot->iStan == 0)
	{
		iNowaKolumna--;
		iNowyWiersz--;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			int tempser = akot->iSer;
			akot->iSer = tablica[iNowaKolumna][iNowyWiersz];
			if (tempser == 1)
			{
				tablica[akot->iKolumna][akot->iWiersz] = tempser;
			}
			else
			{
				tablica[akot->iKolumna][akot->iWiersz] = 0;
			}
			

			tablica[iNowaKolumna][iNowyWiersz] = 3;
			akot->iKolumna = iNowaKolumna;
			akot->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (akot->iStan == 1)
	{
		iNowyWiersz--;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			int tempser = akot->iSer;
			akot->iSer = tablica[iNowaKolumna][iNowyWiersz];
			if (tempser == 1)
			{
				tablica[akot->iKolumna][akot->iWiersz] = tempser;
			}
			else
			{
				tablica[akot->iKolumna][akot->iWiersz] = 0;
			}
			

			tablica[iNowaKolumna][iNowyWiersz] = 3;
			akot->iKolumna = iNowaKolumna;
			akot->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (akot->iStan == 2)
	{
		iNowaKolumna++;
		iNowyWiersz--;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			int tempser = akot->iSer;
			akot->iSer = tablica[iNowaKolumna][iNowyWiersz];
			if (tempser == 1)
			{
				tablica[akot->iKolumna][akot->iWiersz] = tempser;
			}
			else
			{
				tablica[akot->iKolumna][akot->iWiersz] = 0;
			}
			

			tablica[iNowaKolumna][iNowyWiersz] = 3;
			akot->iKolumna = iNowaKolumna;
			akot->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (akot->iStan == 3)
	{
		iNowaKolumna--;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			int tempser = akot->iSer;
			akot->iSer = tablica[iNowaKolumna][iNowyWiersz];
			if (tempser == 1)
			{
				tablica[akot->iKolumna][akot->iWiersz] = tempser;
			}
			else
			{
				tablica[akot->iKolumna][akot->iWiersz] = 0;
			}
			

			tablica[iNowaKolumna][iNowyWiersz] = 3;
			akot->iKolumna = iNowaKolumna;
			akot->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (akot->iStan == 4)
	{
		iNowaKolumna++;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			int tempser = akot->iSer;
			akot->iSer = tablica[iNowaKolumna][iNowyWiersz];
			if (tempser == 1)
			{
				tablica[akot->iKolumna][akot->iWiersz] = tempser;
			}
			else
			{
				tablica[akot->iKolumna][akot->iWiersz] = 0;
			}
			akot->iSer = tablica[akot->iKolumna][akot->iWiersz];

			tablica[iNowaKolumna][iNowyWiersz] = 3;
			akot->iKolumna = iNowaKolumna;
			akot->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (akot->iStan == 5)
	{
		iNowaKolumna--;
		iNowyWiersz++;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			int tempser = akot->iSer;
			akot->iSer = tablica[iNowaKolumna][iNowyWiersz];
			if (tempser == 1)
			{
				tablica[akot->iKolumna][akot->iWiersz] = tempser;
			}
			else
			{
				tablica[akot->iKolumna][akot->iWiersz] = 0;
			}
			akot->iSer = tablica[akot->iKolumna][akot->iWiersz];

			tablica[iNowaKolumna][iNowyWiersz] = 3;
			akot->iKolumna = iNowaKolumna;
			akot->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (akot->iStan == 6)
	{
		iNowyWiersz++;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			int tempser = akot->iSer;
			akot->iSer = tablica[iNowaKolumna][iNowyWiersz];
			if (tempser == 1)
			{
				tablica[akot->iKolumna][akot->iWiersz] = tempser;
			}
			else
			{
				tablica[akot->iKolumna][akot->iWiersz] = 0;
			}
			

			tablica[iNowaKolumna][iNowyWiersz] = 3;
			akot->iKolumna = iNowaKolumna;
			akot->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (akot->iStan == 7)
	{
		iNowaKolumna++;
		iNowyWiersz++;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			int tempser = akot->iSer;
			akot->iSer = tablica[iNowaKolumna][iNowyWiersz];
			if (tempser == 1)
			{
				tablica[akot->iKolumna][akot->iWiersz] = tempser;
			}
			else
			{
				tablica[akot->iKolumna][akot->iWiersz] = 0;
			}
			

			tablica[iNowaKolumna][iNowyWiersz] = 3;
			akot->iKolumna = iNowaKolumna;
			akot->iWiersz = iNowyWiersz;
		}
		return 1;
	}
}

int RuchMysz(struct Mysz* amysz, int **tablica, int wymiar)
{
	int iNowaKolumna = amysz->iKolumna;
	int iNowyWiersz = amysz->iWiersz;

	if (amysz->iStan == -1)
	{
		cout << "Mysz bez ucieczki" << endl;
		int iLosowana = rand() % 7;

		if (iLosowana == 0)
		{
			iNowaKolumna--;
			iNowyWiersz--;
		}
		else if (iLosowana == 1)
		{
			iNowyWiersz--;
		}
		else if (iLosowana == 2)
		{
			iNowaKolumna++;
			iNowyWiersz--;
		}
		else if (iLosowana == 3)
		{
			iNowaKolumna--;
		}
		else if (iLosowana == 4)
		{
			iNowaKolumna++;
		}
		else if (iLosowana == 5)
		{
			iNowaKolumna--;
			iNowyWiersz++;
		}
		else if (iLosowana == 6)
		{
			iNowyWiersz++;
		}
		else if (iLosowana == 7)
		{
			iNowaKolumna++;
			iNowyWiersz++;
		}

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			tablica[amysz->iKolumna][amysz->iWiersz] = 0;
			tablica[iNowaKolumna][iNowyWiersz] = 2;
			amysz->iKolumna = iNowaKolumna;
			amysz->iWiersz = iNowyWiersz;
			cout << "Mysz nowe wspolrzedne: " << iNowaKolumna << ":" << iNowyWiersz << endl;
		}
		return 1;
	}
	//detekcja myszy
	else if (amysz->iStan == 7)
	{
		iNowaKolumna--;
		iNowyWiersz--;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			tablica[amysz->iKolumna][amysz->iWiersz] = 0;
			tablica[iNowaKolumna][iNowyWiersz] = 2;
			amysz->iKolumna = iNowaKolumna;
			amysz->iWiersz = iNowyWiersz;
			
		}
		return 1;
	}
	else if (amysz->iStan == 6)
	{
		iNowyWiersz--;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			tablica[amysz->iKolumna][amysz->iWiersz] = 0;
			tablica[iNowaKolumna][iNowyWiersz] = 2;
			amysz->iKolumna = iNowaKolumna;
			amysz->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (amysz->iStan == 5)
	{
		iNowaKolumna++;
		iNowyWiersz--;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			tablica[amysz->iKolumna][amysz->iWiersz] = 0;
			tablica[iNowaKolumna][iNowyWiersz] = 2;
			amysz->iKolumna = iNowaKolumna;
			amysz->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (amysz->iStan == 4)
	{
		iNowaKolumna--;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			tablica[amysz->iKolumna][amysz->iWiersz] = 0;
			tablica[iNowaKolumna][iNowyWiersz] = 2;
			amysz->iKolumna = iNowaKolumna;
			amysz->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (amysz->iStan == 3)
	{
		iNowaKolumna++;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			tablica[amysz->iKolumna][amysz->iWiersz] = 0;
			tablica[iNowaKolumna][iNowyWiersz] = 2;
			amysz->iKolumna = iNowaKolumna;
			amysz->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (amysz->iStan == 2)
	{
		iNowaKolumna--;
		iNowyWiersz++;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			tablica[amysz->iKolumna][amysz->iWiersz] = 0;
			tablica[iNowaKolumna][iNowyWiersz] = 2;
			amysz->iKolumna = iNowaKolumna;
			amysz->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (amysz->iStan == 1)
	{
		iNowyWiersz++;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			tablica[amysz->iKolumna][amysz->iWiersz] = 0;
			tablica[iNowaKolumna][iNowyWiersz] = 2;
			amysz->iKolumna = iNowaKolumna;
			amysz->iWiersz = iNowyWiersz;
		}
		return 1;
	}
	else if (amysz->iStan == 0)
	{
		iNowaKolumna++;
		iNowyWiersz++;

		//jesli nie wyjdzie poza pole
		if (iNowaKolumna != -1 && iNowaKolumna != wymiar && iNowyWiersz != -1 && iNowyWiersz != wymiar)
		{
			tablica[amysz->iKolumna][amysz->iWiersz] = 0;
			tablica[iNowaKolumna][iNowyWiersz] = 2;
			amysz->iKolumna = iNowaKolumna;
			amysz->iWiersz = iNowyWiersz;
		}
		return 1;
	}
}

int DetekcjaKot(struct Kot* akot, int **tablica, int wymiar)
{
	if (akot->iKolumna > 0 && akot->iWiersz > 0 && tablica[akot->iKolumna - 1][akot->iWiersz - 1] == 2)
	{
		akot->iStan = 0;
	}
	else if (akot->iKolumna > 0 && akot->iWiersz > 0 && tablica[akot->iKolumna][akot->iWiersz - 1] == 2)
	{
		akot->iStan = 1;
	}
	else if (akot->iKolumna < wymiar - 1 && akot->iWiersz > 0 && tablica[akot->iKolumna + 1][akot->iWiersz - 1] == 2)
	{
		akot->iStan = 2;
	}
	else if (akot->iKolumna > 0 && tablica[akot->iKolumna - 1][akot->iWiersz] == 2)
	{
		akot->iStan = 3;
	}
	else if (akot->iKolumna < wymiar - 1 && tablica[akot->iKolumna + 1][akot->iWiersz] == 2)
	{
		akot->iStan = 4;
	}
	else if (akot->iKolumna > 0 && akot->iWiersz < wymiar - 1 && tablica[akot->iKolumna - 1][akot->iWiersz + 1] == 2)
	{
		akot->iStan = 5;
	}
	else if (akot->iWiersz < wymiar - 1 && tablica[akot->iKolumna][akot->iWiersz + 1] == 2)
	{
		akot->iStan = 6;
	}
	else if (akot->iKolumna < wymiar - 1 && akot->iWiersz < wymiar - 1 && tablica[akot->iKolumna + 1][akot->iWiersz + 1] == 2)
	{
		akot->iStan = 7;
	}
	cout << "Detekcja kot : " << akot->iStan << endl;

	return 1;
}

int DetekcjaMysz(struct Mysz* amysz, int **tablica, int wymiar)
{
	
	if (amysz->iKolumna > 0 && amysz->iWiersz > 0 && tablica[amysz->iKolumna - 1][amysz->iWiersz - 1] == 3)
	{
		amysz->iStan = 0;
	}
	else if (amysz->iKolumna > 0 && amysz->iWiersz > 0 && tablica[amysz->iKolumna][amysz->iWiersz - 1] == 3)
	{
		amysz->iStan = 1;
	}
	else if (amysz->iKolumna < wymiar-1 && amysz->iWiersz > 0 && tablica[amysz->iKolumna + 1][amysz->iWiersz - 1] == 3)
	{
		amysz->iStan = 2;
	}
	else if (amysz->iKolumna > 0 && tablica[amysz->iKolumna - 1][amysz->iWiersz] == 3)
	{
		amysz->iStan = 3;
	}
	else if (amysz->iKolumna < wymiar - 1 && tablica[amysz->iKolumna + 1][amysz->iWiersz] == 3)
	{
		amysz->iStan = 4;
	}
	else if (amysz->iKolumna > 0 && amysz->iWiersz < wymiar - 1 && tablica[amysz->iKolumna - 1][amysz->iWiersz + 1] == 3)
	{
		amysz->iStan = 5;
	}
	else if (amysz->iWiersz < wymiar - 1 && tablica[amysz->iKolumna][amysz->iWiersz + 1] == 3)
	{
		amysz->iStan = 6;
	}
	else if (amysz->iKolumna < wymiar-1 && amysz->iWiersz < wymiar - 1 && tablica[amysz->iKolumna + 1][amysz->iWiersz + 1] == 3)
	{
		amysz->iStan = 7;
	}
	cout << "Detekcja mysz : " << amysz->iStan << endl;
	return 1;
}

bool JestMysz(int **tablica, int wymiar)
{
	bool Mysz = false;
	for (int i = 0; i<wymiar; i++)
	{
		for (int j = 0; j<wymiar; j++)
		{
			if (tablica[i][j] == 2)
			{
				Mysz = true;
			}
		}
	}

	return Mysz;
}

int main(int argc, char** argv)
{
	bool test;
	srand(time(NULL));
	int **plansza;
	int rozmiar = 5;

	plansza = StworzPlansze(rozmiar);
	struct Kot* pierwszykot = DodajKota(plansza, rozmiar);
	struct Mysz* pierwszamysz = DodajMysz(plansza, rozmiar);
	struct Ser* pierwszyser = DodajSer(plansza, rozmiar);
	WyswietlPlansze(plansza, rozmiar);

	do
	{
		RuchMysz(pierwszamysz, plansza, rozmiar);
		RuchKot(pierwszykot, plansza, rozmiar);

		WyswietlPlansze(plansza, rozmiar);

		DetekcjaKot(pierwszykot, plansza, rozmiar);
		(pierwszamysz, plansza, rozmiar);

		test = JestMysz(plansza, rozmiar);
		getch();
	} while (test);
	return 0;
}


