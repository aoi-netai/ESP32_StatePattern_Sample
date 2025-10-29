#include "ProcessStateBase.hpp"
#include <Arduino.h>


StateError ProcessStateBase::enter(StateContext& context) {

    Serial.printf("[ProcessStateBase] Entering State ID: %d\n", static_cast<int>(getStateID()));

    return onEnter(context);
}

StateResult ProcessStateBase::update(StateContext& context) {

    return onUpdate(context);
}

StateError ProcessStateBase::exit(StateContext& context) {

    Serial.printf("[ProcessStateBase] Exiting State ID: %d\n", static_cast<int>(getStateID()));

    return onExit(context);
}