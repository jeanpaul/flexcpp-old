#include "states.ih"

#include <iostream>

// Starting at a state, if it has two edges, and an e-transition reaches an
// accept-state then that set becomes an inheriting accept set
//
set<size_t> States::eClosure(set<size_t> &current, bool &twoEdges,
                                                    bool &inheriting) const
{
    set<size_t> ret;
    ret.insert(0);      // initialize to state 0, which is never inspected

    while (not current.empty())
    {
        size_t next = *current.begin();     // pick a state number
        ret.insert(next);                   // add it to the `ret' set

        State const &nextState = d_state[next];

        if (twoEdges && nextState.accept() != State::NONE)
            inheriting = true;

        if (nextState.type() == State::EMPTY)   // e-transition?
        {
            current.insert(nextState.next1());   // if so, add the 
            current.insert(nextState.next2());   //  next states

            if (nextState.next2() != 0)
                twoEdges = true;
        }
                                            // remove states already in the 
                                            // `ret' set from current
        for (auto iter = ret.begin(), end = ret.end(); iter != end; ++iter)
            current.erase(*iter);
    }

    ret.erase(0);       // erase state 0 again

    return ret;
}
