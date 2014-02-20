#ifndef CSV_WRITER_HPP
#define CSV_WRITER_HPP

#include <fstream>

namespace ea
{

class csv_writer
{
    public:
        csv_writer(const std::string& out) : out_file(out + ".csv") {}
        ~csv_writer() { out_file.close(); }
        void write(std::size_t, ...);
    private:
        std::ofstream out_file;
};

}

#endif
