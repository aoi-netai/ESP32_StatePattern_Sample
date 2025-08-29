#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"

void StateB::update(StateManager& manager) {
    static uint16_t loopCounter = 0;
    loopCounter++;

    if(loopCounter > 10){

        loopCounter = 0;

        manager.state_change_count ++;
        manager.changeState(std::make_unique<StateC>());

        return;
    }
}

void StateB::enter(StateManager& manager) {


}
void StateB::exit(StateManager& manager) {


}
