// Generated by Bisonc++ V2.09.04 on Mon, 16 Jan 2012 21:40:37 +0100

#ifndef Parser_h_included
#define Parser_h_included

#include <string>

#include "../utility/utility.h"
#include "../state/state.h"
#include "../block/block.h"

#include <bobcat/arg>

// $insert baseclass
#include "parserbase.h"
// $insert scanner.h
#include "../scanner/scanner.h"

namespace FBB
{
    class Arg;
}

class Options;
class States;
class Rules;

#undef Parser
class Parser: public ParserBase, public DataType
{
    FBB::Arg &d_arg;

    // $insert scannerobject
    Scanner d_scanner;
    std::string const &d_matched;   // text matched at the last lex() call.
    Block   d_block;

    Options &d_options;

    std::string d_expect;
    bool d_printTokens;
    bool d_doError;                 // use the error() function at ERRORs
    bool d_warnCarets;              // carets in a RE
    bool d_warnDollars;             // dollars in a RE
    size_t d_tokenCount;
    bool d_boln;                    // rule starts at boln
    bool d_usesLOP;
    size_t d_parentheses;

    Rules &d_rules;
    States &d_states;

    static int s_ignoreToken;
    static std::string s_lastMsg;

    public:
        Parser(Rules &rules, States &states);
        int parse();

    private:
        spSemUnion eolnDollar();
        void orAction();
        void reset();       // prepare the parser for a new regex 
                            // (resetting tokencount and warning flags)

        spSemUnion boln();
        spSemUnion dollar();
        spSemUnion eofPattern();
        spSemUnion quotes();
        spSemUnion concatenate(spSemUnion &lhs, spSemUnion &rhs);
        spSemUnion lookahead(spSemUnion &left, spSemUnion &right);
        spSemUnion interval(spSemUnion &regex, spSemUnion const &interval);


        void assignBlock();                                 // .ih
        void noActions();                                   // .ih
        spSemUnion alternatives(spSemUnion const &lhs, 
                                spSemUnion const &rhs);     // .ih
        spSemUnion characterClass(spSemUnion &charClass);   // .ih
        spSemUnion dot();                                   // .ih
        spSemUnion escape();                                // .ih
        spSemUnion str();                                   // .ih
        spSemUnion rawText();                               // .ih
        spSemUnion rawText(std::string const &str);         // .ih
        spSemUnion quantifier(spSemUnion const &regex);     // .ih
        spSemUnion unite(spSemUnion const &lhs,             // .ih
                         spSemUnion const &rhs);
        spSemUnion difference(spSemUnion const &lhs,        // .ih
                              spSemUnion const &rhs);
        spSemUnion setElements(size_t skip = 0);            // .ih
        spSemUnion setConcatenate(spSemUnion &lhs,          // .ih
                                  spSemUnion const &rhs);
        spSemUnion setNegate(spSemUnion &lhs);              // .ih
        spSemUnion setNegate(spSemUnion &lhs,               // .ih
                                  spSemUnion const &rhs);

        void addRule(spSemUnion const &rule, bool resetMs = false);
        void addBlockRule(spSemUnion const &rule);

        void setFlags(size_t idx, State::Flag flag);    // called fm lookahead

        void block();
        void error(char const *msg);    // called on (syntax) errors
        int lex();                      // returns the next token from the
                                        // lexical scanner. 
        void print();  

    // support functions for parse():
        void executeAction(int ruleNr);
        void errorRecovery();
        int lookup(bool recovery);
        void nextToken();
        void print__();
};

#endif





