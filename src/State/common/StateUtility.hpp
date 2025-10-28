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
    ERROR_A,
    ERROR_B,
    ERROR_C,
};

// 状態更新の結果を格納する構造体
struct StateResult{

    bool is_state_changed = false;  
    StateID next_state;
    StateError error;
};
    
#endif // STATE_ID_HPP
