#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <optional>

#include "Operator.h"

class Operation
{
private:
	/* Q3. Ajouter les attributs nécessaires */
	int left;
	int right;
	const Operator& used_operator;

public:
	Operation(int left, const Operator& n, int right);

	/* Q4. Ajouter un opérateur d'affichage permettant d'afficher l'opération,
	 * par exemple sous la forme "3 + 2 = 5" */
	friend std::ostream& operator<<(std::ostream& os, Operation& op);
};


#endif //OPERATION_H
