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

	virtual void Anniversary() = 0;

	virtual void profit(long int Gained) = 0;

	virtual void ShowInformation() = 0;

    virtual ~VideoGames()
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
		cout << "Name:  " << this->NameOfTheGame << endl;
		cout << "Release Date:  " << this->ReleaseDate << endl;
		cout << "Company Name:  " << this->CompanyName << endl;
		cout << "Cost:  " << this->Cost << endl;
		cout << "Consol Type:  " << ConsolType << endl;
		cout << "Number of Copied Sold:  " << NumberOfCopiedSold << endl;
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

	virtual ~ConsolGames()
	{
		cout << "Destructor called to avoid memory leak(ConsolGames)" << endl;
	}
};


class IndieGames : public VideoGames {

private:

	string GameType; // Is it a platform , Action RPG...
	string PublisherName;  // Most of the indie games requires publishers from the outside
	list<string>* DigitalPlatforms;    // Steam, EpicGames, Origin, GamePass...

public:

	IndieGames(string NameOftheGame = "", int ReleaseDate = 0, string CompanyName = "", long int Cost = 0,
		string GameType = "", string PublisherName = "")
		:VideoGames(NameOftheGame, ReleaseDate, CompanyName, Cost), DigitalPlatforms{ NULL }
	{
		this->GameType = GameType;
		this->PublisherName = PublisherName;
		DigitalPlatforms = new list<string>;
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

	void InputPlatforms()
	{
		size_t n{};
		string PlatformName;

		cout << "Please enter how many platforms your game have: ";
		cin >> n;
		cin.ignore();
		cout << "Please enter Platform Name where your game will be released." << endl;
		
		for (size_t i = 0; i < n; ++i)
		{
			getline(cin, PlatformName);
			DigitalPlatforms->push_back(PlatformName);
		}

		cout << endl<<endl;

	}
	
	void ShowInformation()
	{
		cout << "Name:  " << this->NameOfTheGame << endl;
		cout << "Release Date:  " << this->ReleaseDate << endl;
		cout << "Company Name:  " << this->CompanyName << endl;
		cout << "Cost:  " << this->Cost << endl;
		cout << "Game Type:  " << this->GameType << endl;
		cout << "Publisher Name:  " << this->PublisherName << endl;
		cout << "Digital Platforms:  ";
		
		for (auto& platform : *DigitalPlatforms)
		{
			cout << platform<<", ";
		}
		cout << endl;
	}

	virtual ~IndieGames()
	{
		cout << "Destructor called to avoid memory leak(IndieGames)" << endl;
		delete DigitalPlatforms;
	}
};


int main()
{
	ConsolGames* MyConsolGame{ NULL };

	MyConsolGame = new ConsolGames("The Last Of Us", 2017, "Naughty Dog", 120000000, "PS4", 30000000); 

	MyConsolGame->ShowInformation();
	MyConsolGame->Anniversary();
	MyConsolGame->profit(200000000);
	MyConsolGame->isExclusive();

	delete MyConsolGame;

	cout << endl;

	IndieGames* MyIndieGame{ NULL };

	MyIndieGame = new IndieGames("Mount And Blade Warband", 2012, "Talewords", 800000, "Action RPG", "Paradox Interactive");

	MyIndieGame->InputPlatforms();
	MyIndieGame->ShowInformation();
	MyIndieGame->Anniversary();
	MyIndieGame->profit(12000000);
	
	delete MyIndieGame;


	cout << endl;
	return 0;
}