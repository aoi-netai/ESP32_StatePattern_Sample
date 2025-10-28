#include <Arduino.h>
#include "StateManager/StateManager.hpp"

// 状態管理クラスのインスタンスを作成（初期状態を指定する）
StateManager state_manager(StateID::STATE_A, 100000);

void setup() {


}

void loop() {

    // StateManagerの更新
    state_manager.update();
}