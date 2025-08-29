#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"

void StateB::Update(StateManager& manager) {
    static uint16_t loop_counter = 0;
    loop_counter++;

    if (loop_counter > 10) {

        loop_counter = 0;

    manager.state_change_count++;
    manager.ChangeState(std::make_unique<StateC>());

        return;
    }
}

void StateB::Enter(StateManager& manager) {

}
void StateB::Exit(StateManager& manager) {

}
