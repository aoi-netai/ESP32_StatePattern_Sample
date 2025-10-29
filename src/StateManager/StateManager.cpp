#include "StateManager.hpp"
#include "../State/common/StateHeaders.hpp"
#include <Arduino.h>

// コンストラクタ
StateManager::StateManager(StateID init_state_id, uint32_t loop_interval_us)
	: loop_manager(loop_interval_us) {

	// 移入された状態を current_state に設定
	current_state = createState(init_state_id);

	// enter を呼ぶ
	if (current_state) {

		current_state->enter(state_context);
	}

}
// 状態遷移
void StateManager::changeState(std::unique_ptr<StateInterface> new_state) {

	// 現在の状態の終了処理（exit関数の呼び出し）
	if (current_state) {

		current_state->exit(state_context);
	}

	// 新しい状態クラスのオブジェクトのポインタを代入
	current_state = std::move(new_state);

	// 新しい状態の開始処理（enter関数の呼び出し）
	if (current_state) {

		current_state->enter(state_context);

		// 状態遷移メッセージの出力(デバッグ用)
		// 状態遷移カウントと遷移先の状態を表示
		printf("[StateManager] StateChange[%d]: %d\n", state_context.state_change_count, static_cast<int>(current_state->getStateID()));
	}
}

// メインループの更新処理
void StateManager::update() {

	// ポインタが無効な場合は処理しない
	if(!current_state) {

		return;
	}

	// 次ループまでの待機が必要な場合はスキップ
	if(loop_manager.isWaitNextLoop()) {

		return;
	}

	// 現在状態の更新処理
	StateResult result = current_state->update(state_context);

	// 状態遷移が発生した場合
	if (result.state_change == StateChange::STATE_CHANGE) {

		// 状態を変更
		changeState(createState(result.next_state));
	}
}

// 状態IDから状態クラスのオブジェクトを生成
std::unique_ptr<StateInterface> StateManager::createState(StateID state_id) {

	switch (state_id) { 

		case StateID::STATE_A:
			return std::make_unique<StateA>();

		case StateID::STATE_B:
			return std::make_unique<StateB>();

		case StateID::STATE_C:
			return std::make_unique<StateC>();

		default:
			return nullptr;
	}
}