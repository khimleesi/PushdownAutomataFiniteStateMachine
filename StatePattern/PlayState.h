#pragma once
#include "GameState.h"

class PlayState : public GameState {

public:
	PlayState(GameState* previousState, const std::string& name);
	virtual ~PlayState();

public:
	virtual bool Update() override;
	virtual bool Render() override;

private:
	bool Initialize();
};