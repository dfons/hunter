/*
 * Engine.hpp
 *
 *  Created on: Nov 21, 2020
 *      Author: dfons
 */

#ifndef INCLUDE_ENGINE_HPP_
#define INCLUDE_ENGINE_HPP_

#include <BaseAnimal.hpp>
#include <BaseHunter.hpp>
#include <BaseWeapon.hpp>

class Engine {
public:
	Engine();
	virtual ~Engine();

	bool resolveEncounter(BaseHunter& hunter, BaseAnimal& animal, const int shots = 1);

private:
	int energyFromShots(int caliber, int shots);
};

#endif /* INCLUDE_ENGINE_HPP_ */
