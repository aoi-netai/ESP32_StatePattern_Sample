#ifndef STATE_ID_HPP
#define STATE_ID_HPP

#include <cstdint>

// 状態IDの定義
enum class StateID : uint8_t {
    STATE_A,
    STATE_B,
    STATE_C,
};

// 状態エラーの定義
enum class StateError : uint8_t {

    NONE = 0,

    // 10:199 次のループで再処理を行うべき変化（初期の通信待ち、センサーデータの取得）

    // 200:255 処理を停止すべきエラー(Nullptr参照、センサー異常など)
    SOME_CRITICAL_ERROR = 200,
    SAMPLE_LIB_NULLPTR_ERROR = 201,
};

enum class StateChange : uint8_t {

    NO_STATE_CHANGE = 0,
    STATE_CHANGE = 1,
};

// 状態更新の結果を格納する構造体
struct StateResult {

    StateChange state_change = StateChange::NO_STATE_CHANGE;
    StateID next_state;
    StateError error;
};
    
#endif // STATE_ID_HPP
