#ifndef PROCESS_STATE_BASE_HPP
#define PROCESS_STATE_BASE_HPP

#include "State/common/StateInterface/StateInterface.hpp"

class ProcessStateBase : public StateInterface {

    private:

        StateResult update(StateContext& context) override;
        StateError enter(StateContext& context) override;
        StateError exit(StateContext& context) override;

    protected:

        virtual StateError onEnter(StateContext& context){ return StateError::NONE; };
        virtual StateResult onUpdate(StateContext& context) = 0;
        virtual StateError onExit(StateContext& context){ return StateError::NONE; };
        virtual StateID getStateID() const = 0;
};

#endif // PROCESS_STATE_BASE_HPP