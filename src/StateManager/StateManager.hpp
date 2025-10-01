/* StateHeaders.cpp
*
*  ここでは、状態管理をしています
*  Context構造体のインスタンスをメンバーにもち、状態を実行するときに引数として渡しています
*  各状態は、次の状態を返してくるため、状態が変化した場合は状態を変更する処理もしています
*/

#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include "../State/common/StateInterface.hpp"
#include <memory>
#include <atomic>

#include "../State/common/StateContext.hpp"
#include "../State/common/StateID.hpp"

// 状態管理クラス
class StateManager {

    public:

        // コンストラクタ 初期状態を設定
        StateManager(StateID init_state_id);

        // デストラクタ
        ~StateManager() = default;
            
        // メインループ
        void Update();

    private:

        // 状態遷移
        void ChangeState(std::unique_ptr<StateInterface> newState);

        // 状態IDから状態クラスのオブジェクトを生成する関数
        std::unique_ptr<StateInterface> CreateState(StateID state_id);

        // 現在の状態を保持するポインタ
        std::unique_ptr<StateInterface> current_state;

        // StateContext をオブジェクトとして保持し、各状態処理に参照で渡す
        StateContext state_context;
};

// ループ管理クラス
class LoopManager {

    public: 
        
        LoopManager() = default;
        ~LoopManager() = default;

        // 待機フラグのセット
        void SetWaitFlag(){
            
            wait_flag = true; 
        }

        // 待機フラグのクリア
        void ClearWaitFlag(){

            wait_flag = false;
        }

        // 待機フラグの取得
        bool GetWaitFlag(){ 

            return wait_flag; 
        }

    private:

        bool wait_flag = false;
};

#endif // STATE_MANAGER_HPP