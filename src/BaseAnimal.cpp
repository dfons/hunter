/*
 * BaseAnimal.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: dfons
 */

#include <BaseAnimal.hpp>

#include <stdexcept>

std::string BaseAnimal::DEFAULT_NAME = "bear";
int BaseAnimal::DEFAULT_ENERGY = 100;
int BaseAnimal::MIN_ENERGY = 10;
int BaseAnimal::MAX_ENERGY = 100;

BaseAnimal::BaseAnimal(const std::string name, const int energy) : name(name) {
	this->setEnergy(energy);
}

BaseAnimal::~BaseAnimal() {
}

const std::string& BaseAnimal::getName() const {
	return name;
}

void BaseAnimal::setName(const std::string &name) {
	this->name = name;
}

void BaseAnimal::setEnergy(int energy) {
	if(energy >= BaseAnimal::MIN_ENERGY and energy <= BaseAnimal::MAX_ENERGY) {
		this->energy = energy;
	}
	else {
		throw std::runtime_error("No suitable energy provided!");
	}
}

int BaseAnimal::updateEnergy(int delta){
	std::lock_guard<std::mutex> lock (energyMtx);

	if(this->energy >= delta) {
		this->energy -= delta;
	}
	else {
		this->energy = 0;
	}

	return this->energy;
}
