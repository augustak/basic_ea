#ifndef CSV_WRITER_HPP
#define CSV_WRITER_HPP

#include <fstream>

namespace ea
{

class csv_writer
{
    public:
        csv_writer(const std::string&);
        ~csv_writer() { out_file.close(); }
        void write_title(std::size_t, ...);
        void write(std::size_t, ...);
    private:
        std::ofstream out_file;
};

}

#endif
