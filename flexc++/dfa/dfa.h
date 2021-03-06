#ifndef INCLUDED_DFA_
#define INCLUDED_DFA_

#include <iosfwd>
#include <vector>
#include <string>
#include <set>

class Rules;
class States;

#include "../dfarow/dfarow.h"

class DFA
{
    friend std::ostream &operator<<(std::ostream & out, DFA const &dfa);

    typedef std::set<size_t> StateSet;

    Ranges *d_ranges;
    Rules *d_rules;
    States *d_states;

    std::vector<DFARow> d_row;
    std::vector<StateSet> d_stateSet;    
    bool d_verbose;
    bool d_sawACCEPT;           // used by visitTailCount

    size_t d_rule;              // used when computing TailCount values 

    public:
        DFA() = default;        // only used for vector-resizing operations

        DFA(Ranges &ranges, Rules &d_rules, States &states);

        void build(std::string const &name, 
                   std::vector<size_t> const &active);

        std::vector<DFARow>::const_iterator begin() const;
        std::vector<DFARow>::const_iterator end() const;

        size_t size() const;

    private:
        void keepViableTailCounts();

        void keepUniqueRows();
        void inspectRows(std::vector<size_t> &unique);
        void shrinkDFA(std::vector<size_t> &unique);


        size_t available(DFARow const &nextRow);

        void computeTailCounts();
        void visitTailCount(TailCount &tailCount);

        void determineTailCount(TailCount &tailCount, size_t thisRow,
                                      TailCount *fmTailCount, size_t fmRow);

        bool setTailCount(TailCount &tailCount, size_t thisRow, 
                         TailCount *fmTailCount, size_t fmRow);
        bool setIncTailCount(TailCount::Type type, TailCount &thisTailCount);
        bool setInitTailCount(TailCount::Type type, TailCount &thisTailCount);
        bool setNextTailCount(TailCount::Type type,
                            TailCount &thisTailCount, size_t thisRow,
                            TailCount &fmTailCount, size_t fmRow);
        void transitTailCount(DFARow::MapValue const &rangeToRow, 
                    TailCount *fmTailCount, size_t fmRow);
};

inline std::vector<DFARow>::const_iterator DFA::begin() const
{
    return d_row.begin();
}

inline std::vector<DFARow>::const_iterator DFA::end() const
{
    return d_row.end();
}

inline size_t DFA::size() const
{
    return d_row.size();
}

//        void mergeFinalSet();

#endif

