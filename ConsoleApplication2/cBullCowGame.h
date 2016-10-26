#pragma once

#include <string>

using FString = std::string;
using int32 = int;

typedef struct BullCowCount {
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EWordStatus {

	Ok, 
	Not_isogram,
	Wrong_Length,
	Not_Lowercase
};


class cBullCowGame
{
private:

	//Declaration et initialisation des attributs dans la classe
	int32 essaiCourant;
	int32 maxEssai;
	FString motCache;
	EWordStatus status;
	bool gagne;
	


public:
	cBullCowGame();
	//cBullCowGame(int, int);
	~cBullCowGame();
	//get
	int32 getEssaiCourant()const;
	int32 getMaxEssai()const;
	//set
	void setEssaiCourant(int32 nEssai);
	void setMaxEssai(int32 nEssai);

	void Reset();

	bool Gagne()const;


	//bool testValideMot(FString)const;
	EWordStatus testValideMot(FString)const;

	BullCowCount valideEssai(FString);

	int32 getLongMotCache()const;

	int32 getEWordStatus()const;

	bool estIsogram(FString mot)const;

	bool estMiniscule(FString Mot)const;


};

