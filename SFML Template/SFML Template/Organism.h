#pragma once
class Organism
{
private:
	int type;
	int life;
public:
	Organism();
	Organism(int);		//used to set types
	~Organism();

	void setType(int);
	void setLife(int);
	int getLife();
	int getType();

	void setOrganism(int);
	void incLife();
	void decLife();
};

