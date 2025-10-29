#include "common/StateHeaders.hpp"
#include <Arduino.h>

StateResult StateC::onUpdate(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    // 50回ループしたら状態をBに変更
    if (loop_counter > 50) {

        loop_counter = 0;
        context.state_change_count++;

        printf("[StateC] Current_Loop: %d\n", loop_counter);

        return {StateChange::STATE_CHANGE, StateID::STATE_B, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_C, StateError::NONE};
}

StateError StateC::onEnter(StateContext& context) {

    Serial.println("[StateC] Entered State C");

    return StateError::NONE;
}

StateError StateC::onExit(StateContext& context) {

    Serial.println("[StateC] Exited State C");

    return StateError::NONE;
}
