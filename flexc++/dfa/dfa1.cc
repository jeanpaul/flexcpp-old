#include "dfa.ih"

DFA::DFA(Ranges &ranges, Rules &rules, States &states)
:
    d_ranges(&ranges),
    d_rules(&rules),
    d_states(&states),
    d_stateSet(1),
    d_verbose(Arg::instance().option('V'))
{}
