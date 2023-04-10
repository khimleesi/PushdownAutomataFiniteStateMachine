#include <iostream>
#include "GameState.h"
#include "GUID.h"

/*******************************************************************************************************************
	Constructor with initializer list to set default values of data members
*******************************************************************************************************************/
GameState::GameState(GameState* previousState, const std::string& name)
	: m_previousState(previousState), m_isActive(true), m_isAlive(true), m_name(name), m_GUID("NULL")
{
	m_GUID = CreateGUID(10);
	std::cout << "\nState Created: " << m_name << " | GUID: " << m_GUID << "\n\n";
}


/*******************************************************************************************************************
	Cleanup all memory usage, delete all objects and shut down all devices
*******************************************************************************************************************/
GameState::~GameState()
{
	std::cout << "\nState Destroyed: " << m_name << " | GUID: " << m_GUID << "\n\n";
}


/*******************************************************************************************************************
	Accessor Methods
*******************************************************************************************************************/
bool& GameState::IsActive() { return m_isActive; }
bool& GameState::IsAlive() { return m_isAlive; }
const std::string& GameState::GetName() { return m_name; }
const std::string& GameState::GetGUID() { return m_GUID; }