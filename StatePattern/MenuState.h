#pragma once
#include "GameState.h"

class MenuState : public GameState {

public:
	MenuState(GameState* previousState, const std::string& name);
	virtual ~MenuState();

public:
	virtual bool Update() override;
	virtual bool Render() override;

private:
	bool Initialize();
};