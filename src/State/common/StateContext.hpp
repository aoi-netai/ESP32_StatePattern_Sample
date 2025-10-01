#ifndef STATECONTEXT_HPP
#define STATECONTEXT_HPP

#include <cstdint>

// 状態間で共有する変数
struct StateContext {
    
    uint16_t state_change_count = 0;
};

#endif // STATECONTEXT_HPP
