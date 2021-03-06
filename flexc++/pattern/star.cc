#include "pattern.ih"

Pattern Pattern::star(States &states, Pattern const &pattern)
{
    States::Pair pair = states.next2();     // create new Start/Final states

        // pattern's end connects to pattern begin and the new FINAL state.
    states[pattern.end()] =                 
                State::factory(State::EMPTY, pattern.begin(), pair.second);
    
        // new Start state connects to pattern begin + end
    states[pair.first] = State::factory(State::EMPTY, 
                                            pattern.begin(), pair.second);

    Pattern ret(pair);

    return ret;
}



