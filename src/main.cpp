#include <Arduino.h>
#include <memory>
#include "StateManager/StateManager.hpp"
#include "State/common/StateHeaders.hpp"

// 状態管理クラスのインスタンスを作成（初期状態を指定する）
StateManager stateManager(std::make_unique<StateA>());

// ループ管理クラスのインスタンスを作成
LoopManager loopManager;

// ループ管理用のタイマー
hw_timer_t* timer10Hz = nullptr;

void LoopTimer();

void setup() {

  // タイマー初期化（80Mhzを1Mhzに分周）
  timer10Hz = timerBegin(0, 80, true);

  // タイマーに割り込み関数を設定
  timerAttachInterrupt(timer10Hz, &LoopTimer, true);

  // 1Mhzのカウント * 100000回 = 10hz
  timerAlarmWrite(timer10Hz, 100000, true);

  // タイマーの有効化
  timerAlarmEnable(timer10Hz);
}

// StateManagerの呼び出し
// 呼び出し時に待機フラグが立つため、実際の実行速度はフラグの更新速度 = LoopTimerの更新速度（10hz)
void loop() {

  // 待機フラグの確認
  if(loopManager.GetWaitFlag() == false){

    // フラグをセット
    loopManager.SetWaitFlag();

    // StateManagerの更新
    stateManager.update();
  }
}

// 10Hzで呼び出されるタイマー割り込み関数
void LoopTimer(){

  // 待機フラグのクリア
  loopManager.ClearWaitFlag();
}
