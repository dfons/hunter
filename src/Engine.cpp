/*
 * Engine.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: dfons
 */

#include <Engine.hpp>

Engine::Engine() {
}

Engine::~Engine() {
}

bool Engine::resolveEncounter(BaseHunter& hunter, BaseAnimal& animal, const int shots) {
	int caliber = hunter.getWeapon().getCaliber();
	BaseWeapon& weapon = hunter.getWeapon();

	// Update ammo on weapon.
	weapon.decMagazine(shots);

	int damage = this->energyFromShots(caliber, shots);
	int energy = animal.updateEnergy(damage);

	return energy > 0;
}

int Engine::energyFromShots(int caliber, int shots) {
	return static_cast<int>(shots * caliber * 0.75);
}
