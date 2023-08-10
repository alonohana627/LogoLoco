#ifndef LOGOLOCO_CONSOLE_SINK_H
#define LOGOLOCO_CONSOLE_SINK_H

#include <sinks/sink_trait.h>
#include <mutex>

namespace LogoLoco {

class ConsoleSink {
public:
    explicit ConsoleSink() : outputStream(std::make_shared<std::ostream>(std::cout.rdbuf())) {}
    ~ConsoleSink() = default;

    ConsoleSink(const ConsoleSink &other) {
        const std::lock_guard<std::mutex> lock(other.mutex);
        outputStream = other.outputStream;
    }

    ConsoleSink(ConsoleSink &&other) noexcept {
        const std::lock_guard<std::mutex> lock(other.mutex);
        outputStream = std::move(other.outputStream);
    }

    // Operators
    ConsoleSink &operator=(const ConsoleSink &other) {
        if (this == &other) {
            return *this;
        }

        std::lock(mutex, other.mutex);
        const std::lock_guard<std::mutex> lockThis(mutex, std::adopt_lock);
        const std::lock_guard<std::mutex> lockOther(other.mutex, std::adopt_lock);

        outputStream = other.outputStream;

        return *this;
    }

    ConsoleSink &operator=(ConsoleSink &&other) noexcept {
        if (this == &other) {
            return *this;
        }
        std::lock(mutex, other.mutex);

        const std::lock_guard<std::mutex> lockThis(mutex, std::adopt_lock);
        const std::lock_guard<std::mutex> lockOther(other.mutex, std::adopt_lock);

        outputStream = std::move(other.outputStream);

        return *this;
    }

    void write(const std::string &message) {
        *outputStream << message << std::endl;
    }

private:
    std::shared_ptr<std::ostream> outputStream;
    mutable std::mutex mutex;
};


}

#endif
