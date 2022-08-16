#include <iostream>

using namespace std;

enum State{
	WOLNY,
	ZAJETY,
	USUNIETY,
};

unsigned int funkcja_haszujaca(string element)
{
	unsigned int dlugosc = element.length(),suma=0,N=257;
	for(int i=0;i<dlugosc;i++)
	{
//		suma+=element[i];
		suma = N*suma+element[i];

	}
	cout<<"Hash od "<<element<<" to: "<<suma<<endl;
	return suma;
}

class Tablica_Haszujaca{
	public:
		
	int rozmiar;
	string *tablica;
	enum State *stany;
	
	Tablica_Haszujaca(int rozmiar)
	{
		this->rozmiar = rozmiar;
		tablica = new string[rozmiar];
		
		stany = new enum State[rozmiar];
		for(int i=0;i<rozmiar;i++) stany[i] = WOLNY; 
	}
	
	void wstawienie(string element)
	{
		unsigned int index = funkcja_haszujaca(element)%rozmiar;
		while(stany[index] == ZAJETY)
		{
			index++;
			if (index>=rozmiar) index = 0;
		}
		tablica[index] = element;
		stany[index] = ZAJETY;
		cout<<"Wstawiam na: "<<index<<endl;
	}
	
	bool szukanie(string szukana)
	{
		unsigned int index = funkcja_haszujaca(szukana)%rozmiar;
		while(stany[index] != WOLNY)
		{
			if(stany[index] != USUNIETY && tablica[index] == szukana ) 
			{
				cout<<"Znalazlem na pozycji: "<<index<<endl;
				return true;
			}
			index++;
			if (index>=rozmiar) index = 0;
			
		}
		
		return false;	
	}
	
	bool usuwanie(string usuwana)
	{
		unsigned int index = funkcja_haszujaca(usuwana)%rozmiar;
		
		while(stany[index] != WOLNY)
		{
			if(stany[index] != USUNIETY && tablica[index] == usuwana) 
			{
				stany[index] = USUNIETY;
				
				cout<<usuwana<<" zostala usunieta."<<endl;
				return true;
			}
			
			index++;
			if (index>=rozmiar) index = 0;
		}
		
		cout<<"Nieznaleziono."<<endl;
		return false;
	}
	
	
};


int main()
{
	Tablica_Haszujaca koty(20);
	
	koty.wstawienie("Adam");
	koty.wstawienie("Pszemek");
	koty.wstawienie("Pawel");
	koty.wstawienie("Pawel");
	koty.szukanie("Pszemek");
	koty.szukanie("Adam");
	koty.szukanie("Pawel");
	koty.usuwanie("Pawel");
	koty.usuwanie("Pawel");
	koty.usuwanie("Pawel");
	
	return 0;
}
