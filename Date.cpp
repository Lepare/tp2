/**
 * \file Date.cpp
 * \brief Implantation de la classe Date
 *        r�vision : normes 12-2013
 *        balises Doxygen
 *        r�vision des commentaires d'en-t�te des m�thodes
 * \author Yves Roy Version initiale, THE
 * \date 10 octobre 2013
 * \version 2.2
 */
// derni�re modification : 2014-09-12

#include "Date.h"
#include <sstream>
#include <ctime>
#include <iostream>
static const long MAX_SECONDE = 2145848400;
static const long JOUR_EN_SECONDES = 60 * 60 * 24;
static const long MIN_SECONDE = 5 * 60 * 60; // 5 heure par rapport � Greenwich

using namespace std;
namespace util
{
/**
 * \brief constructeur par d�faut \n
 * La date prise par d�faut est la date du syst�me
 */
Date::Date()
{
	m_temps = time(NULL);

	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);

	asgDate(infoTempsP->tm_mday, infoTempsP->tm_mon + 1,
			infoTempsP->tm_year + 1900);

	INVARIANTS();
}
/**
 * \brief constructeur avec param�tres
 * 		  On construit un objet Date � partir de valeurs pass�es en param�tres.
 * 		  Les attributs sont assign�s seulement si la date est consid�r�e comme valide.
 * 		  Autrement, une erreur d'assertion est g�n�r�e.
 * \param[in] p_jour est un entier long qui repr�sente le jour de la date
 * \param[in] p_mois est un entier long qui repr�sente le mois de la date
 * \param[in] p_annee est un entier long qui repr�sente l'ann�e de la date
 * \pre p_jour, p_mois, p_annee doivent correspondre � une date valide
 * \post l'objet construit a �t� initialis� � partir des entiers pass�s en param�tres
  */
Date::Date(long p_jour, long p_mois, long p_annee)
{
	PRECONDITION (Date::validerDate(p_jour, p_mois, p_annee));

	asgDate(p_jour, p_mois, p_annee);

	POSTCONDITION (reqJour() == p_jour);
	POSTCONDITION (reqMois() == p_mois);
	POSTCONDITION (reqAnnee() == p_annee);
	INVARIANTS();
}
/**
 * \brief Assigne une date � l'objet courant
 * \param[in] p_jour est un entier long qui repr�sente le jour de la date
 * \param[in] p_mois est un entier long qui repr�sente le mois de la date
 * \param[in] p_annee est un entier long qui repr�sente l'ann�e de la date
 * \pre p_jour, p_mois, p_annee doivent correspondre � une date valide
 * \post l'objet a �t� assign� � partir des entiers pass�s en param�tres
 */
void Date::asgDate(long p_jour, long p_mois, long p_annee)
{
	PRECONDITION(Date::validerDate(p_jour, p_mois, p_annee));

	struct tm infoTemps;

	infoTemps.tm_year = (p_annee - 1900);
	infoTemps.tm_mon = (p_mois - 1);
	infoTemps.tm_mday = p_jour;
	infoTemps.tm_hour = 0;
	infoTemps.tm_min = 0;
	infoTemps.tm_sec = 0;
	infoTemps.tm_isdst = -1;

	m_temps = mktime(&infoTemps);

	POSTCONDITION(reqJour() == p_jour);
	POSTCONDITION(reqMois() == p_mois);
	POSTCONDITION(reqAnnee() == p_annee);
	INVARIANTS();
}
/**
 * \brief Ajoute ou retire un certain nombre de jours � la date courante
 * \param[in] p_nbJour est une entier long qui repr�sente le nombre de jours � ajouter ou � soustraire s'il est n�gatif
 * \return un bool�en qui indique si l'op�ration a r�ussi ou non
 */
bool Date::ajouteNbJour(long p_nbJour)
{
	bool bRet = true;

	long tModif = m_temps + (p_nbJour * JOUR_EN_SECONDES);
	if (tModif < MIN_SECONDE || tModif > MAX_SECONDE)
	{
		bRet = false;
	}
	else
	{
		m_temps = m_temps + (p_nbJour * JOUR_EN_SECONDES);
	}

	INVARIANTS();
	return bRet;
}
/**
 * \brief retourne le jour de la date
 * \return un entier long qui repr�sente le jour de la date
 */
long Date::reqJour() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_mday;
}
/**
 * \brief retourne le mois de la date
 * \return un entier long qui repr�sente le mois de la date
 */
long Date::reqMois() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_mon + 1;
}
/**
 * \brief retourne l'ann�e de la date
 * \return un entier long qui repr�sente l'ann�e de la date
 */
long Date::reqAnnee() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_year + 1900;
}
/**
 * \brief retourne le i�me jour de l'ann�e correspondant au jour de la date
 * \return un entier long qui repr�sente le i�me jour de l'ann�e
 */
