#include "charclass.ih"

CharClass CharClass::elements(string const &chars, size_t skip)
{
    CharClass ret(skip == 0 ? chars : chars.substr(skip));

//cout << "CharClass::elements: " << ret << '\n';

    return ret;
}
