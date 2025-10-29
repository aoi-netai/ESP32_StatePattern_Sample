#include "common/StateHeaders.hpp"
#include <Arduino.h>

StateResult StateB::onUpdate(StateContext& context) {
    
    static uint16_t loop_counter = 0;
    loop_counter++;

    // 5回ループしたら状態をCに変更
    if (loop_counter > 5) {

        loop_counter = 0;
        context.state_change_count++;
        
        // SampleLibのデータを取得して確認する
        context.instances.sample_lib->getData();
        printf("[StateB] Current_Loop: %d, SampleLib Data: %d\n", loop_counter, context.instances.sample_lib->getData());

        return {StateChange::STATE_CHANGE, StateID::STATE_C, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_B, StateError::NONE};
}

StateError StateB::onEnter(StateContext& context) {

    Serial.println("[StateB] Entered State B");

    return StateError::NONE;
}

StateError StateB::onExit(StateContext& context) {

    Serial.println("[StateB] Exited State B");

    return StateError::NONE;
}
