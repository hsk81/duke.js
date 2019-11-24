#include "io.h"

std::ifstream* io_ctor(
    const std::string path
) {
    std::ifstream *stream = new std::ifstream(path);
    if (!stream->good()) {
        io_put(std::cerr, std::list<std::string>{
            "duke: ", path, ": No such file or directory", "\n"
        });
    }
    return stream;
}

void io_dtor(
    std::ifstream *stream
) {
    stream->close();
}

std::string io_get(
    std::istream &stream, std::string text
) {
    for (std::string line; std::getline(stream, line);) {
        text.append(line).append("\n");
    }
    return text;
}

std::list<std::string> io_get(
    std::istream &stream, std::list<std::string> texts
) {
    for (std::string line; std::getline(stream, line);) {
        texts.push_back(line);
    }
    return texts;
}

void io_put(
    std::ostream &stream, const std::string &text
) {
    stream << text;
}

void io_put(
    std::ostream &stream, const std::list<std::string> &texts
) {
    for (const std::string text : texts) stream << text;
}
