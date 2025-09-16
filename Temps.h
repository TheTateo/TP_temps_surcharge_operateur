#pragma once
#include <iostream>

class Temps
{
public:
	Temps(int heures, int minutes, int secondes);
	void afficher() const;
	Temps& operator+=(const Temps& autre);
	Temps& operator++(int);
	Temps& operator++();
	friend bool operator==(const Temps& t1, const Temps& t2);
	friend Temps operator+(const Temps& t1, const Temps& t2);
	friend std::ostream& operator<<(std::ostream& os, const Temps& _temps);


private:
	int m_heures;
	int m_minutes;
	int m_secondes;
};