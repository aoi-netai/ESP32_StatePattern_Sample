#ifndef STATECONTEXT_HPP
#define STATECONTEXT_HPP

#include <cstdint>
#include <memory>
#include <optional>
#include "../sample_lib/sample_lib.hpp"

// 使用するインスタンス
struct Instances{

    std::optional<SampleLib> sample_lib;
};

// 状態間で共有する変数
struct StateContext {
    
    uint16_t state_change_count = 0;
    Instances instances;
};

#endif // STATECONTEXT_HPP
