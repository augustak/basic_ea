#ifndef CSV_WRITER_HPP
#define CSV_WRITER_HPP

#include <fstream>
#include <vector>

namespace ea
{

class data
{
    public:
        data(double a, double s, double m) : avg(a), std(s), max(m) {}
        double avg;
        double std;
        double max;
};

extern std::vector<std::vector<data>> csv_data;

class csv_writer
{
    public:
        csv_writer(const std::string&);
        ~csv_writer();
        void write_title(std::size_t, ...);
        void write(std::size_t, ...);
    private:
        std::ofstream out_file;
        std::vector<data> datas;
};

}

#endif
