/**
 * \file personneMain.cpp
 * \brief Programme principale
 * \version 0.1
 * \date 2014-10-12
 * \author etudiant
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "Adresse.h"
#include "Personne.h"
#include "Date.h"
#include "validationFormat.h"

using namespace std;

int main()
{
	cout << "Bienvenu dans le programme de creation d'une personne." << endl;
	cout << "Veuillez repondre aux question suivante : " << endl;

	//Saisie des informations relatives a une personne
	cout << "Quel est votre NAS : " << endl;

	//Saisie du NAS
	string Nas;
	char buffer[256];
	cin.getline(buffer,255);
	Nas = buffer;
	//Verification de la validite du NAS
	while (not util::validerNas(Nas))
	{
		cout << "Valeur invalide pour le NAS, vous devez entrer un NAS sous le format XXX XXX XXX" << endl;
		cout << "Entrer un nouveau NAS : " << endl;
		cin.getline(buffer,255);
		Nas = buffer;
	}

	//Saisie du prenom
	cout << "Entrer votre prenom" << endl;
	string prenom;
	cin.getline(buffer,255);
	prenom = buffer;
	//Validation du prenom
	while (prenom.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer un prenom" << endl;
		cout << "Entrer un prenom : " << endl;
		cin.getline(buffer,255);
		prenom = buffer;
	}
	//Saisie du nom
	cout << "Entrer votre nom" << endl;
	string nom;
	cin.getline(buffer,255);
	nom = buffer;
	//Validation du nom
	while (nom.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer un nom" << endl;
		cout << "Entrer un nom : " << endl;
		cin.getline(buffer,255);
		nom = buffer;
	}
	//Saisie de la date
	cout << "Entrer votre date de naissance avec le format JJ MM AAAA :" << endl;
	long int jour;
	long int mois;
	long int annee;
	string date;
	cin.getline(buffer,255);
	date = buffer;
	istringstream chainedate(date);
	chainedate >> jour;
	chainedate >> mois;
	chainedate >> annee;
	chainedate.ignore();
	//Validation de la date
	bool valide;
	valide = util::Date::validerDate(jour,mois,annee);
	while (valide == false)
	{
		cout << "Vous avez entre une date invalide." << endl;
		cout << "Entrer une date valide de format JJ MM AAAA :" << endl;
		cin.getline(buffer,255);
		date = buffer;
		istringstream chainedate(date);
		chainedate >> jour;
		chainedate >> mois;
		chainedate >> annee;
		chainedate.ignore();
		valide = util::Date::validerDate(jour,mois,annee);
	}
	//Saisie et validation de l'adresse
	cout << "Entrer votre numero de rue : " << endl;
	string noRue;
	cin.getline(buffer,255);
	noRue = buffer;
	while (noRue.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer un numero de rue" << endl;
		cout << "Entrer votre numero de rue : " << endl;
		cin.getline(buffer,255);
		noRue = buffer;
	}

	cout << "Entrer le nom de votre rue: " << endl;
	string nomRue;
	cin.getline(buffer,255);
	nomRue = buffer;
	while (nomRue.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer un nom de rue" << endl;
		cout << "Entrer votre nom de rue : " << endl;
		cin.getline(buffer,255);
		nomRue = buffer;
	}

	cout << "Entrer le nom de votre ville : " << endl;
	string ville;
	cin.getline(buffer,255);
	ville = buffer;
	while (ville.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer une ville" << endl;
		cout << "Entrer le nom de votre ville : " << endl;
		cin.getline(buffer,255);
		ville = buffer;
	}

	cout << "Entrer votre code postal : " << endl;
	string codePostal;
	cin.getline(buffer,255);
	codePostal = buffer;
	while (codePostal.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer un code postal" << endl;
		cout << "Entrer votre code postal : " << endl;
		cin.getline(buffer,255);
		codePostal = buffer;
	}

	cout << "Entrer le nom de votre province : " << endl;
	string province;
	cin.getline(buffer,255);
	province = buffer;
	while (province.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer une province" << endl;
		cout << "Entrer votre province : " << endl;
		cin.getline(buffer,255);
		province = buffer;
	}

	//Construction de l'objet Adresse,Date et Personne
	util::Adresse adresse(noRue,nomRue,ville,codePostal,province);
	util::Date ddn(jour,mois,annee);
	election::Personne personne(Nas,prenom,nom,ddn,adresse);

	//Affiche de l'objet personne
	cout << "Voici les informations que vous venez d'entrer." << endl;
	cout << personne.reqPersonneFormate();

	//Demander et valider une nouvelle adresse
	cout << "Donner une nouvelle adresse s.v.p" << endl;
	cout << "Entrer votre numero de rue : " << endl;
	cin.getline(buffer,255);
	noRue = buffer;
	while (noRue.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer un numero de rue" << endl;
		cout << "Entrer votre numero de rue : " << endl;
		cin.getline(buffer,255);
		noRue = buffer;
	}

	cout << "Entrer le nom de votre rue: " << endl;
	cin.getline(buffer,255);
	nomRue = buffer;
	while (nomRue.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer un nom de rue" << endl;
		cout << "Entrer votre nom de rue : " << endl;
		cin.getline(buffer,255);
		nomRue = buffer;
	}

	cout << "Entrer le nom de votre ville : " << endl;
	cin.getline(buffer,255);
	ville = buffer;
	while (ville.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer une ville" << endl;
		cout << "Entrer le nom de votre ville : " << endl;
		cin.getline(buffer,255);
		ville = buffer;
	}

	cout << "Entrer votre code postal : " << endl;
	cin.getline(buffer,255);
	codePostal = buffer;
	while (codePostal.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer un code postal" << endl;
		cout << "Entrer votre code postal : " << endl;
		cin.getline(buffer,255);
		codePostal = buffer;
	}

	cout << "Entrer le nom de votre province : " << endl;
	cin.getline(buffer,255);
	province = buffer;
	while (province.empty())
	{
		cout << "Vous avez laisser le champ vide, vous devez entrer une province" << endl;
		cout << "Entrer votre province : " << endl;
		cin.getline(buffer,255);
		province = buffer;
	}
	//Remplacer l'adresse de l'objet personne par la nouvelle adresse
	adresse.asgAdresse(noRue,nomRue,ville,codePostal,province);
	personne.asgAdresse(adresse);
	//Afficher la nouvelle adresse
	cout << "Les informations avec modifications sont les suivantes : " << endl;
	cout << personne.reqPersonneFormate() << endl;


	//Sauvegarder les valeurs de l'instance de l'objet personne dans un fichier
	cout << "Indiquer le nom du fichier dans lequel vous voulez sauvegarder les information :" << endl;
	string fichier;
	cin >> fichier;

	ofstream unFlux(fichier.c_str(), ios::out);
	unFlux << personne;

	return 0;
}



