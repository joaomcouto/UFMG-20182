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
		this->mp += a.mp ;
		this->strenght += a.strenght ;
		this->constitution += a.constitution ;
		this->dexterity += a.dexterity ;
		return *this ;
	}
	inline Stats operator +(Stats a){
		Stats t ;
		t.level = this->level + a.level ;
		t.hp = this->hp + a.hp ;
		t.mp = this->mp + a.mp ;
		t.strenght =this->strenght + a.strenght ;
		t.constitution =this->constitution + a.constitution ;
		t.dexterity =this->dexterity + a.dexterity ;
		return t ;
	}
	int printStats(){
		std::cout << " ->Health: " << this->hp  << std::endl;
		std::cout << " ->Magic Points: " << this->mp  << std::endl;
		std::cout << " ->Strenght: " << this->strenght  << std::endl;
		std::cout << " ->Constitution: " << this->constitution  << std::endl;
		std::cout << " ->Dexterity: " << this->dexterity  << std::endl;
	}
} Stats ;

#endif