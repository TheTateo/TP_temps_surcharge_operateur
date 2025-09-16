#include "Temps.h"
#include <iomanip>

Temps::Temps(int heures, int minutes, int secondes) {
	// Gestion des débordements
	minutes += secondes / 60;
	secondes = secondes % 60;
	heures += minutes / 60;
	minutes = minutes % 60;
	heures = heures % 24;

	m_heures = heures;
	m_minutes = minutes;
	m_secondes = secondes;
}

void Temps::afficher() const {
	//std::cout << m_heures << ":" << m_minutes << ":" << m_secondes <<std::endl;

	std::cout << std::setfill('0') << std::setw(2) << m_heures << ":"
		<< std::setfill('0') << std::setw(2) << m_minutes << ":"
		<< std::setfill('0') << std::setw(2) << m_secondes << std::endl;
}

Temps& Temps::operator+=(const Temps& autre) {
	this->m_heures += autre.m_heures;
	this->m_minutes += autre.m_minutes;
	this->m_secondes += autre.m_secondes;

	// Gestion des débordements après addition
	m_minutes += m_secondes / 60;
	m_secondes = m_secondes % 60;
	m_heures += m_minutes / 60;
	m_minutes = m_minutes % 60;
	m_heures = m_heures % 24;

	return *this;
}

Temps& Temps::operator++(int)
{
	this->m_secondes++;

	// Gestion des débordements après addition
	m_minutes += m_secondes / 60;
	m_secondes = m_secondes % 60;
	m_heures += m_minutes / 60;
	m_minutes = m_minutes % 60;
	m_heures = m_heures % 24;

	return *this;
}

Temps& Temps::operator++()
{
	m_secondes++;
	if (m_secondes >= 60)
	{
		m_secondes -= 60;
		m_minutes++;
		if (m_minutes >= 60)
		{
			m_minutes -= 60;
			m_heures++;
			if (m_heures >= 24)
				m_heures = 0;
		}
	}
	return *this; // Retourne une référence à l'objet modifié
}

bool operator==(const Temps& t1, const Temps& t2)
{
	if ((t1.m_heures == t2.m_heures) &&
		(t1.m_minutes == t2.m_minutes) &&
		(t1.m_secondes == t2.m_secondes)) {
		return true;
	}
	return false;
}

Temps operator+(const Temps& t1, const Temps& t2)
{
	Temps temp(0,0,0);
	temp.m_heures = t1.m_heures + t2.m_heures;
	temp.m_heures %= 24;
	temp.m_minutes = t1.m_minutes + t2.m_minutes;
	temp.m_minutes %= 60;
	temp.m_secondes = t1.m_secondes + t2.m_secondes;
	temp.m_secondes %= 60;

	return temp;
}

std::ostream& operator<<(std::ostream& os, const Temps& _temps)
{
	os << std::setfill('0') << std::setw(2) << _temps.m_heures<< ":"
		<< std::setw(2) << _temps.m_minutes << ":"
		<< std::setw(2) << _temps.m_secondes;
	return os;
}
