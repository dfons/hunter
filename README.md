# Hunter Simulation

## Build the demo
In order to build the demo app, a GCC compiler with C++11 support is required. This demo app includes a MAkefile, so default make target can be used. The make targets must be executed in the root directory of the app, let's say `$HUNTER_DIR`:

```
$ cd $HUNTER_DIR

$ # Build the demo app. A binary called 'hunter' will be created.
$ make all

$ # Clean all objects and binaries.
$ make clean
```

## Run the demo
To run the demo app, just execute the built binary:

```
$ ./hunter
```

## Usage
You can instantiate any of the base classes provided or you can extend any of those classes to implement our own objects. The base classes provided are:
* BaseHunter: Defines a hunter. A hunter holds a weapon an tries to hunt some animals. To instantiate a hunter, you have to provide a `name` and a `weapon`.
* BaseWeapon: Defines a weapon that can be used by a hunter. To instantiate a weapon, you have to provide a `name`, the weapon `caliber` and the `magazine` size. A weapon can shoot if it has enough ammo in its magazine.
* BaseAnimal: Defines an animal that can be hunt b a hunter. To instantiate an animal, you have to provide a `name` and its `energy`. An animal is dead once its energy is 0.

If you want to implement some custom object, the procedure is as follows for all the three object types:

```c++
class MyAnimal : public BaseAnimal {
public:
    MyAnimal() : BaseAnimal("myAnimalName", 90) {};
    virtual ~MyAnimal() {};
};
```

Once you instantiate all your objects, you have to use the `Engine` class to simulate and resolve the encounters between the hunter and some animal:

```c++
BaseWeapon weapon("shotgun", 45, 6);
BaseAnimal deer("deer", 30);
BaseHunter hunter(weapon, "elmer");

bool result = engine.resolveEncounter(hunter, deer, 1);
```

### The Engine
The engine is implemented in the class `Engine` and the only method it provides is:
* `bool resolveEncounter(BaseHunter& hunter, BaseAnimal& animal, const int shots = 1)`: This method resolves an encounter between a hunter and an animal including how many shots the hunter shoots. This method returns `true` if the animal is still alive, `false` otherwise.

Each weapon causes damage to the animal according the caliber you configured in the weapon, the relation between caliber and damage is as follows:
* damage = floor(shots \* caliber \* 0.75)

## Considerations
* The values for the **caliber** property on weapons can be defined between **12** and **60** (defined as constants).
* The values for the **magazine size** property on weapons can be defined between **6** and **120** (defined as constants).
* The values for the **energy** property on animals can be defined between **10** and **100** (defined as constants).
