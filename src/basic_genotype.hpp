#ifndef BASIC_GENOTYPE_HPP
#define BASIC_GENOTYPE_HPP

#include <vector>

namespace ea
{

class basic_genotype
{
    public:
        // typedefs
        typedef std::vector<bool>::iterator iterator;
        typedef std::vector<bool>::const_iterator const_iterator;
        // constructors
        basic_genotype(const std::vector<bool>&);
        virtual ~basic_genotype() {}
        // iterators
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        // operators
        std::vector<bool>::reference operator[](std::size_t pos) { return genome_[pos]; }
        const bool operator[](const std::size_t pos) const { return genome_[pos]; }
        const std::size_t size() const { return genome_.size(); }
    private:
        // internal data
        std::vector<bool> genome_;
};

basic_genotype* random_basic_genotype(std::size_t);

typedef std::pair<basic_genotype*, basic_genotype*> genotype_pair;
typedef std::vector<genotype_pair> genotype_pair_vector;
typedef std::vector<basic_genotype*> genotype_vector;

}
#endif
