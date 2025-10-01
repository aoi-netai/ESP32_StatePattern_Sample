#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"

StateID StateB::Update(StateContext& context) {
    
    static uint16_t loop_counter = 0;
    loop_counter++;

    // 10回ループしたら状態をCに変更
    if (loop_counter > 10) {

        loop_counter = 0;
        context.state_change_count++;

        return StateID::STATE_C;
    }

    return StateID::STATE_B;
}

void StateB::Enter(StateContext& context) {

}
void StateB::Exit(StateContext& context) {

}
