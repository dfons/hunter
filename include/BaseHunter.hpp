/*
 * BaseHunter.hpp
 *
 *  Created on: Nov 21, 2020
 *      Author: dfons
 */

#ifndef INCLUDE_BASEHUNTER_HPP_
#define INCLUDE_BASEHUNTER_HPP_

#include <BaseWeapon.hpp>

#include <string>

class BaseHunter {
public:
	static std::string DEFAULT_NAME;

public:
	BaseHunter(BaseWeapon& weapon, const std::string name = BaseHunter::DEFAULT_NAME);
	virtual ~BaseHunter();

	const std::string& getName() const;
	void setName(const std::string &name);
	BaseWeapon& getWeapon() const;
	void setWeapon(BaseWeapon& weapon);

private:
	std::string name;
	BaseWeapon& weapon;

	friend class Engine;
};

#endif /* INCLUDE_BASEHUNTER_HPP_ */
