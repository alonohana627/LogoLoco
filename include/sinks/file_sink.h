#ifndef LOGOLOCO_FILE_SINK_H
#define LOGOLOCO_FILE_SINK_H

#include <string>
#include <fstream>
#include <utility>

namespace LogoLoco {

class FileSink {
public:
    explicit FileSink(std::string fileName) : fileName(std::move(fileName)) {
        fileStream.open(this->fileName);
    }

    // Rule of Five: Destructor
    ~FileSink() {
        fileStream.close();
    }

    // Rule of Five: Copy Constructor (Deleted)
    FileSink(const FileSink &other) {
        fileName = other.fileName;
        fileStream.open(fileName);
    }

    // Rule of Five: Copy Assignment Operator (Deleted)
    FileSink &operator=(const FileSink &other) {
        if (this == &other) {
            fileStream.open(fileName);
            return *this;
        }

        fileName = std::move(fileName);

        fileStream.open(fileName);
        return *this;
    }

    // Rule of Five: Move Constructor
    FileSink(FileSink &&other) noexcept: fileName(std::move(other.fileName)) {
        fileStream.open(fileName);
    }

    // Rule of Five: Move Assignment Operator
    FileSink &operator=(FileSink &&other) noexcept {
        if (this != &other) {
            fileName = std::move(other.fileName);

            fileStream.open(fileName);
            return *this;
        }

        fileStream.open(fileName);
        return *this;
    }

    void write(const std::string &message) {
        fileStream << message << std::endl;
    }

private:
    std::string fileName;
    std::fstream fileStream;
};

}

#endif
