#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"


StateID StateC::Update(StateContext& context) {
    static uint16_t loop_counter = 0;
    loop_counter++;

    if (loop_counter > 10) {

        loop_counter = 0;
    context.state_change_count++;

        return StateID::STATE_A;
    }

    return StateID::STATE_C;
}

void StateC::Enter(StateContext& context) {
}


void StateC::Exit(StateContext& context) {

}
