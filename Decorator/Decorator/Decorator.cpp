#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

// SKŁADNIK
class AbstractNPC {
public:
	virtual void render() = 0;
};

// SKŁADNIK KOŃCOWY
class NPC : public AbstractNPC {
private:
	string name;
public:
	NPC(string basename) { name.assign(basename); }
	NPC(char * basename) { name.assign(basename); }
	void render() { cout << name; }
};

// DEKORATOR
class NPCDecorator : public AbstractNPC {
private:
	AbstractNPC * npc;
public:
	NPCDecorator(AbstractNPC *n) { npc = n; }
	void render() { npc->render(); } // delegate render to npc data member
};

// DEKORATOR A
class Elite : public NPCDecorator {
public:
	Elite(AbstractNPC *n) : NPCDecorator(n) { }
	void render() {
		cout << "Elite "; // render special features
		NPCDecorator::render(); // delegate to base class
	}
};

// DEKORATOR B
class Captain : public NPCDecorator {
public:
	Captain(AbstractNPC *n) : NPCDecorator(n) { }
	void render() {
		cout << "Captain "; // render special features
		NPCDecorator::render(); // delegate to base class
	}
};

// DEKORATOR C
class Shaman : public NPCDecorator {
public:
	Shaman(AbstractNPC *n) : NPCDecorator(n) { }
	void render() {
		NPCDecorator::render(); // delegate to base class
		cout << " Shaman "; // render special features *after* base
	}
};

int main(int argc, char **argv)
{
	AbstractNPC *goblin1 = new Elite(new Shaman(new NPC("Goblin")));
	AbstractNPC *orc1 = new Elite(new Captain(new NPC("Orc")));
	goblin1->render(); cout << endl;
	orc1->render(); cout << endl;

	delete goblin1;
	delete orc1;
	cin.get();
	return 0;
}