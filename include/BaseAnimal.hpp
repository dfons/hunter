/*
 * BaseAnimal.hpp
 *
 *  Created on: Nov 21, 2020
 *      Author: dfons
 */

#ifndef INCLUDE_BASEANIMAL_HPP_
#define INCLUDE_BASEANIMAL_HPP_

#include <string>
#include <mutex>

class Engine;

class BaseAnimal {
public:
	static std::string DEFAULT_NAME;
	static int DEFAULT_ENERGY;
	static int MIN_ENERGY;
	static int MAX_ENERGY;

public:
	BaseAnimal(const std::string name = BaseAnimal::DEFAULT_NAME, const int energy = BaseAnimal::DEFAULT_ENERGY);
	virtual ~BaseAnimal();

	const std::string& getName() const;
	void setName(const std::string &name);

private:
	void setEnergy(int energy);
	int updateEnergy(int delta);

private:
	std::string name;
	int energy;

	std::mutex energyMtx;

	friend class Engine;
};

#endif /* INCLUDE_BASEANIMAL_HPP_ */
