/**
 * \file Adresse.h
 * \brief  interface de la classe adresse
 * \author Maxime Pare
 * \version 0.1
 * \date 2014-10-11
 */
#ifndef ADRESSE_H_
#define ADRESSE_H_
#include<string>
#include<sstream>

namespace util
{
/**
 * \class Adresse
 * \brief Classe Adresse permettant de modéliser les objets adresse
 */
class Adresse
{

	friend std::ostream& operator<<(std::ostream& p_os, const Adresse& p_adresse);

public:
	//Constructeur avec parametres
	Adresse(const std::string& p_noRue, const std::string& p_nomRue,const std::string& p_ville,
			const std::string& p_codePostal,const std::string& p_province);



	//Acceseurs
	const std::string& reqCodePostal() const;
	const std::string& reqNomRue() const;
	const std::string& reqNoRue() const;
	const std::string& reqProvince() const;
	const std::string& reqVille() const;
	std::string reqAdresseFormate();

	//Mutateurs
	void asgAdresse(const std::string& p_noRue, const std::string& p_nomRue,const std::string& p_ville,
			const std::string& p_codePostal,const std::string& p_province);

	void asgCodePostal(const std::string& codePostal);
	void asgNomRue(const std::string& nomRue);
	void asgNoRue(const std::string& noRue);
	void asgProvince(const std::string& province);
	void asgVille(const std::string& ville);

	//Operateur d'egalite
	bool operator==(const Adresse& p_adresse) const;


private:
	std::string m_adresse;
	std::string m_noRue;
	std::string m_nomRue;
	std::string m_ville;
	std::string m_codePostal;
	std::string m_province;

};

}

#endif /* ADDRESSE_H_ */
