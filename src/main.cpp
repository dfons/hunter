#include <Engine.hpp>
#include <BaseHunter.hpp>
#include <BaseAnimal.hpp>
#include <BaseWeapon.hpp>

#include <iostream>
#include <stdexcept>

int main() {
    Engine engine;

    try {
		BaseWeapon weapon("shotgun", 45, 6);
		BaseAnimal deer("deer", 30);
		BaseAnimal bear("bear", 90);
		BaseHunter hunter(weapon, "elmer");

		std::cout << "Hunter with shotgun finds deer, 1 shot..." << std::endl;
		bool result = engine.resolveEncounter(hunter, deer, 1);
		std::cout << "Animal is " << (result ? "ALIVE" : "DEAD") << std::endl;

		std::cout << "Hunter with shotgun finds bear, 1 shot..." << std::endl;
		result = engine.resolveEncounter(hunter, bear, 1);
		std::cout << "Animal is " << (result ? "ALIVE" : "DEAD") << std::endl;
    }
    catch(std::runtime_error& ex) {
    	std::cout << "Error is: " << ex.what() << std::endl;
    }

    try {
		BaseWeapon weapon("shotgun", 45, 6);
		BaseAnimal deer("deer", 30);
		BaseAnimal bear("bear", 90);
		BaseHunter hunter(weapon, "elmer");

		std::cout << "Hunter with shotgun finds bear, 3 shot..." << std::endl;
		bool result = engine.resolveEncounter(hunter, bear, 3);
		std::cout << "Animal is " << (result ? "ALIVE" : "DEAD") << std::endl;
	}
	catch(std::runtime_error& ex) {
		std::cout << "Error is: " << ex.what() << std::endl;
	}

    return 0;
}
