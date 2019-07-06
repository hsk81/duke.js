#include "io.h"

std::ifstream io_ctor(
    const std::string path
) {
    auto stream = std::ifstream(path);
    if (!stream) {
        io_put(std::cerr, {
            "duke: ", path, ": No such file or directory", "\n"
        });
    }
    return stream;
}

void io_dtor(
    std::ifstream &stream
) {
    stream.close();
}

std::string io_get(
    std::istream &stream, std::string text
) {
    for (std::string line; std::getline(stream, line);) {
        text.append(line);
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
    for (auto text : texts) stream << text;
}
