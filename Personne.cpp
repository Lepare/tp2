/**
 * \file Personne.cpp
 * \brief Implementation de la classe Personne
 * \version 0.1
 * \date 2014-10-12
 * \author etudiant
 */
#include <string>
#include <iostream>
#include "Personne.h"
#include "Adresse.h"
#include "Date.h"

namespace election
{
/**
 * \brief Constructeur de la classe Personne
 * \param[in] p_nas
 * \param[in] p_prenom
 * \param[in] p_nom
 * \param[in] p_dateNaissance
 * \param[in] p_adresse
 * \return un objet Personne
 */
Personne::Personne(const std::string& p_nas,const std::string& p_prenom,const std::string& p_nom,
		const util::Date& p_dateNaissance, const util::Adresse& p_adresse):
		m_nas(p_nas), m_prenom(p_prenom), m_nom(p_nom),m_dateNaissance(p_dateNaissance),
		m_adresse(p_adresse)

{
	// TODO Auto-generated constructor stub

}

/**
 * \brief Surcharge de l'operateur <<
 * \param[in] p_os,p_personne
 * \return un flux
 */
std::ostream& operator<<(std::ostream& p_os, const Personne& p_personne)
{

	p_os << p_personne.m_nas << std::endl << p_personne.m_prenom << std::endl << p_personne.m_nom << std::endl <<
	p_personne.m_dateNaissance.reqJour() << " " << p_personne.m_dateNaissance.reqMois() << " " <<
	p_personne.m_dateNaissance.reqAnnee() << std::endl << p_personne.m_adresse.reqNoRue() << std::endl <<
	p_personne.m_adresse.reqNomRue() << std::endl << p_personne.m_adresse.reqVille() << std::endl <<
	p_personne.m_adresse.reqCodePostal() << std::endl << p_personne.m_adresse.reqProvince() << std::endl ;
	return p_os;

}
/**
 * \brief Surcharge de l'operateur ==
 * \param[in] p_personne
 * \return bool
 */
bool Personne::operator==(const Personne& p_personne) const
{
	return (m_nas == p_personne.m_nas && m_prenom == p_personne.m_prenom && m_nom == p_personne.m_nom &&
			m_dateNaissance == p_personne.m_dateNaissance && m_adresse == p_personne.m_adresse);
}

/**
 * \brief Formate les informations d'une personne dans une chaine de caratere
 * \return os.str()
 */
std::string Personne::reqPersonneFormate()
{
	std::ostringstream os;
	os << "NAS               : " << m_nas << std::endl << "Prenom            : " << m_prenom << std::endl
	<< "Nom               : " << m_nom << std::endl << "Date de naissance : " << m_dateNaissance.reqDateFormatee() << std::endl
	<< "Adresse           : " << m_adresse << std::endl;
	return os.str();
}
/**
 * \brief Retourne la valeur de d'adresse
 * \return m_adresse
 */
const util::Adresse& Personne::reqAdresse() const
{
	return m_adresse;
}
/**
 * \brief Permet de modifier l'adresse
 * \param[in] p_adresse
 */
void Personne::asgAdresse(const util::Adresse& p_adresse)
{
	m_adresse = p_adresse;
}
/**
 * \brief Retourne la date de naissance
 * return m_dateNaissance
 */
util::Date Personne::reqDateNaissance() const
{
	return m_dateNaissance;
}
/**
 * \brief Permet de modifier la date de naissance
 * \param[in] p_dateNaissance
 * \return return_type
 */
void Personne::asgDateNaissance(util::Date p_dateNaissance)
{
	m_dateNaissance = p_dateNaissance;
}
/**
 * \brief Retourne le NAS
 * \return m_nas
 */
const std::string& Personne::reqNas() const
{
	return m_nas;
}
/**
 * \brief Permet de modifier un Nas
 * \param[in] p_nas un string
 */
void Personne::asgNas(const std::string& p_nas)
{
	m_nas = p_nas;
}
/**
 * \brief Retourne le nom
 * \return m_nom
 */
const std::string& Personne::reqNom() const
{
	return m_nom;
}
/**
 * \brief Permet de modifier un nom
 * \param[in] p_nom un string
 */
void Personne::asgNom(const std::string& p_nom)
{
	m_nom = p_nom;
}
/**
 * \brief Retourne le prenom
 * \return m_prenom
 */
const std::string& Personne::reqPrenom() const
{
	return m_prenom;
}
/**
 * \brief Permet de modifier un prenom
 * \param[in] p_prenom un string
 */
void Personne::asgPrenom(const std::string& p_prenom)
{
	m_prenom = p_prenom;
}

} /* namespace election */
