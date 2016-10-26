// ConsoleApplication2.cpp : fichier projet principal.

#include "stdafx.h"
#include <iostream>
#include <string>
#include "cBullCowGame.h"

using namespace std;

using FTEXT = string;
using int32 = int;


void afficheIntro(cBullCowGame);
FTEXT votreMot(cBullCowGame);
void Jouer(cBullCowGame);
bool jouerEncore();
void afficheEtat(cBullCowGame);


int32 main()
{
	cBullCowGame joueur;
	
	do {
		afficheIntro(joueur);
		Jouer(joueur);
	} while (jouerEncore());


	system("pause");

	return 0;
}

void afficheIntro(cBullCowGame joueur) {

	//constante local au main
	constexpr int32 WORLDLENGTH = 9;

	cout << "bienvenu dans le jeu du BULL and cow game" << endl;
	cout << "Nombre de lettres du mot caché : " << joueur.getLongMotCache() << endl;
	cout << "Nombre de possibilité" << joueur.getMaxEssai() << endl;
	cout << "Status :" << joueur.getEWordStatus() << endl;


}

FTEXT votreMot(cBullCowGame joueur) {

	
	EWordStatus status = EWordStatus::Ok;
	do {
		int EssaiCourant = joueur.getEssaiCourant();
		FTEXT mot = "";
		cout << "Essai : " << EssaiCourant << endl;

		cout << "sasir votre mot" << endl;
		getline(cin, mot);

		status = joueur.testValideMot(mot);
		switch (status)
			{
				case EWordStatus::Wrong_Length: cout << "Entrez un mot de max : " << joueur.getLongMotCache() << " lettres" << endl; break;
				case EWordStatus::Not_isogram: cout << "Entrez un mot sans lettre repétés : " << endl; break;
				case EWordStatus::Not_Lowercase: cout << "Entrez un mot en miniscule : " << endl; break;
				default : return mot;break;
		}
	} while (status != EWordStatus::Ok);

}

void Jouer(cBullCowGame joueur) {

	
	joueur.Reset();
	int32 MaxEssai = joueur.getMaxEssai();

	//for (int32 i = 1; i <= MaxEssai; i++) {
	while (!joueur.Gagne() && joueur.getEssaiCourant()<=MaxEssai){
		FTEXT mot = votreMot(joueur);
		EWordStatus status = joueur.testValideMot(mot);

		BullCowCount BullCowCount = joueur.valideEssai(mot);
		cout << "votre mot est : " << mot << endl;
		cout << "Bulls : " << BullCowCount.bulls << endl;
		cout << "Cows : " << BullCowCount.cows << endl;
		cout << endl;
	}
}

bool jouerEncore() {
	cout << "voulez vous rejouer?" << endl;
	FTEXT Reponse = "";
	getline(cin, Reponse);
	return(Reponse[0] == 'o' || Reponse[0] == 'O');
}

void afficheEtat(cBullCowGame joueur) {
	if (joueur.Gagne()) {
		cout << "Gagné" << endl;
	}
	else {
		cout<<"Perdu" << endl;
	}
}