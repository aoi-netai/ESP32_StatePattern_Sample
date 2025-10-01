#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"

StateID StateA::Update(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    if (loop_counter > 10) {

        loop_counter = 0;

        return StateID::STATE_B;
    }

    return StateID::STATE_A;
}

void StateA::Enter(StateContext& context) {

}

void StateA::Exit(StateContext& context) {

}
