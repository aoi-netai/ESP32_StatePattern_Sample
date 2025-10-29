#include "common/StateHeaders.hpp"
#include <Arduino.h>

StateResult StateC::onUpdate(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    printf("[StateC] Process\n");

    if(loop_counter > 2) {

        loop_counter = 0;
        return {StateChange::STATE_CHANGE, StateID::STATE_B, StateError::NONE};
    }

    return {StateChange::NO_STATE_CHANGE, StateID::STATE_C, StateError::NONE};
}

StateError StateC::onEnter(StateContext& context) {

    printf("[StateC] Entered State C\n");

    return StateError::NONE;
}

StateError StateC::onExit(StateContext& context) {

    printf("[StateC] Exited State C\n");

    return StateError::NONE;
}
