#ifndef DERIVATION_ITERATOR_H
#define DERIVATION_ITERATOR_H

#include <iterator>
#include <vector>
#include <tuple>

// "forward-declaration" de la classe Derivation, pour pouvoir utiliser
// pointeurs et références dessus sans l'inclure entièrement (parce que ça
// provoquerait une inclusion croisée)
class Derivation;

class DerivationIterator : public std::iterator_traits<std::tuple<int, int>>
{
private:
	const Derivation* derivation;
	std::vector<int>::const_iterator it;
	std::vector<int>::const_iterator jt;

public:
	/*
	 * Ce marqueur, utilisé par convention dans la bibliothèque standard,
	 * identifie les itérateurs les plus basiques : ceux en lecture-seule,
	 * avançant dans une seule direction et qui ne peuvent pas sauter
	 * d'élément.
	 */
	using iterator_category = std::forward_iterator_tag;

	explicit DerivationIterator(const Derivation& d);

	/*
	 * Crée un itérateur invalide, servant d'itérateur de fin
	 */
	DerivationIterator();

	/*
	 * Q8. Implémenter cet opérateur
	 */
	void operator++();

	/*
	 * Cet opérateur retourne la paire correspondant à la position de
	 * l'itérateur
	 */
	std::tuple<int, int> operator*();

	/*
	 * Cet opérateur sert essentiellement à comparer un itérateur à
	 * l'itérateur de fin.
	 */
	bool operator!=(const DerivationIterator& dit);
};

#endif // DERIVATION_ITERATOR_H
