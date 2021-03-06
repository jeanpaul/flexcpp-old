#include "generator.ih"

void Generator::startCondNames(ostream &out) const
{
    key(out);
    out << indent << "INITIAL";

    for (auto it = d_rules.begin(), end = d_rules.end(); it != end; ++it)
    {
        string const &name = (*it).name();      // -> is not defined for 'it'
        if (name != "INITIAL")
            out << ",\n" << 
                    indent << (*it).name();
    }

    out << '\n';
}
