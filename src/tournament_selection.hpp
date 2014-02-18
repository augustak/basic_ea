#ifndef TOURNAMENT_SELECTION_HPP
#define TOURNAMENT_SELECTION_HPP

#include "basic_individual.hpp"
#include "basic_parent_selection.hpp"

namespace ea
{

class tournament_selection : public basic_parent_selection
{
    public:
        virtual individual_pair_vector operator()(const individual_vector&);
};

}

#endif
