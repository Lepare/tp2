JE VIENS DE BOUSSILLER MON BODE AVEC CETTE PHRASE!!
/**
 * \file Adresse.cpp
 * \brief classe adresse
 * \author Maxime Pare
 * \version 0.1
 * \date 2014-10-11
 */
#include <sstream>
#include <iostream>
#include "Adresse.h"
using namespace std;

namespace util
{
/**
 * \brief constructeur
 * \param[in] p_noRue une chaine de caracteres contenant le numero de la rue.
 * \param[in] p_nomRue une chaine de caracteres contenant le num de la rue.
 * \param[in] p_ville une chaine de caracteres contenant le nom de la ville.
 * \param[in] p_codePostal une chaine de caracteres contenant le code postal.
 * \param[in] p_province une chaine de caracteres contenant la province.
 */
Adresse::Adresse(const std::string& p_noRue, const std::string& p_nomRue,const std::string& p_ville,
		const std::string& p_codePostal,const std::string& p_province) :
		m_noRue(p_noRue),m_nomRue(p_nomRue),m_ville(p_ville),
		m_codePostal(p_codePostal),m_province(p_province)
{
}

/**
 * \brief permet de modifier une adresse au complet.
 * \param[in] p_noRue une chaine de caracteres contenant le numero de la rue.
 * \param[in] p_nomRue une chaine de caracteres contenant le num de la rue.
 * \param[in] p_ville une chaine de caracteres contenant le nom de la ville.
 * \param[in] p_codePostal une chaine de caracteres contenant le code postal.
 * \param[in] p_province une chaine de caracteres contenant la province.
 */
void Adresse::asgAdresse(const std::string& p_noRue, const std::string& p_nomRue,const std::string& p_ville,
		const std::string& p_codePostal,const std::string& p_province)
{
	asgNoRue(p_noRue);
	asgNomRue(p_nomRue);
	asgVille(p_ville);;
	asgCodePostal(p_codePostal);
	asgProvince(p_province);
}
/**
 * \brief opérateur de sortie vers un flux pour l'afichage, l'écriture dans un fichier, etc.
 * \param[in] p_os
 * \param[in] p_adresse
 * \return un flux de sortie pour les appels en cascade
 */
std::ostream& operator<<(std::ostream& p_os, const Adresse& p_adresse)
{
	p_os << p_adresse.m_noRue << ", " << p_adresse.m_nomRue << ", " << p_adresse.m_ville << ", " <<
			p_adresse.m_codePostal << ", " <<  p_adresse.m_province << endl;
	return p_os;
}

/**
 * \brief accesseur
 * \return le code postal sous la forme d'un objet string
 */
const std::string& Adresse::reqCodePostal() const {
	return m_codePostal;
}
/**
 * \brief permet de modifier un code postal
 * \param[in] p_codePostal
 */
void Adresse::asgCodePostal(const std::string& p_codePostal) {
	m_codePostal = p_codePostal;
}
/**
 * \brief accesseur
 * \return le nom de la rue sous la forme d'un objet string
 */
const std::string& Adresse::reqNomRue() const {
	return m_nomRue;
}
/**
 * \brief permet de modifier un nom de rue
 * \param[in] p_nomRue
 */
void Adresse::asgNomRue(const std::string& p_nomRue) {
	m_nomRue = p_nomRue;
}
/**
 * \brief accesseur
 * \return le numero de la rue sous la forme d'un objet string
 */
const std::string& Adresse::reqNoRue() const {
	return m_noRue;
}
/**
 * \brief permet de modifier un no de rue
 * \param[in] p_noRue
 */
void Adresse::asgNoRue(const std::string& p_noRue) {
	m_noRue = p_noRue;
}
/**
 * \brief accesseur
 * \return la province sous la forme d'un objet string
 */
const std::string& Adresse::reqProvince() const {
	return m_province;
}
/**
 * \brief permet de modifier la province
 * \param[in] p_province
 */
void Adresse::asgProvince(const std::string& p_province) {
	m_province = p_province;
}
/**
 * \brief accesseur
 * \return la ville sous la forme d'un objet string
 */
const std::string& Adresse::reqVille() const {
	return m_ville;
}
/**
 * \brief permet de modifier la ville
 * \param[in] p_ville
 */
void Adresse::asgVille(const std::string& p_ville) {
	m_ville = p_ville;
}

/**
 * \brief accesseur
 * \return l'adresse complete formatee sous la forme d'un objet string
 */
std::string Adresse::reqAdresseFormate()
{
	ostringstream os;
	os << m_noRue << ", " << m_nomRue << ", " << m_ville << ", " << m_codePostal <<
			", " << m_province << endl;
	return os.str();
}

/**
 * \brief Surchargeur de l'operater de comparaison pour comparer deux adresse
 * \return si deux adresse sont pareille ou non
 */
bool Adresse::operator==(const Adresse& p_adresse) const
{
	return (m_noRue == p_adresse.m_noRue && m_nomRue == p_adresse.m_nomRue &&
			m_ville == p_adresse.m_ville && m_codePostal == p_adresse.m_codePostal &&
			m_province == p_adresse.m_province);
}


} //namespace util

