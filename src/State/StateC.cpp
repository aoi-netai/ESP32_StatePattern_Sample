#include "common/StateHeaders.hpp"

StateResult StateC::update(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    // 10回ループしたら状態をAに変更
    if (loop_counter > 10) {

        loop_counter = 0;
        context.state_change_count++;

        return {true, StateID::STATE_B, StateError::NONE};
    }

    return {false, StateID::STATE_C, StateError::NONE};
}

void StateC::enter(StateContext& context) {
}


void StateC::exit(StateContext& context) {

}
