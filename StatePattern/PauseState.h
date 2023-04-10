#pragma once
#include "GameState.h"

class PauseState : public GameState {

public:
	PauseState(GameState* previousState, const std::string& name);
	virtual ~PauseState();

public:
	virtual bool Update() override;
	virtual bool Render() override;

private:
	bool Initialize();
};