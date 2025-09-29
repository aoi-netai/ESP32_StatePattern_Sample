#include "StateManager.hpp"
#include "../State/common/StateHeaders.hpp"

#include <Arduino.h>
#include <memory>

// コンストラクタ
StateManager::StateManager() {

    
}

void StateManager::Init(std::unique_ptr<StateInterface> initialState) {

    // 移入された状態を current_state に設定
    current_state = std::move(initialState);

    // enter を呼ぶ
    if (current_state) {
        current_state->Enter(*this);
    }
}

// 状態遷移
void StateManager::ChangeState(std::unique_ptr<StateInterface> new_state) {

    // 現在の状態の終了処理（exit関数の呼び出し）
    if (current_state) {

        current_state->Exit(*this);
    }

    // 新しい状態クラスのオブジェクトのポインタを代入
    current_state = std::move(new_state);

    // 新しい状態の開始処理（enter関数の呼び出し）
    if (current_state) {

        current_state->Enter(*this);

        // 状態遷移メッセージの出力(デバッグ用)
        // 状態遷移カウントと遷移先の状態を表示
        printf("[StateManager] StateChange[%-4u]: %s\n", state_change_count, current_state->GetStateName());
    }
}

// メインループの更新処理
void StateManager::Update() {

    if (current_state) {

        // 現在状態の更新処理
        current_state->Update(*this);
    }
}