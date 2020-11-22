/*
 * BaseHunter.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: dfons
 */

#include <BaseHunter.hpp>

std::string BaseHunter::DEFAULT_NAME = "elmer";

BaseHunter::BaseHunter(BaseWeapon& weapon, const std::string name) : name(name), weapon(weapon) {
}

BaseHunter::~BaseHunter() {
}

const std::string& BaseHunter::getName() const {
	return name;
}

void BaseHunter::setName(const std::string &name) {
	this->name = name;
}

BaseWeapon& BaseHunter::getWeapon() const {
	return weapon;
}

void BaseHunter::setWeapon(BaseWeapon& weapon) {
	this->weapon = weapon;
}
