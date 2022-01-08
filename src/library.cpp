#include "library.h"
#include <cstdio>
#include <kv_parser.hpp>

LoggerFunction* logger_function = [](const std::string& message, LogLevel severity) -> void { fprintf(stderr, "%s\n", message.c_str()); };

LIBRARY_API std::shared_ptr<KVNode> parseKVBuffer(const std::string& buffer) {
    auto parser = ValveKeyValueFormat::KVParser(buffer);
    parser.parse();
    return parser.root();
}
LIBRARY_API void setLogCallback(LoggerFunction* loggerFunction) {
    logger_function = loggerFunction;
}
