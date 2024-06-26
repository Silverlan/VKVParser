//
// Created by MED45 on 07.01.2022.
//

#ifndef KVPARSER_SHARED_HPP
#define KVPARSER_SHARED_HPP

#include <functional>
#include <cctype>
#include <string>
#include <cinttypes>

namespace ValveKeyValueFormat {
	enum class LogLevel : int8_t {
		ALL = 0,
		TRACE = 1,
		DEBUG = 2,
		WARN = 3,
		ERR = 4,
	};

	using LoggerFunction = std::function<void(const std::string& message, LogLevel severity)>;
	extern LoggerFunction logger_function;


    inline std::string_view trim(std::string_view in) {
        uint32_t left = 0;
        for (;; ++left) {
            if (left == in.length())
                return {};
            if (!isspace(in[left]))
                break;
        }
        auto right = in.length();
        for (; right > left && isspace(in[right - 1]); --right) {};

        return in.substr(left, right - left);
    }
    inline std::string to_lower(std::string& s) {
        char* c = const_cast<char*>(s.c_str());
        size_t l = s.size();
        for (char* c2 = c; c2 < c + l; c2++) *c2 = tolower(*c2);
        return s;
    }
};

#ifdef _WIN32
#define LIBRARY_API __declspec(dllexport)
#else
#define LIBRARY_API
#endif

#endif//KVPARSER_SHARED_HPP
