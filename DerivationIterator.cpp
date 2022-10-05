#include <vector>
#include <iterator>
#include <tuple>

#include "DerivationIterator.h"
// On doit faire une inclusion de Derivation pour pouvoir utiliser ces
// attributs. Il n'y a pas de risque d'inclusion croisée dans le fichier .cpp
// puisque les .cpp ne sont pas inclus ailleurs (seulement les .h).
#include "Derivation.h"

/*
 * Crée un itérateur de début sur la collection d, qui peut être aussi
 * l'itérateur
 */
DerivationIterator::DerivationIterator(const Derivation& d):
	derivation{d},
	it{d.availables.cbegin()},
	jt{d.availables.cbegin()}
{
	if (jt != d.availables.cend()) {
		++jt;
	}
	// Dans le cas le plus dégénéré, il n'y a qu'un ou zéro élément dans d,
	// et du coup jt == d.availables.cend() donc l'itération est terminée
	// (voir la définition de != plus bas).
}

/*
 * Crée un itérateur invalide, servant d'itérateur de fin
 */
DerivationIterator::DerivationIterator():
	derivation{nullptr}
{}

void DerivationIterator::operator++()
{
	/* Q8. compléter l'algorithme consistant à avancer l'itérateur
	 * d'une position */
	/* si on suppose que les nombres disponibles sont 1 2 3 4, l'itérateur doit
	 * retourner les paires suivantes dans cet ordre : (1,2), (1,3), (1,4),
	 * (2,3), (2,4), (3,4) */
}

std::tuple<long, long> DerivationIterator::operator*()
{
	return {*it, *jt};
}

/*
 * Cet opérateur sert essentiellement à comparer un itérateur à
 * l'itérateur de fin.
 */
bool DerivationIterator::operator!=(const DerivationIterator& dit)
{
	if (derivation == nullptr && dit.derivation == nullptr) {
		return false;
	} else if (derivation == nullptr && dit.derivation != nullptr) {
		return dit.jt != dit.derivation->availables.end();
	} else if (derivation != nullptr && dit.derivation == nullptr) {
		return jt != derivation->availables.end();
	} else {
		return it != dit.it && jt != dit.jt;
	}
}
