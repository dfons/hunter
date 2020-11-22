/*
 * BaseWeapon.cpp
 *
 *  Created on: Nov 21, 2020
 *      Author: dfons
 */

#include "BaseWeapon.hpp"

#include <stdexcept>

std::string BaseWeapon::DEFAULT_NAME = "revolver";
int BaseWeapon::DEFAULT_CALIBER = 38;
int BaseWeapon::DEFAULT_MAGAZINE = 6;
int BaseWeapon::MIN_CALIBER = 12;
int BaseWeapon::MAX_CALIBER = 60;
int BaseWeapon::MIN_MAGAZINE = 6;
int BaseWeapon::MAX_MAGAZINE = 120;


BaseWeapon::BaseWeapon(const std::string name, const int caliber, const int magazine) : name(name) {
	this->setCaliber(caliber);
	this->setMagazine(magazine);
}

BaseWeapon& BaseWeapon::operator=(const BaseWeapon& other) {
	if(&other != this) {
		this->name = other.name;
		this->caliber = other.caliber;
		this->magazine = other.magazine;
	}

	return *this;
}

BaseWeapon::~BaseWeapon() {
}

int BaseWeapon::getCaliber() const {
	return caliber;
}

void BaseWeapon::setCaliber(int caliber) {
	if(caliber >= BaseWeapon::MIN_CALIBER and caliber <= BaseWeapon::MAX_CALIBER) {
		this->caliber = caliber;
	}
	else {
		throw std::runtime_error("No suitable caliber provided!");
	}
}

int BaseWeapon::getMagazine() const {
	return magazine;
}

void BaseWeapon::setMagazine(int magazine) {
	if(magazine >= BaseWeapon::MIN_MAGAZINE and magazine <= BaseWeapon::MAX_MAGAZINE) {
		this->magazine = magazine;
	}
	else {
		throw std::runtime_error("No suitable magazine size provided!");
	}
}

const std::string& BaseWeapon::getName() const {
	return name;
}

void BaseWeapon::setName(const std::string &name) {
	this->name = name;
}

int BaseWeapon::decMagazine(int delta) {
	std::lock_guard<std::mutex> lock (reloadMtx);

	if(this->magazine >= delta) {
		this->magazine -= delta;
		return delta;
	}
	else {
		int rounds = this->magazine;
		this->magazine = 0;
		return rounds;
	}
}
