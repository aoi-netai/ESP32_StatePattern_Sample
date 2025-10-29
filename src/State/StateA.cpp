#include "common/StateHeaders.hpp"
#include <Arduino.h>
#include <memory>

StateResult StateA::onUpdate(StateContext& context) {

    static uint16_t loop_counter = 0;
    loop_counter++;

    // SampleLibのインスタンスを生成してcontextに保存
    context.instances.sample_lib.emplace(42);

    // インスタンスの生成を確認する
    if(!context.instances.sample_lib.has_value()) {

        return {StateChange::NO_STATE_CHANGE, StateID::STATE_A, StateError::SAMPLE_LIB_NULLPTR_ERROR};
    }

    // 処理を1回したら状態をBに変更
    return {StateChange::STATE_CHANGE, StateID::STATE_B, StateError::NONE};
}

StateError StateA::onEnter(StateContext& context) {

    printf("[StateA] Entered State A\n");

    return StateError::NONE;
}

StateError StateA::onExit(StateContext& context) {

    printf("[StateA] Exited State A\n");

    return StateError::NONE;
}