long Date::reqJourAnnee() const
{
	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return infoTempsP->tm_yday + 1;
}
/**
 * \brief D�terminer si une ann�e est bissextile ou non
 * \param[in] p_annee un entier long qui repr�sente l'ann�e � v�rifier
 * \return estBissextile un bool�en qui a la valeur true si l'ann�e est bissextile et false sinon
 */
bool Date::estBissextile(long p_annee)
{
	bool estBissextile = false;

	if (((p_annee % 4 == 0) && (p_annee % 100 != 0)) || ((p_annee % 4 == 0) && (p_annee
			% 100 == 0) && (p_annee % 400 == 0)))
	{
		estBissextile = true;
	}

	return estBissextile;
}
/**
 * \brief retourne le nom du jour de la semaine en fran�ais
 * \return une cha�ne de caract�res qui repr�sente le nom du jour de la semaine en fran�ais
 */
string Date::reqNomJourSemaine() const
{
	static string JourSemaine[] =
	{ "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" };

	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return JourSemaine[infoTempsP->tm_wday];

}
/**
 * \brief retourne le nom du mois en fran�ais
 * \return une cha�ne de caract�res qui repr�sente le nom du mois en fran�ais
 */
string Date::reqNomMois() const
{
	static string NomMois[] =
	{ "janvier", "fevrier", "mars", "avril", "mai", "juin", "juillet", "aout",
			"septembre", "octobre", "novembre", "decembre" };

	struct tm* infoTempsP = localtime(&m_temps);
	ASSERTION(infoTempsP != NULL);
	return NomMois[infoTempsP->tm_mon];
}
/**
 * \brief retourne une date format�e dans une cha�ne de carac�res (string)
 * \return la date format�e dans une cha�ne de caract�res
 */
 string Date::reqDateFormatee() const
{
	ostringstream os;

	os << reqNomJourSemaine() << " le ";
	if (reqJour() < 10)
	{
		os << "0";
	}
	os << reqJour() << " ";
	os << reqNomMois() << " ";
	os << reqAnnee();

	return os.str();
}

/**
 * \brief V�rifie la validit� d'une date
 * \param[in] p_jour un entier long repr�sentant le jour de la date
 * \param[in] p_mois un entier long repr�sentant  le mois de la date
 * \param[in] p_annee un entier long repr�sentant l'ann�e de la date
 * \return un bool�en indiquant si la date est valide ou non
 */
bool Date::validerDate(long p_jour, long p_mois, long p_annee)
{
	long JourParMois[] =
	{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	static const long DEBUT_TEMPS = 1970;
	static const long FIN_TEMPS = 2037;

	bool valide = false;

	if (p_mois > 0 && p_mois <= 12 && p_annee >= DEBUT_TEMPS && p_annee <= FIN_TEMPS)
	{
		if (p_mois == 2 && Date::estBissextile(p_annee))
		{
			JourParMois[p_mois - 1]++;
		}
		if (p_jour > 0 && p_jour <= JourParMois[p_mois - 1])
		{
			valide = true;
		}
	}
	return valide;
}

/**
 * \brief surcharge de l'op�rateur ==
 * \param[in] p_date � comparer � la date courante
 * \return un bool�en indiquant si les deux dates sont �gales ou non
 */
bool Date::operator==(const Date& p_date) const
{
	return m_temps == p_date.m_temps;
}

/**
 * \brief surcharge de l'op�rateur <
 * \param[in] p_date � comparer � la date courante
 * \return un bool�en indiquant si la date courante est plus petite que la date pass�e en param�tre
 */
bool Date::operator<(const Date& p_date) const
{
	return m_temps < p_date.m_temps;
}

/**
 * \brief retourne le nombre de jours entre deux dates
 * \param[in] p_date � soustraire � la date courante
 * \return un entier qui repr�sente le nombre de jours entre la date courante
 * 	et celle pass�e en param�tre
 */
int Date::operator-(const Date& p_date) const
{
	double nbSec = difftime(m_temps, p_date.m_temps);
	return static_cast<int> (nbSec / JOUR_EN_SECONDES);
}

/**
 * \brief surcharge de la fonction << d'�criture dans un flux de sortie
 * \param[in] p_os un flux de sortie  dans laquelle on va �crire
 * \param[in] p_date sortie dans le flux
 * \return le flux dans lequel on a �crit la date, ceci pour les appels en cascade
 */
 ostream& operator<<( ostream& p_os, const Date& p_date)
{
	long jour = p_date.reqJour();
	long mois = p_date.reqMois();

	if (jour < 10)
	{
		p_os << "0";
	}
	p_os << jour << "/";
	if (mois < 10)
	{
		p_os << "0";
	}
	p_os << mois << "/";
	p_os << p_date.reqAnnee();

	return p_os;
}

/**
 * \brief Teste l'invariant de la classe Date. L'invariant de cette classe s'assure que la date est valide
 */
void Date::verifieInvariant() const
{
	INVARIANT(m_temps >= MIN_SECONDE);
	INVARIANT(m_temps <= MAX_SECONDE);
	INVARIANT(Date::validerDate(reqJour(), reqMois(), reqAnnee()));
}
}// namespace util
