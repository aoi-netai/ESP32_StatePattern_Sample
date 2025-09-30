#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"

StateID StateB::Update(StateManager& manager) {
    
    static uint16_t loop_counter = 0;
    loop_counter++;

    if (loop_counter > 10) {

        loop_counter = 0;

    manager.state_change_count++;

        return StateID::STATE_C;
    }

    return StateID::STATE_B;
}

void StateB::Enter(StateManager& manager) {

}
void StateB::Exit(StateManager& manager) {

}
