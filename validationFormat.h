/**
 * \file validationFormat.h
 * \brief Prototype des fonctions de validation.
 * \version 0.1
 * \date 2014-10-12
 * \author etudiant
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
namespace util{

bool validerNas(const std::string& unNas);
bool validerFormatFichier(std::istream& p_is);
}

#endif /* VALIDATIONFORMAT_H_ */
