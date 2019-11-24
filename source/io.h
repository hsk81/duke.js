#ifndef IO_H
#define IO_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>

std::ifstream* io_ctor(
    std::string path
);
void io_dtor(
    std::ifstream *stream
);

std::string io_get(
    std::istream &stream, std::string text = "");
std::list<std::string> io_get(
    std::istream &stream, std::list<std::string> texts);

void io_put(
    std::ostream &stream, const std::string &text);
void io_put(
    std::ostream &stream, const std::list<std::string> &texts);

const struct IO {
    std::istream &istream = std::cin;
    std::string iname = "";
    std::ostream &ostream = std::cout;
    std::string oname = "";
    std::ostream &estream = std::cerr;
    std::string ename = "";

    IO() {}
    IO(std::istream& istream, std::string iname)
    : istream(istream), iname(iname) {}
    IO(std::ostream& ostream, std::string oname)
    : ostream(ostream), oname(oname) {}
    IO(std::istream& istream, std::string iname,
       std::ostream& ostream, std::string oname)
    : istream(istream), iname(iname),
      ostream(ostream), oname(oname) {}
    IO(std::ostream& ostream, std::string oname,
       std::ostream& estream, std::string ename)
    : ostream(ostream), oname(oname),
      estream(estream), ename(ename) {}
    IO(std::istream& istream, std::string iname,
       std::ostream& ostream, std::string oname,
       std::ostream& estream, std::string ename)
    : istream(istream), iname(iname),
      ostream(ostream), oname(oname),
      estream(estream), ename(ename) {}
} standard_io;

#endif /* IO_H */
