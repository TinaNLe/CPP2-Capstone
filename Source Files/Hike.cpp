#include "Hike.h"

using namespace std;

ostream& operator<<(ostream& out, const Hike& aHike)
{
	//'e' easy, 'm' moderate, 's' strenuous
	string difficultyForDisplay;
	switch (aHike.difficulty)
	{
	case 'e':
		difficultyForDisplay = "easy";
		break;
	case 'm':
		difficultyForDisplay = "moderate";
		break;
	case 's':
		difficultyForDisplay = "strenuous";
		break;
	}

	out << "\t" << aHike.hikeName << " ("
		<< aHike.location << ")"
		<< "\n\t  Difficulty: " << difficultyForDisplay
		<< "\n\t  Duration: " << aHike.duration << " day(s)";

	return out;
}

string Hike::getLocation() const
{
	return location;
}

int Hike::getDuration() const
{
	return duration;
}

char Hike::getDifficulty() const
{
	return difficulty;
}

string Hike::getHikeName() const
{
	return hikeName;
}

bool Hike::operator< (const Hike& anotherHike) const
{
	return location < anotherHike.location;
}