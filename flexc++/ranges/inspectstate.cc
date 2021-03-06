#include "ranges.ih"

void Ranges::inspectState(State const &state)
{
    size_t type = state.type();
    
    if (type < State::UNDETERMINED__)
        add(type);
    else if (type == State::CHARSET)
        add(state.data().str());
}

