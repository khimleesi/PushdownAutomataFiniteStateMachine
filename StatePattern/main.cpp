//--- Pushdown Automata Finite State Machine Example
//--- Created by Kim Kane www.khimleesi.com

#include "FiniteStateMachine.h"
#include "MenuState.h"
#include "PlayState.h"
#include "PauseState.h"

typedef FiniteStateMachine<GameState> GameStates;

GameStates gameStates;

//--- A quick preview to demonstrate the FSM working. We would normally do this in our Game Loop within some kind of game manager / application class
int main()
{
	std::cout << "Select option:\n";
	std::cout << "[E] Exit\n";
	std::cout << "[T] Add temporary state\n";
	std::cout << "[P] Add permanent state\n";
	std::cout << "[A] Toggle current state active / inactive\n";
	std::cout << "[D] Destroy current state\n";
	std::cout << "[C] Show count of game states currently in stack.\n";
	
	gameStates.MakeTemporaryState<MenuState>(nullptr, "Temporary MenuState");
	
	bool endGame = false;
	bool windowClosed = false;
	std::string input = "";

	while (!endGame) {

		//--- While we have an active game state continue, if the window is closed at any stage we break out of this loop
		while (gameStates.CurrentState()->IsActive()) {

			while (std::getline(std::cin, (input)))
			{ 
				if (input == "E") {
					gameStates.CurrentState()->IsActive() = gameStates.CurrentState()->IsAlive() = false;
					gameStates.PreviousState()->IsActive() = gameStates.PreviousState()->IsAlive() = false;
					std::cout << "Window Closed event triggered. Killing all states." << std::endl;
					windowClosed = true;
					break;
				}
				else if (input == "T")
				{
					gameStates.MakeTemporaryState<PauseState>(gameStates.CurrentState(), "Temporary PauseState");
				}
				else if (input == "P")
				{
					gameStates.MakePermanentState<PlayState>(gameStates.CurrentState(), "Permanent PlayState");
				}
				else if (input == "A")
				{
					std::cout << "\nToggle Active: " << gameStates.CurrentState()->GetName() << " | " << gameStates.CurrentState()->GetGUID() << std::endl;
				
					gameStates.CurrentState()->IsActive() = !gameStates.CurrentState()->IsActive();

					(gameStates.CurrentState()->IsActive()) ? std::cout << "Now Active\n" << std::endl : std::cout << "Now Inactive\n" << std::endl;
				}
				else if (input == "D")
				{
					std::cout << "\nDestroying Game State: " << gameStates.CurrentState()->GetName() << std::endl;
					gameStates.CurrentState()->IsActive() = gameStates.CurrentState()->IsAlive() = false;
					break;
				}
				else if (input == "C")
				{
					std::cout << "\n";
					for (auto& state : gameStates.GetAllStates())
					{
						std::cout << state.get()->GetName() << " | " << state.get()->GetGUID() << std::endl;
					}
					std::cout << "Total States: " << gameStates.GetAllStates().size() << "\n\n";
				}
				else
				{
					std::cout << "\nEnter a valid input.\n" << std::endl;
				}
			}
			
			if (!windowClosed) {
				//--- Update the game and process all physics
				gameStates.CurrentState()->Update();

				//--- Render all graphics
				gameStates.CurrentState()->Render();
			}
		}

		//--- Check if we still have a current game state & if we killed the state, remove it from the stack
		if (!gameStates.CurrentState()->IsAlive())
		{ 
			std::cout << "Removing game state from the stack: " << gameStates.CurrentState()->GetName() << std::endl;
			gameStates.RemoveState(); 
		}
		
		//--- And if the states stack is empty, we end the game and clear the stack
		if (gameStates.IsEmpty())
		{ 
			std::cout << "No game states left in the stack. Exiting the Game." << std::endl;
			gameStates.Clear();
			endGame = true; 
		}
	}

	system("Pause");
	return 0;
}