#ifndef STATS_H
#define STATS_H

#include <iostream>

typedef struct Stats {
	int level;
 	int hp;
 	int mp;
 	int strenght; 
 	int constitution;
 	int dexterity;

	inline Stats operator +=(Stats a){
		this->level += a.level ;
		this->hp += a.hp ;
			if(this->hp < 0) {this->hp = 0;}
		this->mp += a.mp ;
			 if(this->mp < 0) {this->mp = 0;}
		this->strenght += a.strenght ;
				 if(this->strenght < 0) {this->strenght = 0;}
		this->constitution += a.constitution ;
				 if(this->constitution < 0) {this->constitution = 0;}
		this->dexterity += a.dexterity ;
				 if(this->dexterity < 0) {this->dexterity = 0;}
		return *this ;
	}
	inline Stats operator +(Stats a){
		Stats t ;
		t.level = this->level + a.level ;
		t.hp = this->hp + a.hp ;
			if(t.hp < 0) {t.hp = 0;}
		t.mp = this->mp + a.mp ;
			if(t.mp < 0) {t.mp = 0;}
		t.strenght =this->strenght + a.strenght ;
			if(t.strenght < 0) {t.strenght = 0;}
		t.constitution =this->constitution + a.constitution ;
			if(t.constitution < 0) {t.constitution = 0;}
		t.dexterity =this->dexterity + a.dexterity ;
			if(t.dexterity < 0) {t.dexterity = 0;}
		return t ;
	}
	void printStats(){
		std::cout << " ->Health: " << this->hp  << std::endl;
		std::cout << " ->Magic Points: " << this->mp  << std::endl;
		std::cout << " ->Strength: " << this->strenght  << std::endl;
		std::cout << " ->Constitution: " << this->constitution  << std::endl;
		std::cout << " ->Dexterity: " << this->dexterity  << std::endl;
	}
} Stats ;

#endif
