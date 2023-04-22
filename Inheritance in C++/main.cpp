#include <iostream>
#include <string>
#include <list>
using namespace std;

/*                               Inheritance of OOP(Object Orianted Programming)                          */

class VideoGames {

protected:
	string NameOfTheGame;
	int ReleaseDate;
	string CompanyName;
	long int Cost;  // The amount of money in USD Your company invested
public:

	VideoGames(string NameOftheGame = "", int ReleaseDate = 0, string CompanyName = "", long int Cost = 0)
	{
		this->NameOfTheGame = NameOftheGame;
		this->ReleaseDate = ReleaseDate;
		this->CompanyName = CompanyName;
		this->Cost = Cost;
	}

	void Anniversary()
	{
		cout << 2023 - ReleaseDate << " th Anniversary." << endl;
	}

	void profit(long int Gained)
	{
		if (Gained - Cost < 0) {
			cout << "You didn't make profit from your game!!" << endl;
			cout << "Your loss is " << Gained - Cost << " USD." << endl;
		}
		else {
			cout << "Your game has made " << Gained - Cost << " USD." << endl;
		}
	}

	virtual void ShowInformation()
	{
		cout << "Name:  " << NameOfTheGame << endl;
		cout << "Release Date:  " << ReleaseDate << endl;
		cout << "Company Name:  " << CompanyName << endl;
		cout << "Cost:  " << Cost << endl;
	}
    
	~VideoGames()
	{
		cout << "Destructor called to avoid memory leak(VideoGames)" << endl;
	}
};


class ConsolGames: public VideoGames {

private:

	string ConsolType;  // Is it PS, XBOX, Nintendo Switch...
	long int NumberOfCopiedSold;

public:
   
	ConsolGames(string NameOftheGame = "", int ReleaseDate = 0, string CompanyName = "", long int Cost = 0, string
		ConsolType = "", long int NumberOfCopiedSold = 0)
		:VideoGames(NameOftheGame, ReleaseDate, CompanyName, Cost)
	{
		this->ConsolType = ConsolType;
		this->NumberOfCopiedSold = NumberOfCopiedSold;
	}

	void isExclusive()
	{
		// Playstation Studios Generaly release their videogames to pc platform after min 4 years
		// XBOX games generaly comes to PC platforms
		if (ConsolType == "PS4" || ConsolType == "PS5")
		{
			if (2023 - ReleaseDate > 3)
			{
				cout << "No " << NameOfTheGame << " is also available in PC platform" << endl;
			}
			else {
				cout << "Yes " << NameOfTheGame << " is only available in " << ConsolType << " Platfomrs"<<endl;
			}
		}
		else {
			cout << "No " << NameOfTheGame << " is also available in both " << ConsolType << " and PC platforms." << endl;
		}
	}

	void ShowInformation()
	{
		cout << "Name:  " << NameOfTheGame << endl;
		cout << "Release Date:  " << ReleaseDate << endl;
		cout << "Company Name:  " << CompanyName << endl;
		cout << "Cost:  " << Cost << endl;
		cout << "Consol Type:  " << ConsolType << endl;
		cout << "Number of Copied Sold:  " << NumberOfCopiedSold << endl;
	}

	~ConsolGames()
	{
		cout << "Destructor called to avoid memory leak(Consol Games)" << endl;
	}
};


class IndieGames : public VideoGames {

private:

	string GameType; // Is it a platform , Action RPG...
	string PublisherName;  // Most of the indie games requires publishers from the outside
	list<string>* DigitalPlatforms;    // Steam, EpicGames, Origin, GamePass...


};


int main()
{
	VideoGames* MyConsolGame{ NULL };

	MyConsolGame = new ConsolGames("The Last Of Us", 2017, "Naughty Dog", 120000000, "PS4", 30000000); 

	MyConsolGame->ShowInformation();
	MyConsolGame->Anniversary();
	MyConsolGame->profit(200000000);



	delete MyConsolGame;

	cout << endl;
	return 0;
}