#include "Organism.h"


Organism::Organism()
{
	type = 0;
	life = 0;
}

Organism::Organism(int t)
{
	type = t;
	if (t == 0) {
		life = 0;
	}
	else if (t == 1) {
		life = 1;
	}
	else if (t == 2) {
		life = 4;
	}
}


Organism::~Organism()
{
}

void Organism::setType(int t)
{
	type = t;
}

void Organism::setLife(int l)
{
	life = l;
}

int Organism::getLife()
{
	return life;
}

int Organism::getType()
{
	return type;
}


void Organism::setOrganism(int t, int l)
{
	type = t;
	life = l;
}

void Organism::incLife()
{
	life++;
}

void Organism::decLife() {
	life--;
}
