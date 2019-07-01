#ifndef IO_H
#define IO_H

#include <iostream>
#include <string>
#include <list>

std::string io_get(
    std::istream &stream, std::string text = "");
std::list<std::string> io_get(
    std::istream &stream, std::list<std::string> texts);

void io_put(
    std::ostream &stream, const std::string &text);
void io_put(
    std::ostream &stream, const std::list<std::string> &texts);

const struct IO {
    std::istream &cin = std::cin;
    std::ostream &cout = std::cout;
    std::ostream &cerr = std::cerr;
} standard_io;

#endif /* IO_H */
