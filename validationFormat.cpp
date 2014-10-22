/**
 * \file validationFormat.cpp
 * \brief Implementation des fonctions de validation. Les fonctionnes valides un Nas et un format de fichier.
 * \version 0.1
 * \date 2014-10-12
 * \author etudiant
 */

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

namespace util{
bool validerNas(const string& unNas)
/** Fonction qui valide un Nas.
* \param[in] unNas
* \return valide
* \
*/
{
	//Verifier si le nas a 11 caractere et si il y a un espace au endroit requis.
	bool valide = true;
	if ((unNas.length() != 11) || (unNas[3] != 32) || (unNas[7] != 32))
	{
		valide = false;
	}
	/* Verifie si il y a un espace au mauvais endroit ou un autre caractere invalide.
	 * La boucle compare si le premier caractere de la chaine unNas correspond a un des
	 * carractere representant le nombre 0 a 9. Si le compteur final n'arrive pas a 9,
	 * c'est qu'il y a utilisation de caractere non valide.
	 */
	if(valide)
	{
		int nombreOk = 0;
		for (unsigned int i = 0; i < unNas.length(); i++)
			{
				for (char valeur = 48; valeur < 58; valeur++)
				{
					if (unNas[i] == valeur)
					{
						++nombreOk;
					}
				}
			}
			if (nombreOk == 9)
			{
				valide = true;
			}
			else
			{
				valide = false;
			}
	}
	/* Transformer le nas en un tableau d'entier.*/
	if (valide)
		{
			int unNasInt[9];
			int a = 0;
			for (int i = 0; i < unNas[i]; i++)
			{
				if (unNas[i] != 32)
				{
					unNasInt[a] = unNas[i];
					a++;
				}

			}
			int nasMultplicateur[] = {1,2,1,2,1,2,1,2,1};
			int nasResultatMultiplier[9];
			int b = 48;
			//Donne le resultat de chaque nombre du NAS original multiplier par le NAS verificateur.
			for (int i = 0; i < 9; i++)
			{
				nasResultatMultiplier[i] = (unNasInt[i]-b)*nasMultplicateur[i];
			}


			//Verifie si le resultat de la multiplication est superieur a 10, si oui, on fait
			//la somme des deux nombre.  ex: 10 = 1+0 = 1
			for (int i = 1; i < 9; i++)
			{
				if (nasResultatMultiplier[i] > 9)
				{
					string tropGrand = "";
					ostringstream convertir;
					convertir << (nasResultatMultiplier[i] = ((unNasInt[i]-b)*nasMultplicateur[i]));
					tropGrand = convertir.str();
					int premierNombre = tropGrand[0];
					int deuxiemeNomre = tropGrand[1];
					int c = 48;
					nasResultatMultiplier[i] = (premierNombre-c + deuxiemeNomre-c);
				}
				else
				{
					nasResultatMultiplier[i] = ((unNasInt[i]-b)*nasMultplicateur[i]);
				}

			}
				//Calcul de la somme final pour voir si c est divisible par 10.
				int sommeFinal = 0;
				for (int i = 0 ; i < 9 ; i++)
				{
					sommeFinal += nasResultatMultiplier[i];
				}
				if ((sommeFinal % 10) == 0)
				{
					valide = true;
				}
				else
				{
					valide = false;
				}
			}
	return valide;
}

bool validerFormatFichier(istream& p_is)
/** Fonction qui valide la position des element a l interieur d un fichier.
* \param[in]  p_is
* \return Si le nas est valide.
*/
{
	bool valide;
	// Verifier si l ouverture du fichier est possible.
	if (p_is)
	{

		// Verifier si le fichier commence par un nom de circonscription.
		valide = true;
		string circonscription;
		getline(p_is,circonscription);

		if (circonscription.empty() || p_is.eof())
		{
			valide = false;
		}

		//Verifier si la deuxieme ligne du fichier est un parti valide.
		string parti = "";
		getline(p_is,parti);
		if (not ((parti == "BLOC_QUEBECOIS") || (parti == "INDEPENDANT") || (parti == "CONSERVATEUR")
			|| (parti == "LIBERAL") || (parti == "NOUVEAU_PARTI_DEMOCRATIQUE")))
		{
			valide = false;
		}

		//Lecture du fichier jusqu'a la fin.
		while (not p_is.eof())
		{
			string partiOuNas = "";
			getline(p_is,partiOuNas);

			//Verifie si la ligne est un parti valide.
			if (((partiOuNas == "BLOC_QUEBECOIS") || (partiOuNas == "INDEPENDANT") || (partiOuNas == "CONSERVATEUR")
					|| (partiOuNas == "LIBERAL") || (partiOuNas == "NOUVEAU_PARTI_DEMOCRATIQUE")))
			{

				//Verifie si le nas est valide.
				string NAS = "";
				getline(p_is,NAS);
				if (not (validerNas(NAS)))
				{
					valide = false;
					break;
				}
				//Verifie que la ligne prenom n'est pas vide.
				string prenom = "";
				getline(p_is,prenom);

				if (prenom.empty() != 0)
				{
					valide = false;
					break;
				}
				//Verifie que la ligne nom n'est pas vide.
				string nom = "";
				getline(p_is,nom);
				if (nom.empty() != 0)
				{
					valide = false;
					break;
				}
				//Verifie qu'il y a une date et que sont format soit valide.
				int jour = 0;
				int mois = 0;
				int annee = 0;
				char buffer [100];
				p_is.getline(buffer,99);
				string date = buffer;
				istringstream dateInt(date);
				dateInt >> jour;
				dateInt >> mois;
				dateInt >> annee;
				dateInt.ignore();
				if(not((jour < 32 && jour > 0) && (mois < 13 && mois > 0) && (annee > 999 && annee < 10000)))
				{
					valide = false;
					break;
				}

				//Verifie que la ligne adresse n'est pas vide.
				string adresse = "";
				getline(p_is,adresse);
				if (adresse.empty() != 0)
				{
					valide = false;
					break;
				}
			}
			//Verifie si que si ce n'est pas un nom de parti valide, le nas est valide.
			else if (validerNas(partiOuNas))
			{
				//Verifie que la ligne prenom n'est pas vide.
				string prenom = "";
				getline(p_is,prenom);
				if (prenom.empty() != 0)
				{
					valide = false;
					break;
				}
				//Verifie que la ligne nom n'est pas vide.
				string nom = "";
				getline(p_is,nom);
				if (nom.empty() != 0)
				{
					valide = false;
					break;
				}

				//Verifie qu'il y a une date et que sont format soit valide.
				int jour = 0;
				int mois = 0;
				int annee = 0;
				char buffer [100];
				p_is.getline(buffer,99);
				string date = buffer;
				istringstream dateInt(date);
				dateInt >> jour;
				dateInt >> mois;
				dateInt >> annee;
				dateInt.ignore();

				if(not((jour < 32 && jour > 0) && (mois < 13 && mois > 0) && (annee > 999 && annee < 10000)))
				{
					valide = false;
					break;
				}

				//Verifie que la ligne adresse n'est pas vide.
				string adresse = "";
				getline(p_is,adresse);
				if (adresse.empty() != 0)
				{
					valide = false;
					break;
				}
			}
			else
			{
				valide = false;
				break;
			}

		}
	}

	else
	{
		cerr << "Erreur d'ouverture du fichier.";
	}
	return valide;
}
}




