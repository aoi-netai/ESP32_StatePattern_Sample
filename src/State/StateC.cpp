#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"


StateID StateC::Update(StateManager& manager) {
    static uint16_t loop_counter = 0;
    loop_counter++;

    if (loop_counter > 10) {

        loop_counter = 0;
        manager.state_change_count++;

        return StateID::STATE_A;
    }

    return StateID::STATE_C;
}

void StateC::Enter(StateManager& manager) {
}


void StateC::Exit(StateManager& manager) {

}
