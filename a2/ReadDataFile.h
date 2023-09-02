#include "pcb.h"
#include <string>
#include <deque>

class ReadDataFile{
    public:
        static std::deque<pcb> ReadThisDataFile(const std::string& filename);
        static osp2023::id_type toIdType(const std::string& num);
        static osp2023::time_type toTimeType(const std::string& num);

};