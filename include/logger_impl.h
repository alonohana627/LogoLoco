#ifndef LOGOLOCO_LOGGER_IMPL_H
#define LOGOLOCO_LOGGER_IMPL_H

#include <sinks/sink_trait.h>
#include <iostream>

namespace LogoLoco {

template<typename... Sinks> requires VariadicSinks<Sinks...>
class Logger {
public:
    constexpr explicit Logger(Sinks... sinks) : sinks_(std::make_tuple(sinks...)) {}
    ~Logger() = default;

    void log(const std::string &message) {
        const std::lock_guard<std::mutex> lockThis(_mutex);

        std::apply([message](auto &&... sink) {
            (sink.write(message), ...);
        }, sinks_);
    }

private:
    mutable std::mutex _mutex;
    std::tuple<Sinks...> sinks_;
};

}

#endif
