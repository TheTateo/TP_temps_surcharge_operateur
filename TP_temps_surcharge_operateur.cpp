// TP_temps_surcharge_operateur.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Temps.h"

using namespace std;

int main()
{	
	Temps t1(1, 30, 0);
	Temps t2(0, 45, 0);
	Temps t3(0, 45, 0);

	// affichage des heures
	cout << "t1 : ";
	t1.afficher();
	cout << "t2 : ";
	t2.afficher();
	cout << "t3 : ";
	t3.afficher();

	// Vérification surcharge opérateur ==
	if ((t1 == t2) == true)
		std::cout << "t1 et t2 sont egaux." << std::endl;
	else
		std::cout << "t1 et t2 ne sont pas egaux." << std::endl;

	if ((t2 == t3) == true)
		std::cout << "t2 et t3 sont egaux." << std::endl;
	else
		std::cout << "t2 et t3 ne sont pas egaux." << std::endl;

	// Vérification surcharge opérateur +=
	cout << "surcharge operateur += : ";
	t1 += t2;
	t1.afficher();

	// Vérification surcharge opérateur ++ post-fixée
	cout << "surcharge operateur ++ : ";
	Temps t(1, 59, 59);
	t++;
	t.afficher();

	// Vérification surcharge opérateur +
	cout << "surcharge operateur + : ";
	Temps t4 = t1 + t2;
	t4.afficher();

	// Vérification surcharge de flux de sortie <<
	cout << "La duree est de " << t1 << endl;
	return 0;
}
