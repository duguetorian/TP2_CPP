#include <algorithm>
#include <iostream>
#include <sstream>
#include <iterator>

#include <vector>
#include <deque>
#include <string>

// #include "Derivation.h"
#include "Operation.h"
#include "Operator.h"
#include "OperatorPlus.h"
#include "OperatorDiv.h"
#include "OperatorMinus.h"

/*
 * Exemple de tests pour vos classes Operator, n'hésitez pas à en ajouter et à
 * en faire autant pour les autres classes.
 *
 * int testOperator()
 * {
 *    OperatorPlus plus;
 *    std::cout << plus(3,4) << "\n"; // doit afficher 7
 *
 *    OperatorTimes times;
 *    std::cout << times(3,4) << "\n"; // doit afficher 12
 *
 *    OperatorMinus minus;
 *    std::cout << minus(3,4) << " " << minus(4,3) << "\n"; // doit afficher 0 1
 *
 *    OperatorDiv div;
 *    std::cout << div(7,2) << " " << div(8,4) << "\n"; // doit afficher 0 2
 *  }
 */


int main()
{
	#if false
	/* Lire les nombres depuis l'entrée standard
	 * on lit d'abord le résultat-cible, puis une série de nombres
	 */
	std::vector<long> numbers;
	long target;

	std::cin >> target;
	std::copy(std::istream_iterator<long>(std::cin), std::istream_iterator<long>{}, std::back_inserter(numbers));

	std::cout << "Numbers: ";
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<long>{std::cout, " "});
	std::cout << "\n";

	std::cout << "Target: " << target << std::endl;
	#endif

	int left = 10;
	int right = 2;
	OperatorPlus plus;
	OperatorDiv div;
	OperatorMinus minus;
	std::cout << "10 + 2 = " << plus(left, right) << "\n" << std::endl;
	std::cout << "10 / 2 = " << div(left, right) << "\n" << std::endl;
	std::cout << "10 - 2 = " << minus(left, right) << "\n" << std::endl;

#if false
	/* On crée une pile de Derivation pour parcourir toutes les combinaisons
	 * possibles en fonction des nombres disponibles */
	std::vector<Derivation> derivations{ Derivation{numbers, target} };
	/* On stocke la meilleure Derivation trouvée jusqu'alors */
	Derivation result;
	unsigned long maxDistance = target;

	/* On utilise la condition maxDistance > 0 pour se limiter à la
	 * première solution exacte trouvée */
	while (!derivations.empty() && maxDistance > 0) {
		/* On prend la Derivation en haut de la pile et on la retire */
		Derivation d = derivations.back();
		derivations.pop_back();

		/* Q10 Itérer sur toutes les paires d'éléments disponibles et
		 * puis tous les opérateurs disponibles pour les combiner */

		/* Si l'opération est valide (par exemple, que des divisions
		 * entières), ajouter la Derivation au-dessus de la pile avec
		 * la nouvelle opération créée.
		 * Vérifier au passage si on a obtenu un nombre plus proche de
		 * la cible. */
	};

	/* Q11 Afficher le résultat */
#endif
}
