#include "common/StateHeaders.hpp"
#include <Arduino.h>

StateResult StateB::onUpdate(StateContext& context) {
    
    static uint16_t loop_counter = 0;
    loop_counter++;

    context.state_change_count++;
    
    // SampleLibのデータを取得して確認する
    context.instances.sample_lib->getData();
    printf("[StateB] SampleLib Data: %d\n", context.instances.sample_lib->getData());

    if(loop_counter > 2) {

        loop_counter = 0;
        return {StateChange::STATE_CHANGE, StateID::STATE_C, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_B, StateError::NONE};
}

StateError StateB::onEnter(StateContext& context) {

    printf("[StateB] Entered State B\n");

    return StateError::NONE;
}

StateError StateB::onExit(StateContext& context) {

    printf("[StateB] Exited State B\n");

    return StateError::NONE;
}
