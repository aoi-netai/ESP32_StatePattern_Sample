/* StateHeaders.cpp
* 
*  ここでは、メインから呼び出す状態遷移の処理と各状態処理の呼び出しを行います
*
*  すべての状態クラスはStateInterfaceを継承しているため、Update()メソッドを持っています
*  そこで、どの状態クラスのUpdate()メソッドを呼び出すかを現在の状態(current_state)によって切り替えるだけで状態遷移が実装できます
*
*  状態の変更は各状態の処理内から、changeState()メソッドを呼び出すことで行います
*  各状態が実行されるとき、privateに書いた変数や構造体などは共有されるため、センサーデータはこのクラスで管理することができます
*  これは、void StateA::update(StateManager& manager)のように、StateManagerの参照を引数にとることで実現しています
*
*  クラスは変数のように直接代入することはできないため、std::unique_ptrを使用して状態オブジェクトを管理します(これは状態クラスのオブジェクトのポインタです)
*  std::unique_ptrを使うことで、このクラス以外からアクセスできなくなるため、想定していない状態遷移を防ぐことができます（ついでに難しいメモリ管理もしてくれます）
*/

#ifndef STATE_MANAGER_HPP
#define STATE_MANAGER_HPP

#include "../State/common/StateInterface.hpp"
#include <memory>
#include <atomic>

struct StateContext{

    // ここに状態間で共有する変数を定義する
    // 例: センサーデータ、タイマー、フラグなど

    uint16_t state_change_count = 0;
};

// 状態管理クラス
class StateManager {

    public:

        // コンストラクタ 初期状態を設定
        StateManager();

        // デストラクタ
        ~StateManager() = default;

        // 初期状態の設定
        void Init(StateID init_state_id);
            
        // メインループ
        void Update();

    private:

        // 状態遷移
        void ChangeState(std::unique_ptr<StateInterface> newState);

        // 状態IDから状態クラスのオブジェクトを生成する関数
        std::unique_ptr<StateInterface> CreateState(StateID state_id);

        // 現在の状態を保持するポインタ
        std::unique_ptr<StateInterface> current_state;

        StateContext* state_context;
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