#include "InitStateBase.hpp"
#include <Arduino.h>

StateResult InitStateBase::update(StateContext& context) {

    return onUpdate(context);
}

StateError InitStateBase::enter(StateContext& context) {

    Serial.printf("[InitStateBase] Entering State ID: %d\n", static_cast<int>(getStateID()));

    return onEnter(context);
}

StateError InitStateBase::exit(StateContext& context) {

    Serial.printf("[InitStateBase] Exiting State ID: %d\n", static_cast<int>(getStateID()));

    return onExit(context);
}