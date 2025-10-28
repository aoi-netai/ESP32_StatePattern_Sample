#include "common/StateHeaders.hpp"

StateResult StateA::update(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    // 10回ループしたら状態をBに変更
    if (loop_counter > 10) {

        loop_counter = 0;

        return {true, StateID::STATE_B, StateError::NONE};
    }

    return {false, StateID::STATE_A, StateError::NONE};
}

void StateA::enter(StateContext& context) {

}

void StateA::exit(StateContext& context) {

}
