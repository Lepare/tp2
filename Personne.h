/**
 * \file Personne.h
 * \brief Prototype de la classe Personne
 * \version 0.1
 * \date 2014-10-12
 * \author etudiant
 */

#ifndef PERSONNE_H_
#define PERSONNE_H_

#include "Adresse.h"
#include "Date.h"

namespace election
{
/**
 * \class Personne
 * \brief Prototype de la classe Personne.
 */
class Personne
{
	friend std::ostream& operator<<(std::ostream& p_os, const Personne& p_personne);
public:
	Personne(const std::string& p_nas,const std::string& p_prenom,const std::string& p_nom,
			const util::Date& p_dateNaissance, const util::Adresse& p_adresse);


	const util::Adresse& reqAdresse() const;
	util::Date reqDateNaissance() const;
	const std::string& reqNas() const;
	const std::string& reqNom() const;
	const std::string& reqPrenom() const;
	std::string reqPersonneFormate();

	void asgAdresse(const util::Adresse& adresse);
	void asgDateNaissance(util::Date dateNaissance);
	void asgNas(const std::string& nas);
	void asgNom(const std::string& nom);
	void asgPrenom(const std::string& prenom);

	bool operator==(const Personne& p_personne) const;

private:
	std::string m_nas;
	std::string m_prenom;
	std::string m_nom;
	util::Date m_dateNaissance;
	util::Adresse m_adresse;

};

} /* namespace election */

#endif /* PERSONNE_H_ */
