#include <Arduino.h>
#include <memory>
#include "StateManager/StateManager.hpp"
#include "State/common/StateHeaders.hpp"

// 状態管理クラスのインスタンスを作成（初期状態を指定する）
StateManager state_manager;

// ループ管理クラスのインスタンスを作成
LoopManager loop_manager;

// ループ管理用のタイマー
hw_timer_t* timer_10hz = nullptr;

void LoopTimer();

void setup() {

  // タイマー初期化（80Mhzを1Mhzに分周）
  timer_10hz = timerBegin(0, 80, true);

  // タイマーに割り込み関数を設定
  timerAttachInterrupt(timer_10hz, &LoopTimer, true);

  // 1Mhzのカウント * 100000回 = 10hz
  timerAlarmWrite(timer_10hz, 100000, true);

  // タイマーの有効化
  timerAlarmEnable(timer_10hz);

  // 最初の状態の呼び出し
  state_manager.Init(StateID::STATE_A); 
}

// StateManagerの呼び出し
// 呼び出し時に待機フラグが立つため、実際の実行速度はフラグの更新速度 = LoopTimerの更新速度（10hz)
void loop() {

  // 待機フラグの確認
  if (loop_manager.GetWaitFlag() == false) {

    // フラグをセット
    loop_manager.SetWaitFlag();

    // StateManagerの更新
    state_manager.Update();
  }
}

// 10Hzで呼び出されるタイマー割り込み関数
// 高速なIRAM上に配置する
void IRAM_ATTR LoopTimer(){

  // 待機フラグのクリア
  loop_manager.ClearWaitFlag();
}
