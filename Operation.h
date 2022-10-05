#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <optional>

#include "Operator.h"

class Operation
{
private:
	/* Q3. Ajouter les attributs nécessaires */

public:
	Operation(long left, const Operator& n, long right);

	/* Q4. Ajouter un opérateur d'affichage permettant d'afficher l'opération,
	 * par exemple sous la forme "3 + 2 = 5" */
};


#endif //OPERATION_H
