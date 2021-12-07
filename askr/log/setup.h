#pragma once

#include <iosfwd>

namespace askr {

template <typename CharT>
void init_from_stream(std::basic_istream<CharT> &strm);

} // namespace askr