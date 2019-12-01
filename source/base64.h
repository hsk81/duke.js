#ifndef BASE64_H
#define BASE64_H

#include <iostream>
#include <string>

std::string b64_get(
    const std::istream &stream);
void b64_put(
    const std::ostream &stream, const std::string data);

std::string b64_encode(
    const std::string data);
std::string b64_decode(
    const std::string data);

#endif /* BASE64_H */
