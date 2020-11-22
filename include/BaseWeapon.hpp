/*
 * BaseWeapon.hpp
 *
 *  Created on: Nov 21, 2020
 *      Author: dfons
 */

#ifndef INCLUDE_BASEWEAPON_HPP_
#define INCLUDE_BASEWEAPON_HPP_

#include <string>
#include <mutex>

class Engine;

class BaseWeapon {
public:
	static std::string DEFAULT_NAME;
	static int DEFAULT_CALIBER;
	static int DEFAULT_MAGAZINE;
	static int MIN_CALIBER;
	static int MAX_CALIBER;
	static int MIN_MAGAZINE;
	static int MAX_MAGAZINE;

public:
	BaseWeapon(const std::string name = BaseWeapon::DEFAULT_NAME,
			   const int caliber = BaseWeapon::DEFAULT_CALIBER,
			   const int magazine = BaseWeapon::DEFAULT_MAGAZINE);
	BaseWeapon& operator=(const BaseWeapon& other);
	virtual ~BaseWeapon();

	int getCaliber() const;
	int getMagazine() const;
	const std::string& getName() const;
	void setName(const std::string &name);

private:
	int decMagazine(int delta);
	void setCaliber(int caliber);
	void setMagazine(int magazine);

private:
	std::string name;
	int caliber;
	int magazine;

	std::mutex reloadMtx;

	friend class Engine;
};

#endif /* INCLUDE_BASEWEAPON_HPP_ */
