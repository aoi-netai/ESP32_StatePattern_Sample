/* StateHeaders.cpp
*
*  ここでは、状態管理をしています
*  Context構造体のインスタンスをメンバーにもち、状態を実行するときに引数として渡しています
*  各状態は、次の状態を返してくるため、状態が変化した場合は状態を変更する処理もしています
*/

#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include <memory>
#include "../State/common/StateInterface/StateInterface.hpp"
#include "../State/common/StateContext.hpp"
#include "../State/common/StateUtility.hpp"
#include "LoopManager.hpp"
#include "StateManagerUtility.hpp"

// 状態管理クラス
class StateManager {

    public:

        // コンストラクタ 初期状態を設定
        StateManager(StateID init_state_id, uint32_t loop_interval_us = 100000);

        // デストラクタ
        ~StateManager() = default;
            
        // メインループ
        StateManagerStatus update();

    private:

        // 状態遷移
        void changeState(std::unique_ptr<StateInterface> new_state);

        // 状態IDから状態クラスのオブジェクトを生成する関数
        std::unique_ptr<StateInterface> createState(StateID state_id);

        // 現在の状態を保持するポインタ
        std::unique_ptr<StateInterface> current_state;

        // 状態間で共有する構造体
        StateContext state_context;

        // ループ管理クラス
        LoopManager loop_manager; 
};

#endif // STATE_MANAGER_HPP