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
#include "OperatorTimes.h"
#include "Derivation.h"
#include "DerivationIterator.h"

/*
 * Exemple de tests pour vos classes Operator, n'hésitez pas à en ajouter et à
 * en faire autant pour les autres classes.
 */

void testOperator()
{
	OperatorPlus plus;
	std::cout << plus(3, 4) << "\n"; // doit afficher 7

	OperatorTimes times;
	std::cout << times(3, 4) << "\n"; // doit afficher 12

	OperatorMinus minus;
	std::cout << minus(3, 4) << " " << minus(4, 3) << "\n"; // doit afficher 0 1

	OperatorDiv div;
	std::cout << div(7, 2) << " " << div(8, 4) << "\n"; // doit afficher 0 2
}

void testOperation()
{
	OperatorPlus plus;
	Operation op(5, plus, 10);
	std::cout << op << std::endl;
}

void testDerivation()
{
	OperatorPlus plus;
	OperatorDiv div;
	OperatorMinus minus;
	OperatorTimes times;
	int target = 100;
	std::vector<int> numbers{1, 2, 3, 4, 5, 6, 7, 8};
	Derivation deriv{numbers, target};
	std::cout << deriv << std::endl;
	deriv.addOperation(1, plus, 2);
	std::cout << deriv << std::endl;
	deriv.addOperation(3, times, 5);
	std::cout << deriv << std::endl;
	deriv.addOperation(8, div, 4);
	std::cout << deriv << std::endl;
	deriv.addOperation(7, minus, 6);
	std::cout << deriv << std::endl;
}

int main()
{
	// testOperation();
	// testDerivation();
	/* Lire les nombres depuis l'entrée standard
	 * on lit d'abord le résultat-cible, puis une série de nombres
	 */
	std::vector<int> numbers;
	int target;

	std::cin >> target;
	// for (int i=0; i<6; i++)
	// {
	// 	int number;
	// 	std::cin >> number;
	// 	numbers.push_back(number);
	// }
	std::copy(std::istream_iterator<int>(std::cin), std::istream_iterator<int>{}, std::back_inserter(numbers));

	std::cout << "Numbers: ";
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << "\n";

	std::cout << "Target: " << target << std::endl;

	/* On crée une pile de Derivation pour parcourir toutes les combinaisons
	 * possibles en fonction des nombres disponibles */
	std::vector<Derivation> derivations{Derivation{numbers, target}};
	/* On stocke la meilleure Derivation trouvée jusqu'alors */
	Derivation result(derivations.at(0));
	unsigned int maxDistance = target;

	OperatorPlus plus;
	OperatorDiv div;
	OperatorMinus minus;
	OperatorTimes times;
	/* On utilise la condition maxDistance > 0 pour se limiter à la
	 * première solution exacte trouvée */
	while (!derivations.empty() && maxDistance > 0)
	{
		/* On prend la Derivation en haut de la pile et on la retire */
		Derivation d = derivations.back();
		derivations.pop_back();

		/* Q10 Itérer sur toutes les paires d'éléments disponibles et
		 * puis tous les opérateurs disponibles pour les combiner */
		DerivationIterator it{d};

		while (it != d.end())
		{
			auto left = std::get<0>(*it);
			auto right = std::get<1>(*it);

			Derivation plus_d{d};
			Derivation times_d{d};
			Derivation minus_d{d};
			Derivation div_d{d};

			if (plus_d.addOperation(left, plus, right))
			{
				if (plus_d.distance() < maxDistance)
				{
					result = plus_d;
					maxDistance = plus_d.distance();
				}
				if (plus_d.begin() != plus_d.end())
				{
					derivations.push_back(plus_d);
				}
			}
			if (times_d.addOperation(left, times, right))
			{
				if (times_d.distance() < maxDistance)
				{
					result = times_d;
					maxDistance = times_d.distance();
				}
				if (times_d.begin() != times_d.end())
				{
					derivations.push_back(times_d);
				}
			}
			if (minus_d.addOperation(left, minus, right))
			{
				if (minus_d.distance() < maxDistance)
				{
					result = minus_d;
					maxDistance = minus_d.distance();
				}
				if (minus_d.begin() != minus_d.end())
				{
					derivations.push_back(minus_d);
				}
			}
			else if (minus_d.addOperation(right, minus, left))
			{
				if (minus_d.distance() < maxDistance)
				{
					result = minus_d;
					maxDistance = minus_d.distance();
				}
				if (minus_d.begin() != minus_d.end())
				{
					derivations.push_back(minus_d);
				}
			}
			if (div_d.addOperation(left, div, right))
			{
				if (div_d.distance() < maxDistance)
				{
					result = div_d;
					maxDistance = div_d.distance();
				}
				if (div_d.begin() != div_d.end())
				{
					derivations.push_back(div_d);
				}
			}
			else if (div_d.addOperation(right, div, left))
			{
				if (div_d.distance() < maxDistance)
				{
					result = div_d;
					maxDistance = div_d.distance();
				}
				if (div_d.begin() != div_d.end())
				{
					derivations.push_back(div_d);
				}
			}
			++it;
		}

		/* Si l'opération est valide (par exemple, que des divisions
		 * entières), ajouter la Derivation au-dessus de la pile avec
		 * la nouvelle opération créée.
		 * Vérifier au passage si on a obtenu un nombre plus proche de
		 * la cible. */
	};

	/* Q11 Afficher le résultat */
	std::cout << result << std::endl;
}
