//This program simulates the predator and prey cellular automatic system
//Programmed by Nick Khouri 2/5/18

#include <SFML\Graphics.hpp>
#include <ctime>
#include <iostream>
#include "Organism.h"

using namespace std;
using namespace sf;

const int resolution = 5;
const int width = 1000;
const int height = 1000;

const int MAXLIFE = 15;				//Sets how long it takes for the prey to reproduce

int main() {
	sf::RenderWindow window(sf::VideoMode(width, height), "Predator and Prey");
	Organism grid [width / resolution][height / resolution];		//holds the types of organism

	//Starting grid parameters
	srand((unsigned)time(NULL));										//new seed every run
	for (int i = 0; i < width / resolution; i++) {
		for (int j = 0; j < height / resolution; j++) {
			int ran = rand() % 2001;
			if(ran<=20)
				grid[i][j].setOrganism(2);
			else if(ran >= 21 && ran <=25)
				grid[i][j].setOrganism(1);
			else
				grid[i][j].setOrganism(0);
		}
	}
	//1 = prey  |   2 = predator
	int count = 1;
	while (window.isOpen()) {
		Organism nextGen[width / resolution][height / resolution];
		for (int i = 1; i < (width / resolution)-1; i++) {
			for (int j = 1; j < (height / resolution)-1; j++) {
				if (grid[i][j].getType() == 1) {


					bool move = false;
					//CHECK TO SEE IF CELL CAN MOVE
					//IF SO, MOVE AND INC LIFE

					int ranmov[8] = {-1, -1, -1, -1, -1, -1, -1, -1};
					int c = 0;

					if (grid[i - 1][j - 1].getType() == 0) {
						ranmov[c] = 1;
						c++;
					}
					if (grid[i - 1][j + 1].getType() == 0) {
						ranmov[c] = 2;
						c++;
					}
					if (grid[i - 1][j].getType() == 0) {
						ranmov[c] = 3;
						c++;
					}
					if (grid[i + 1][j - 1].getType() == 0) {
						ranmov[c] = 4;
						c++;
					}
					if (grid[i + 1][j + 1].getType() == 0) {
						ranmov[c] = 5;
						c++;
					}
					if (grid[i + 1][j].getType() == 0) {
						ranmov[c] = 6;
						c++;
					}
					if (grid[i][j - 1].getType() == 0) {
						ranmov[c] = 7;
						c++;
					}
					if (grid[i][j + 1].getType() == 0) {
						ranmov[c] = 8;
						c++;
					}

					int picker;
					if (ranmov[0] != -1) {
						picker = rand() % c;
					}
					

					if (picker == 1) {
						nextGen[i - 1][j - 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i - 1][j - 1].incLife();
						grid[i][j] = nextGen[i - 1][j - 1];
						move = true;
					}
					if (picker == 2) {
						nextGen[i - 1][j + 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i - 1][j + 1].incLife();
						grid[i][j] = nextGen[i - 1][j + 1];
						move = true;
					}
					else if (picker == 3) {
						nextGen[i - 1][j] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i - 1][j].incLife();
						grid[i][j] = nextGen[i - 1][j];
						move = true;
					}
					else if (picker == 4) {
						nextGen[i + 1][j - 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i + 1][j - 1].incLife();
						grid[i][j] = nextGen[i + 1][j - 1];
						move = true;
					}
					else if (picker == 5) {
						nextGen[i + 1][j + 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i + 1][j + 1].incLife();
						grid[i][j] = nextGen[i + 1][j + 1];
						move = true;
					}
					else if (picker == 6) {
						nextGen[i + 1][j] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i + 1][j].incLife();
						grid[i][j] = nextGen[i + 1][j];
						move = true;
					}
					else if (picker == 7) {
						nextGen[i][j - 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i][j - 1].incLife();
						grid[i][j] = nextGen[i][j - 1];
						move = true;
					}
					else if (picker == 8) {
						nextGen[i][j + 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i][j + 1].incLife();
						grid[i][j] = nextGen[i][j + 1];
						move = true;
					}

					//IF CANNOT MOVE, STAY AND INC LIFE
					if (move == false) {
						nextGen[i][j] = grid[i][j];
						nextGen[i][j].incLife();
					}

					//IF THE LIFE REACHES THRESHOLD, REPRODUCE IN A RANDOM ORDER
					if (grid[i][j].getLife() >= MAXLIFE) {
						if (grid[i - 1][j - 1].getType() == 0) {
							nextGen[i - 1][j - 1].setOrganism(1);
							grid[i][j].setLife(1);
							nextGen[i][j] = grid[i][j];
						}
						else if (grid[i - 1][j + 1].getType() == 0) {
							nextGen[i - 1][j + 1].setOrganism(1);
							grid[i][j].setLife(1);
							nextGen[i][j] = grid[i][j];
						}
						else if (grid[i - 1][j].getType() == 0) {
							nextGen[i - 1][j].setOrganism(1);
							grid[i][j].setLife(1);
							nextGen[i][j] = grid[i][j];
						}
						else if (grid[i + 1][j - 1].getType() == 0) {
							nextGen[i + 1][j - 1].setOrganism(1);
							grid[i][j].setLife(1);
							nextGen[i][j] = grid[i][j];
						}
						else if (grid[i + 1][j + 1].getType() == 0) {
							nextGen[i + 1][j + 1].setOrganism(1);
							grid[i][j].setLife(1);
							nextGen[i][j] = grid[i][j];
						}
						else if (grid[i + 1][j].getType() == 0) {
							nextGen[i + 1][j].setOrganism(1);
							grid[i][j].setLife(1);
							nextGen[i][j] = grid[i][j];
						}
						else if (grid[i][j - 1].getType() == 0) {
							nextGen[i][j - 1].setOrganism(1);
							grid[i][j].setLife(1);
							nextGen[i][j] = grid[i][j];
						}
						else if (grid[i][j + 1].getType() == 0) {
							nextGen[i][j + 1].setOrganism(1);
							grid[i][j].setLife(1);
							nextGen[i][j] = grid[i][j];
						}
					}


				}

				//START THE PREDATOR SCRIPT

				else if (grid[i][j].getType() == 2) {
					int ranmov[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };
					int c = 0;

					if (grid[i - 1][j - 1].getType() == 0) {
						ranmov[c] = 1;
						c++;
					}
					if (grid[i - 1][j + 1].getType() == 0) {
						ranmov[c] = 2;
						c++;
					}
					if (grid[i - 1][j].getType() == 0) {
						ranmov[c] = 3;
						c++;
					}
					if (grid[i + 1][j - 1].getType() == 0) {
						ranmov[c] = 4;
						c++;
					}
					if (grid[i + 1][j + 1].getType() == 0) {
						ranmov[c] = 5;
						c++;
					}
					if (grid[i + 1][j].getType() == 0) {
						ranmov[c] = 6;
						c++;
					}
					if (grid[i][j - 1].getType() == 0) {
						ranmov[c] = 7;
						c++;
					}
					if (grid[i][j + 1].getType() == 0) {
						ranmov[c] = 8;
						c++;
					}

					int picker;
					if (ranmov[0] != -1) {
						picker = rand() % c;
					}

					bool move = false;
					if (picker == 1) {
						nextGen[i - 1][j - 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i - 1][j - 1].decLife();
						grid[i][j] = nextGen[i - 1][j - 1];
						move = true;
					}
					if (picker == 2) {
						nextGen[i - 1][j + 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i - 1][j + 1].decLife();
						grid[i][j] = nextGen[i - 1][j + 1];
						move = true;
					}
					else if (picker == 3) {
						nextGen[i - 1][j] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i - 1][j].decLife();
						grid[i][j] = nextGen[i - 1][j];
						move = true;
					}
					else if (picker == 4) {
						nextGen[i + 1][j - 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i + 1][j - 1].decLife();
						grid[i][j] = nextGen[i + 1][j - 1];
						move = true;
					}
					else if (picker == 5) {
						nextGen[i + 1][j + 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i + 1][j + 1].decLife();
						grid[i][j] = nextGen[i + 1][j + 1];
						move = true;
					}
					else if (picker == 6) {
						nextGen[i + 1][j] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i + 1][j].decLife();
						grid[i][j] = nextGen[i + 1][j];
						move = true;
					}
					else if (picker == 7) {
						nextGen[i][j - 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i][j - 1].decLife();
						grid[i][j] = nextGen[i][j - 1];
						move = true;
					}
					else if (picker == 8) {
						nextGen[i][j + 1] = grid[i][j];
						nextGen[i][j].setOrganism(0);
						nextGen[i][j + 1].decLife();
						grid[i][j] = nextGen[i][j + 1];
						move = true;
					}

					if (move == false) {
						nextGen[i][j] = grid[i][j];
						nextGen[i][j].decLife();
					}

					//CHECK TO SEE IF DEAD
					bool isDead = false;
					if (grid[i][j].getLife() == 1) {
						nextGen[i][j].setOrganism(0);
						isDead = true;
					}

					//KILL SURROUNDINGS
					if (isDead == false) {
						if (grid[i - 1][j - 1].getType() == 1) {
							int life = grid[i - 1][j - 1].getLife();
							nextGen[i - 1][j - 1].setOrganism(2);
							nextGen[i - 1][j - 1].setLife(life);
						}
						if (grid[i - 1][j + 1].getType() == 1) {
							int life = grid[i - 1][j + 1].getLife();
							nextGen[i - 1][j + 1].setOrganism(2);
							nextGen[i - 1][j + 1].setLife(life);
						}
						if (grid[i - 1][j].getType() == 1) {
							int life = grid[i - 1][j].getLife();
							nextGen[i - 1][j].setOrganism(2);
							nextGen[i - 1][j].setLife(life);
						}
						if (grid[i + 1][j - 1].getType() == 1) {
							int life = grid[i + 1][j - 1].getLife();
							nextGen[i + 1][j - 1].setOrganism(2);
							nextGen[i + 1][j - 1].setLife(life);
						}
						if (grid[i + 1][j + 1].getType() == 1) {
							int life = grid[i + 1][j + 1].getLife();
							nextGen[i + 1][j + 1].setOrganism(2);
							nextGen[i + 1][j + 1].setLife(life);
						}
						if (grid[i + 1][j].getType() == 1) {
							int life = grid[i + 1][j].getLife();
							nextGen[i + 1][j].setOrganism(2);
							nextGen[i + 1][j].setLife(life);
						}
						if (grid[i][j - 1].getType() == 1) {
							int life = grid[i][j - 1].getLife();
							nextGen[i][j - 1].setOrganism(2);
							nextGen[i][j - 1].setLife(life);
						}
						if (grid[i][j + 1].getType() == 1) {
							int life = grid[i][j + 1].getLife();
							nextGen[i][j + 1].setOrganism(2);
							nextGen[i][j + 1].setLife(life);
						}
					}


				}
			}
		}



		//UPDATE THE GRID
		for (int i = 0; i < width / resolution; i++) {
			for (int j = 0; j < height / resolution; j++) {
				grid[i][j] = nextGen[i][j];
			}
		}


		cout << "Gen: " << count << endl;
		count++;
		//system("pause");

		window.clear();
		//display the array
		for (int i = 0; i < width / resolution; i++) {
			for (int j = 0; j < height / resolution; j++) {
				if (grid[i][j].getType() == 1) {
					RectangleShape prey(Vector2f(resolution, resolution));
						prey.setFillColor(Color(0, 225 / grid[i][j].getLife(), 0));
					prey.setPosition(j*resolution, i*resolution);
					window.draw(prey);
				}
				else if (grid[i][j].getType() == 2) {
					RectangleShape predator(Vector2f(resolution, resolution));
					if (grid[i][j].getLife() <= 0)
						predator.setFillColor(Color(20, 0, 0));
					else
						predator.setFillColor(Color(225 / grid[i][j].getLife(), 0, 0));
					predator.setPosition(j*resolution, i*resolution);
					window.draw(predator);
				}
			}
		}


		window.display();
	}
}