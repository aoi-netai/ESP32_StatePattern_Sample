#include "common/StateHeaders.hpp"

StateResult StateB::update(StateContext& context) {
    
    static uint16_t loop_counter = 0;
    loop_counter++;

    // 10回ループしたら状態をCに変更
    if (loop_counter > 10) {

        loop_counter = 0;
        context.state_change_count++;

        return {true, StateID::STATE_C, StateError::NONE};
    }

    return {false, StateID::STATE_B, StateError::NONE};
}

void StateB::enter(StateContext& context) {

}
void StateB::exit(StateContext& context) {

}
