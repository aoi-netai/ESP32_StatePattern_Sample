#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"

void StateA::update(StateManager& manager) {
    static uint16_t loopCounter = 0;
    loopCounter++;

    if(loopCounter > 10){

        loopCounter = 0;

        manager.state_change_count ++;
        manager.changeState(std::make_unique<StateB>());

        return;
    }
}

void StateA::enter(StateManager& manager) {


}

void StateA::exit(StateManager& manager) {


}
