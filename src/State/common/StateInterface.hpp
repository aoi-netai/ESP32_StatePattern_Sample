/* StateInterface.cpp
* 
* 各状態のインターフェース（基底クラス）を定義しています
* ここで定義されている仮想関数をすべての状態クラスで実装する必要があります（純粋仮想関数はすべてをoverrideしないとコンパイルエラーになります）
* 
* これによって、すべての状態クラスに共通の名前や引数を持つメソッドの実装を約束させることができます
*
* もし、特定の状態で処理をまとめるための関数が必要になった場合は、各状態クラス内で追加の定義もできます（これは通常の関数と同じ）
*/


#ifndef INC_STATE_INTERFACE_HPP_
#define INC_STATE_INTERFACE_HPP_

// ステートマネージャの前方宣言
class StateManager;

// ステートのインターフェース（抽象基底クラス）
class StateInterface {
public:

    virtual ~StateInterface() = default;

    // 状態更新用
    virtual void update(StateManager& manager) = 0;

    // 状態に入るときの処理（起動や初期化など）
    virtual void enter(StateManager& manager) {}

    // 状態を出るときの処理（リセットやクリーンアップなど）
    virtual void exit(StateManager& manager) {}

    // 状態名の取得
    virtual const char* getStateName() const = 0;
};

#endif /* INC_STATE_INTERFACE_HPP_ */