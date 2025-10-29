#ifndef STATE_MANAGER_UTILITY_HPP
#define STATE_MANAGER_UTILITY_HPP

#include <cstdint>

// StateManager の状態を表す enum
enum class StateManagerStatus : uint8_t {

    // 正常系
    SUCCESS = 0,                           // ✅ 正常に処理完了
    WAIT_NEXT_LOOP = 1,                    // ⏸️ 次のループまで待機中
    
    // 復旧可能な問題（処理は続行）
    WARNING_STATE_NOT_CHANGED = 10,        // ⚠️ 状態遷移が発生しなかった
    WARNING_INVALID_STATE = 11,            // ⚠️ 無効な状態ID
    
    // 致命的なエラー（システム停止すべき）
    CRITICAL_NULL_STATE = 200,             // 🔴 current_state が nullptr
    CRITICAL_STATE_CREATION_FAILED = 201,  // 🔴 状態生成に失敗
    CRITICAL_ENTER_FAILED = 202,           // 🔴 enter() が失敗
    CRITICAL_EXIT_FAILED = 203,            // 🔴 exit() が失敗
};

// ステータスの重大度を判定するヘルパー関数
inline bool isCritical(StateManagerStatus status) {

    return static_cast<uint8_t>(status) >= 200;
}

inline bool isWarning(StateManagerStatus status) {

    uint8_t code = static_cast<uint8_t>(status);
    return code >= 10 && code < 200;
}

inline bool isSuccess(StateManagerStatus status) {

    uint8_t code = static_cast<uint8_t>(status);
    return code < 10;
}

// ステータスを文字列で取得するヘルパー関数
inline const char* StateManagerStatusToString(StateManagerStatus status) {

    switch (status) {

        case StateManagerStatus::SUCCESS:
            return "SUCCESS";

        case StateManagerStatus::WAIT_NEXT_LOOP:
            return "WAIT_NEXT_LOOP";

        case StateManagerStatus::WARNING_STATE_NOT_CHANGED:
            return "WARNING_STATE_NOT_CHANGED";

        case StateManagerStatus::WARNING_INVALID_STATE:
            return "WARNING_INVALID_STATE";

        case StateManagerStatus::CRITICAL_NULL_STATE:
            return "CRITICAL_NULL_STATE";

        case StateManagerStatus::CRITICAL_STATE_CREATION_FAILED:
            return "CRITICAL_STATE_CREATION_FAILED";

        case StateManagerStatus::CRITICAL_ENTER_FAILED:
            return "CRITICAL_ENTER_FAILED";

        case StateManagerStatus::CRITICAL_EXIT_FAILED:
            return "CRITICAL_EXIT_FAILED";

        default:
            return "UNKNOWN";
    }
}

#endif // STATE_MANAGER_UTILITY_HPP