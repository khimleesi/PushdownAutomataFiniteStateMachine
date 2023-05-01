#pragma once
#include <iostream>
#include <deque>

template <class BaseState>
class FiniteStateMachine {

public:
	FiniteStateMachine();
	~FiniteStateMachine();

public:
	template<typename State, typename... Args>
	void MakePermanentState(Args&&... args);

	template<typename State, typename... Args>
	void MakeTemporaryState(Args&&... args);

public:
	const std::deque<std::unique_ptr<BaseState>>& GetAllStates() const;
	BaseState* CurrentState();
	BaseState* PreviousState();
	void RemoveState();
	bool IsEmpty();
	void Clear();

private:
	std::deque<std::unique_ptr<BaseState>> m_states;
};

/*******************************************************************************************************************
	Default constructor
*******************************************************************************************************************/
template <class BaseState>
FiniteStateMachine<BaseState>::FiniteStateMachine()
{

}


/*******************************************************************************************************************
	Default destructor
*******************************************************************************************************************/
template <class BaseState>
FiniteStateMachine<BaseState>::~FiniteStateMachine()
{

}


/*******************************************************************************************************************
	Wrapper function that adds a permanent state e.g. Main Game
*******************************************************************************************************************/
template <class BaseState>
template <typename State, typename... Args>
void FiniteStateMachine<BaseState>::MakePermanentState(Args&&... args) {
	
	m_states.emplace_back(std::make_unique<State>(std::forward<Args>(args)...));
}


/*******************************************************************************************************************
	Wrapper function that adds a temporary state e.g. Pause
*******************************************************************************************************************/
template <class BaseState>
template <typename State, typename... Args>
void FiniteStateMachine<BaseState>::MakeTemporaryState(Args&&... args) {

	m_states.emplace_front(std::make_unique<State>(std::forward<Args>(args)...));
}


/*******************************************************************************************************************
	Helper function that returns all the states currently in the stack
*******************************************************************************************************************/
template <class BaseState>
const std::deque<std::unique_ptr<BaseState>>& FiniteStateMachine<BaseState>::GetAllStates() const
{
	return m_states;
}


/*******************************************************************************************************************
	Function which returns the state at the front of the deque
*******************************************************************************************************************/
template <class BaseState>
BaseState* FiniteStateMachine<BaseState>::CurrentState()
{
	return m_states.front().get();
}


/*******************************************************************************************************************
	Function which returns the state at the back of the deque
*******************************************************************************************************************/
template <class BaseState>
BaseState* FiniteStateMachine<BaseState>::PreviousState()
{
	return m_states.back().get();
}


/*******************************************************************************************************************
	Function which removes the state at the front of the deque
*******************************************************************************************************************/
template <class BaseState>
void FiniteStateMachine<BaseState>::RemoveState()
{
	m_states.pop_front();
}


/*******************************************************************************************************************
	Function which checks if the states deque is empty
*******************************************************************************************************************/
template <class BaseState>
bool FiniteStateMachine<BaseState>::IsEmpty()
{
	return m_states.empty();
}

/*******************************************************************************************************************
	Function which clears all the states in the stack
*******************************************************************************************************************/
template <class BaseState>
void FiniteStateMachine<BaseState>::Clear()
{
	return m_states.clear();
}