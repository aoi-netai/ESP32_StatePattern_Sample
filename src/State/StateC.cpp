#include "common/StateHeaders.hpp"
#include "../StateManager/StateManager.hpp"


void StateC::Update(StateManager& manager) {
    static uint16_t loop_counter = 0;
    loop_counter++;

    if (loop_counter > 10) {

        loop_counter = 0;
        
        manager.state_change_count++;
        manager.ChangeState(std::make_unique<StateA>());

        return;
    }
}

void StateC::Enter(StateManager& manager) {
}


void StateC::Exit(StateManager& manager) {

}
