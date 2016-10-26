#include "stdafx.h"
#include "cBullCowGame.h"
#include <map>

#define TMap std::map


cBullCowGame::cBullCowGame()
{
	Reset();
}
//premier formalisme possible c++/unreal
/*cBullCowGame::cBullCowGame(int nEssai, int nMaxEssai)
{
	this->essaiCourant = nEssai;
	this->maxEssai = nMaxEssai;
}*/
//2ème formalisme possible c++/unreal
/*cBullCowGame::cBullCowGame(int nEssai, int nMaxEssai) :essaiCourant(nEssai),maxEssai(nMaxEssai)
{
}*/

cBullCowGame::~cBullCowGame()
{

}

int32 cBullCowGame::getEssaiCourant()const
{
	return this->essaiCourant;
}

int32 cBullCowGame::getMaxEssai()const
{
	//return this->maxEssai;
	TMap<int32, int32> LgMotEssaiMax{ {3,4},{4,7},{5,10},{6,16},{7,20} };
	return LgMotEssaiMax[motCache.length()];

}

void cBullCowGame::setEssaiCourant(int32 nEssai)
{
	this->essaiCourant = nEssai;
}

void cBullCowGame::setMaxEssai(int32 nEssai)
{
	//this->maxEssai = nEssai;
}

void cBullCowGame::Reset()
{
	//constexpr int32 MAX_ESSAI = 8;
	//this->maxEssai = MAX_ESSAI;

	const FString MOTCACHE = "Avion";
	motCache = MOTCACHE;

	this->essaiCourant = 1;

	status = EWordStatus::Wrong_Length;

	gagne = false;
}

bool cBullCowGame::Gagne()const
{
	return gagne;
}

EWordStatus cBullCowGame::testValideMot(FString mot)const
{
	if (!estIsogram(mot)) {//si pas isogram
		return EWordStatus::Not_isogram;
	}
	else if (estMiniscule(mot)) {//si pas minuscule
		return EWordStatus::Not_Lowercase;
	}
	else if (mot.length() != getLongMotCache()) {
		return EWordStatus::Wrong_Length;
	}
	else {
		return EWordStatus::Ok;
	}
}

BullCowCount cBullCowGame::valideEssai(FString mot)
{
	essaiCourant++;

	BullCowCount BullCowCount;

	int32 LChaine = mot.length();

	for (int32 i = 0; i < LChaine; i++) {
		for (int32 j = 0; j < LChaine; j++){
			if (mot[i] == motCache[j]) {
				if (i == j) {
					BullCowCount.bulls++;
				}
				else {
					BullCowCount.cows++;
				}
			}
		}
	}

	if (BullCowCount.bulls == getLongMotCache()) {
		gagne = true;
	}
	else {
		gagne = false;
	}

	return BullCowCount;
}

int32 cBullCowGame::getLongMotCache() const
{
	return motCache.length();
}

int32 cBullCowGame::getEWordStatus() const
{
	return (int)status;

}

bool cBullCowGame::estIsogram(FString mot) const
{
	if (mot.length() <= 1) { return true; }

	TMap<char, bool>lettreMot;

	for (auto lettre : mot) {
		lettre = tolower(lettre);
		if (lettreMot[lettre]) {
			return false;
		}
		else {
			lettreMot[lettre] = true;
		}
	}

	return true;
}

bool cBullCowGame::estMiniscule(FString Mot) const
{
	for (auto lettre : Mot) {
		if (!islower(lettre)) {
			return false;
		}
	}
	return true;
}
