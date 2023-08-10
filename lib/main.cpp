#include <iostream>
#include <LogoLoco.h>

int main() {
    using namespace LogoLoco;
    FileSink fileSink{"C:\\tmp\\logi.txt"};
    ConsoleSink consoleSink{};

    Logger logger{fileSink, consoleSink};

    logger.log("Wassup");
    logger.log("Wassup2");

}