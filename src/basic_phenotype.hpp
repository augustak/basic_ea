#ifndef BASIC_PHENOTYPE_HPP
#define BASIC_PHENOTYPE_HPP

#include <vector>

namespace ea
{

class basic_phenotype
{
    public:
        // typedefs
        typedef std::vector<unsigned int>::iterator iterator;
        typedef std::vector<unsigned int>::const_iterator const_iterator;
        // constructors
        basic_phenotype(const std::vector<unsigned int>&);
        virtual ~basic_phenotype() {}
        // iterators
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        // operators
        const unsigned int operator[](const std::size_t pos) const { return phenome_[pos]; };
        const std::size_t size() const { return phenome_.size(); }
    private:
        std::vector<unsigned int> phenome_;
};

typedef std::pair<basic_phenotype*, basic_phenotype*> phenotype_pair;
typedef std::vector<phenotype_pair> phenotype_pair_vector;
typedef std::vector<basic_phenotype*> phenotype_vector;

}

#endif
