# 状態遷移パターンの試作

- 一般的な`StatePattern`のデモコードです
- ESP32 WROOM32用のプロジェクトとして作成しましたが、コード自体は様々なマイコンで使用できるはずです
- タイマー割り込みを使った一定周期での実行に対応しています
- 詳細な処理の流れと変数の扱いの説明を書きました

## ループの定期実行について

- `void loop`が定期的に実行されるように、100msごとに`stateManager.update();`の更新許可を出しています
- 待機フラグが立っている場合は、`loop`で実行する処理がないため、待機フラグの更新に最速で反応することができます
- フラグのセット、リセット、確認用の機能を持つクラス`LoopManager`を使用しています

```cpp
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
```
## タイマー割り込みの実装について
- フラグのクリアの実行は、ESP32のタイマー割り込み機能を用いています
- タイマークロックは80Mhzであるため、分周を用いて1Mhzになるように調整し、100000回のカウントで100msを測定しています

```cpp
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
```

## 処理の流れについて

#### プログラムスタート(main.cpp)

1. `StateManager` のオブジェクト `stateManager` を作成

2. 最初の状態の`enter`が呼び出される

#### void setup()

3. メインループ管理用のタイマーの設定と起動

#### void loop()

4.  `stateManager.update()`（`StateManager.cpp`）が呼ばれる

5. `StateManager::update()`（`StateManager.cpp`）から現在の状態である `StateA::update()`（`StateA.cpp`）が呼ばれる

**更新タイミングのループ**

6. 5の処理が10回実行(1秒経過)されると、`StateA::update()`（`StateA.cpp`） から `manager.changeState()`（`StateManager.cpp`） が呼ばれる (`StateA::update()`のコードによって条件の変更ができる）
7. `manager.changeState()`（`StateManager.cpp`）で`StateA::exit()`が呼ばれる（今回は空のメソッド）

8. `manager.changeState()`（`StateManager.cpp`）の`currentState`が新しい状態`StateB`に更新

9. `manager.changeState()`（`StateManager.cpp`）で`StateB::enter()`が呼ばれる（今回は空のメソッド）

10. `manager.changeState()`（`StateManager.cpp`）でprintln()が実行（シリアルモニタ用の出力）

**更新タイミングのループが終了**

11. `stateManager.update()` が呼ばれる

12. `StateManager::update()`（`StateManager.cpp`）から現在の状態である `StateB::update()`（`StateB.cpp`）が呼ばれる

13. 以下繰り返し(StateA -> StateB -> StateCの順番に遷移していく)

## 各状態クラスでの変数の扱いについて

**全体で共有したい変数について**

- `FlightManager.hpp`の`public`で定義することができます
- 可読性向上のため、クラスや構造体のインスタンスを持つことが望ましいです
- 使用する際には`FlightManager`のポインタを使用してください(`manager.count`のように呼び出すことができます)

**状態クラス内で共有したい変数について**

- `FlightHeaders`の`private`で定義することができます
- `enter()`で初期化、`update()`で使用、`exit()`で破棄することで、状態遷移ごとにリセットすることもできます

**状態クラス内のメソッドのみで使う変数について**

- `update()`などのメソッド内で通常通り宣言し利用してください
- 前回の値など、`update()`の呼び出しごとにリセットされたくないものは、`FlightHeaders`の`private`で定義してください
