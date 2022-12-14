#ifndef DERIVATION_H
#define DERIVATION_H

#include "Operation.h"

#include <iostream>
#include <vector>
#include <iterator>
#include <tuple>

#include "DerivationIterator.h"

class Derivation
{
private:
	/* Q5. ajouter un conteneur d'opérations et de nombres disponibles */
	/* L'attribut target représente le nombre ciblé dont on cherche à s'approcher. */
	int target;
	std::vector<int> availables;
	std::vector<Operation> used_operations;

public:
	/* Q5. Crée une dérivation à partir d'une collection de nombres et d'un
	 * résultat à atteindre (ou approcher) */
	Derivation(std::vector<int> numbers, int target);

	/* Crée une dérivation en en copiant une autre */
	Derivation(const Derivation& base) = default;

	/* Q6. Compléter ces deux méthodes qui indiquent respectivement quel est
	 * le nombre le plus proche de la solution atteint et à quelle
	 * distance de la solution il se trouve */
	int closest() const;
	int distance() const;

	/* Q7. Ajoute une étape à une dérivation */
	bool addOperation(int left, const Operator& o, int right);

	/* Q8. Créer les méthodes begin() et end() renvoyant un itérateur du type
	 * approprié (une spécialisation de DerivationIterator)
	 * begin() doit être un itérateur sur le début de la collection
	 * end()   doit être un itérateur invalide (permettant la fin de
	 *         l'itération)
	 */
	DerivationIterator begin();

	DerivationIterator end();

	/* Q9. Implémenter un opérateur << d'affichage permettant d'afficher la
	 * solution */

	/* La classe iterateur est "friend" pour lui permettre d'itérer en
	 * utilisant les structures de données privées à la classe */
	friend class DerivationIterator;

	friend std::ostream& operator<<(std::ostream& os, Derivation& deriv);
};

#endif //DERIVATION_H
