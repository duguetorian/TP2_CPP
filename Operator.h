#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <functional>

class Operator
{
public:
	/* Q1. L'opérateur () permet de calculer l'opération représentée par la
	 * classe entre deux * opérandes, elle est implémentée dans les classes-filles */
	virtual int operator()(int left, int right) const = 0;

	/* Q3. La méthode print permet d'afficher une opération entre deux
	 * opérandes, elle est implémentée dans les classes-filles */
	// virtual void print(std::ostream& os, int left, int right) const = 0;
};


#endif //OPERATOR_H
