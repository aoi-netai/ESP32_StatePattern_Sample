#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"

void StateA::Update(StateManager& manager) {
    static uint16_t loop_counter = 0;
    loop_counter++;

    if (loop_counter > 10) {

        loop_counter = 0;

    manager.state_change_count++;
    manager.ChangeState(std::make_unique<StateB>());

        return;
    }
}

void StateA::Enter(StateManager& manager) {

}

void StateA::Exit(StateManager& manager) {

}
