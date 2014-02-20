#ifndef BASIC_PARENT_SELECTION_HPP
#define BASIC_PARENT_SELECTION_HPP

#include <utility>

#include "basic_individual.hpp"

namespace ea
{

class basic_parent_selection
{
    public:
        virtual ~basic_parent_selection() {}
        virtual individual_pair_vector operator()(const individual_vector&);
        void set_children_multiplier(double children_mult) { children_multiplier_ = children_mult; }
    protected:
        double children_multiplier_;
};

}

#endif
