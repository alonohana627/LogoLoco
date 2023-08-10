#ifndef LOGOLOCO_SEVERITY_H
#define LOGOLOCO_SEVERITY_H

namespace LogoLoco{

enum class Severity{
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL,
};

enum class MessageStatus{
    NOTE,
    SUCCESS,
    PROGRESS,
    FAILURE,
};

}

#endif
