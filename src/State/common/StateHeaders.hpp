/* StateHeaders.hpp
* 
*  各状態のヘッダーファイルをまとめたもの
*  通常はStateA.hpp/StateA.cppの2つを作るが、StateA.hppは短いので、StateAからStateCのヘッダーをここでまとめて宣言している
*
*  StateInterface.hppで作成した純粋仮想関数をすべての状態クラスで実装する必要があります
*  また、各クラスごとに追加のメンバー関数やメンバー変数が必要な場合は、各クラス内で追加の定義を行うことができます
*
*  状態を追加するときは、すでにある状態をコピペして、名前の変更と必要な場合は関数の追加をするだけで済みます 
*
*  GetStateName()の実装は、名前(ID)を返すだけなのでこのヘッダー内で行っています
*/


#ifndef STATEHEADERS_HPP
#define STATEHEADERS_HPP

#include "StateInterface/StateInterface.hpp"
#include "StateUtility.hpp"
#include "StateBase/InitStateBase.hpp"
#include "StateBase/ProcessStateBase.hpp"

#include "../sample_lib/sample_lib.hpp"

class StateA : public InitStateBase {

    protected:
        StateResult onUpdate(StateContext& context) override;
        StateError onEnter(StateContext& context) override;
        StateError onExit(StateContext& context) override;
        StateID getStateID() const override { return StateID::STATE_A; }
};

class StateB : public ProcessStateBase {

    protected:
        StateResult onUpdate(StateContext& context) override;
        StateError onEnter(StateContext& context) override;
        StateError onExit(StateContext& context) override;
        StateID getStateID() const override { return StateID::STATE_B; }
};

class StateC : public ProcessStateBase {

    protected:
        StateResult onUpdate(StateContext& context) override;
        StateError onEnter(StateContext& context) override;
        StateError onExit(StateContext& context) override;
        StateID getStateID() const override { return StateID::STATE_C; }
};

#endif // STATEHEADERS_HPP