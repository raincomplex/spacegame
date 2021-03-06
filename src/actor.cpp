/*   actor.cpp
AUTH xazak
DATE Jan 29 2020
DESC Contains the definitions of the Actor class, which handles the player
	object as well as any NPCs and any usable items and objects
*/

#include "actor.hpp"

using namespace std;

// *** ACTOR METHODS

// The default ctor
Actor::Actor() :
obstructs(true),
visible(true),
location(0, 0),
intent(nullptr),
name("n0b0dY"),
sigil(0x2112),
color("white")
{	}
// The specific ctor
Actor::Actor(bool obstructFlag, bool visibleFlag, string inputName, cpair inputPosition, int inputSigil, string inputColor) :
obstructs(obstructFlag),
visible(visibleFlag),
location(inputPosition),
intent(nullptr),
name(inputName),
sigil(inputSigil),
color(inputColor)
{	}
// A shorthand ctor: name, sigil, color, x = 0, y = 0
Actor::Actor(string inputName, int inputSigil, string inputColor, int xPos, int yPos) :
obstructs(true),
visible(true),
location(xPos, yPos),
intent(nullptr),
name(inputName),
sigil(inputSigil),
color(inputColor)
{	}
void Actor::setAbsLocation(int newXPos, int newYPos) {
	// Sets the actor's location to the exact specified coordinates
	this->location.x = newXPos;
	this->location.y = newYPos;
}
void Actor::setRelLocation(int xOffset, int yOffset) {
	// Sets the actor's position by a relative offset
	this->location.x += xOffset;
	this->location.y += yOffset;
}

// *** PLAYER METHODS
Player::Player() :
Actor("Jenaryk", 0x3113, "light green") {
	intent = new PlayerSentience();
//	LOGMSG("Player object initialized.");
}
void Player::update() {
	// Examines the player's action queue and does the most recent thing
//	LOGMSG("Checking for updates on " << this->getName());
	if (this->intent->hasActions()) this->intent->doNextAction();
}
