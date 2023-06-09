#include "MenuState.h"

/*******************************************************************************************************************
	Constructor with initializer list to set default values of data members
*******************************************************************************************************************/
MenuState::MenuState(GameState* previousState, const std::string& name)
	: GameState(previousState, name)
{
	Initialize();
}


/*******************************************************************************************************************
	Cleanup all memory usage, delete all objects and shut down all devices
*******************************************************************************************************************/
MenuState::~MenuState()
{

}


/*******************************************************************************************************************
	Initialize all start up procedures specific to the menu state
*******************************************************************************************************************/
bool MenuState::Initialize()
{
	IsActive() = IsAlive() = true;

	return true;
}


/*******************************************************************************************************************
	Function that updates everything within the menu state
*******************************************************************************************************************/
bool MenuState::Update() 
{
	return true;
}


/*******************************************************************************************************************
	Function that renders all menu state graphics to the screen
*******************************************************************************************************************/
bool MenuState::Render()
{
	return true;
}