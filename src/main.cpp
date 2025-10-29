#include <Arduino.h>
#include "StateManager/StateManager.hpp"

// 状態管理クラスのインスタンスを作成（初期状態を指定する）
constexpr unsigned long time_interval = 100000; // 100ms(10Hz)
StateManager state_manager(StateID::STATE_A, time_interval);

void setup() {

  while(!Serial); // シリアルポートの接続を待つ

  Serial.begin(115200);

  printf("[Main] Setup complete. Starting StateManager...\n");

}

void loop() {

    // StateManagerの更新
    state_manager.update();
}