#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"

StateID StateA::Update(StateManager& manager) {
    static uint16_t loop_counter = 0;
    loop_counter++;

    if (loop_counter > 10) {

        loop_counter = 0;

        return StateID::STATE_B;
    }
    
    return StateID::STATE_A;
}

void StateA::Enter(StateManager& manager) {

}

void StateA::Exit(StateManager& manager) {

}
