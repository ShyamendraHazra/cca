#ifndef LOGS_H
#define LOGS_H

namespace Logs {

    typedef enum {

    DEBUG = 0,
    INFO = 1,
    WARNING = 2,
    ERROR = 3
    } log_level; 

    class Log {
        
        private:
            log_level level;
        public:
            void log();
    };

}

#endif