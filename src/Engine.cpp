/*
 * Engine.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: dfons
 */

#include <Engine.hpp>

#include <iostream>

Engine::Engine() {
}

Engine::~Engine() {
}

bool Engine::resolveEncounter(BaseHunter& hunter, BaseAnimal& animal, const int shots) {
	BaseWeapon& weapon = hunter.getWeapon();

	if(weapon.getMagazine() <= 0) {
		std::cout << "[Engine] Hunter can't shoot, no ammo in magazine." << std::endl;
		return true;
	}

	// If magazine is lower than required shots, just shoot with the available ammo.
	int effectiveShots = weapon.getMagazine() < shots ? weapon.getMagazine() : shots;
	int caliber = weapon.getCaliber();

	// Update ammo on weapon (i.e. shoot!).
	int effectiveRounds = weapon.decMagazine(effectiveShots);
	int damage = this->energyFromShots(caliber, effectiveShots);
	int energy = animal.updateEnergy(damage);

	std::cout << "[Engine] Hunter shoot " << effectiveRounds << " times, "
			  << "damage inflicted was " << damage << ", "
			  << "energy left on animal is " << energy << "." << std::endl;

	return energy > 0;
}

int Engine::energyFromShots(int caliber, int shots) {
	return static_cast<int>(shots * caliber * 0.75);
}
