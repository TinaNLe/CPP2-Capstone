#ifndef HIKE_H
#define HIKE_H

#include <iostream>
#include <string>

class Hike
{
	friend std::ostream& operator<<(std::ostream& out,
		const Hike& aHike);
public:
	Hike(const std::string& theLocation,
		const std::string& theHikeName,
		int theDuration, char theDifficulty)
		: location(theLocation), hikeName(theHikeName),
		duration(theDuration), difficulty(theDifficulty) {}

	std::string	getLocation() const;
	int getDuration() const;
	char getDifficulty() const;
	std::string getHikeName() const;

	bool operator< (const Hike& anotherHike) const;

private:
	std::string location, hikeName;
	int duration;
	char difficulty; //'e' easy, 'm' moderate, 's' strenuous
};

#endif HIKE_H