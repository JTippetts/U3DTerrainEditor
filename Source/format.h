#pragma once

#include <cstdio>
#include <Urho3D/Container/Str.h>

template <size_t BufSize>
class Formatter {
	private:
	char const * const fmt;
	public:
	constexpr Formatter(char const * const fmt) : fmt{fmt} {}

	template <typename... ArgTs>
	String operator ()(ArgTs const &... args) const {
		char buf[BufSize];
		String ret;
		auto size = snprintf(buf, BufSize, this->fmt, args...);
		if (size < 0) {
			/* encoding error */
			//return {};
			return String();
		} else if (static_cast<size_t>(size) >= BufSize) {
			/* does not fit into buffer */
			//return {buf, BufSize - 1};
			return ret.Append(buf, BufSize-1);
		}
		//return {buf, static_cast<unsigned int>(size)};return
		return ret.Append(buf, static_cast<unsigned int>(size));
	}
};

constexpr Formatter<16384> operator "" _fmt(char const * const fmt, size_t const) {
	return {fmt};
}