/*
 * Ignite Programming Language - aplib.hpp - Contains Anstro Pleuton's lib API and implementations (basically utils).
 *
 * MIT License
 *
 * Copyright (c) 2024 Anstro Pleuton
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef APLIB_HPP
#define APLIB_HPP

#include <cstdarg>
#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#ifdef APLIB_RAYLIB
#include "glm/glm.hpp" // IWYU pragma: keep
#include "raylib.h"
#endif

namespace aplib {
    // Add (combine) two vectors
    template <typename T>
    std::vector<T> operator+(const std::vector<T> &a, const std::vector<T> &b)
    {
        std::vector<T> c = a;
        c.insert(c.end(), b.begin(), b.end());
        return c;
    }

    // Multiply (repeat) string
    inline std::string operator*(std::string s, size_t n)
    {
        std::string result;

        // I can't think of a better way
        for (size_t i = 0; i < n; i++)
        {
            result.insert(result.end(), s.begin(), s.end());
        }
        return result;
    }

    // String manipulation
    namespace apstr {
        // Split a string by a delimiter
        inline std::vector<std::string> split(const std::string &string, char delim)
        {
            std::vector<std::string> result;
            std::stringstream sstream = std::stringstream(string);

            std::string temp;
            while (std::getline(sstream, temp, delim))
            {
                result.push_back(temp);
            }

            return result;
        }

        // Split a vector of strings by a delimiter (for recursive templates)
        inline std::vector<std::string> split(const std::vector<std::string> &vec_of_string, char delim)
        {
            std::vector<std::string> result;

            for (const std::string &s : vec_of_string)
            {
                // Call the overloaded split, not this
                const std::vector<std::string> sub_result = split(s, delim);
                result.insert(result.end(), sub_result.begin(), sub_result.end());
            }

            return result;
        }

        // Recursively split a vector of strings by multiple delimiters
        template <typename... Delim>
        inline std::vector<std::string> split(const std::vector<std::string> &vec_of_string, char delim, Delim... more_delims)
        {
            return split(split(vec_of_string, delim), more_delims...);
        }

        // Recursively split a string by multiple delimiters (the starting function)
        template <typename... Delim>
        inline std::vector<std::string> split(const std::string &string, char delim, Delim... more_delims)
        {
            return split(split(string, delim), more_delims...);
        }

        // Combine vector of string into a single delimiter-separated string
        inline std::string merge(const std::vector<std::string> &vec_of_string, char delim)
        {
            std::string result;
            for (size_t i = 0; i < vec_of_string.size(); i++)
            {
                if (i != 0)
                {
                    result.insert(result.end(), delim);
                }
                result.insert(result.end(), vec_of_string[i].begin(), vec_of_string[i].end());
            }
            return result;
        }

        // Word wrap
        inline std::vector<std::string> word_wrap(std::string s, size_t width)
        {
            std::vector<std::string> lines;

            // Continous chopping
            while (s.length() > width)
            {
                // Unsigned reverse for loop looks weird
                for (size_t i = width; i-- > 0;)
                {
                    // Split the line on space
                    if (s[i] == ' ')
                    {
                        lines.push_back(s.substr(0, i));
                        s = s.substr(i + 1);
                        break;
                    }
                }
            }

            if (s.length() > 0)
            {
                lines.push_back(s);
            }

            return lines;
        }
    } // namespace apstr

    // ANSI Escape Code for Colorized and Styled output
    namespace ansi {
        // Reset all colors and styles
        const std::string reset { "\033[0m" };

        // Colors
        const std::string black { "\033[30m" };
        const std::string red { "\033[31m" };
        const std::string green { "\033[32m" };
        const std::string yellow { "\033[33m" };
        const std::string blue { "\033[34m" };
        const std::string magenta { "\033[35m" };
        const std::string cyan { "\033[36m" };
        const std::string white { "\033[37m" };

        // Formats
        const std::string bold { "\033[1m" };
        const std::string underline { "\033[4m" };
        const std::string invert { "\033[7m" };
    } // namespace ansi

    // Command line argument parser
    namespace argp {
        // Flag to describe valid arguments
        struct Flag {
            std::string description;                       // Flag description for help message
            std::vector<std::string> long_names;           // Long argument flag, such as "version" for --version, "file-name" for --file-name, etc.
            std::vector<char> short_names;                 // Short argument flag, such as 'r' for -r, 'f' for -f, etc.
            std::vector<std::string> additional_arguments; // Additional arguments required by a flag
            int optional_arguments_count;                  // Number of arguments that are optional from the last additional arguments
        };

        // Option to describe parsed command-line arguments
        struct Option {
            const Flag *flag;                              // Flag for which this option belongs to
            std::vector<std::string> additional_arguments; // Gathered additional arguments
            std::string unrecognized_option;               // Option not recognized (in this case flag will be nullptr)
        };

        // Parse command-line arguments to options described by flags
        inline std::vector<Option> get_options_from_flags(std::vector<std::string> args, const std::vector<Flag> &flags)
        {
            enum class flag_type {
                unknown = 0,
                f_long, // Damn who decided to add `long` and `short` as keywords
                f_short,
                microsoft
            };

            auto is_flag = [&](std::string s) -> flag_type {
                if (s.size() > 2 && s[0] == '-' && s[1] == '-')
                {
                    return flag_type::f_long;
                }
                if (s.size() > 1 && s[0] == '-')
                {
                    return flag_type::f_short;
                }
                if (s.size() > 1 && s[0] == '/')
                {
                    return flag_type::microsoft;
                }
                return flag_type::unknown;
            };

            // Parse an option for most of the arguments
            std::vector<Option> options;
            for (size_t i = 0; i < args.size(); i++)
            {
                auto create_option = [&](bool &option_created, const Flag &flag) {
                    Option option = {};
                    option.flag = &flag;

                    // Check with all the arguments with current flag
                    for (size_t a = 0; a < flag.additional_arguments.size() && i < args[i].size() - a - 1; a++)
                    {
                        // Skip argument if it seems as a flag
                        if (a >= flag.additional_arguments.size() - flag.optional_arguments_count && is_flag(args[i]) != flag_type::unknown)
                        {
                            break;
                        }

                        // Add the additional argument
                        option.additional_arguments.push_back(args[++i]);
                    }
                    options.push_back(option);
                    option_created = true;
                };

                std::string arg = args[i];

                // Handle long arguments (--argument)
                if (is_flag(arg) == flag_type::f_long)
                {
                    // Remove "--" from the argument name
                    std::string argument_name = arg;
                    argument_name.erase(argument_name.begin(), argument_name.begin() + 2);

                    // Add unrecognized option when no option was created using this flag
                    bool option_created = false;

                    for (const Flag &flag : flags)
                    {
                        // Find a matching flag long name
                        for (size_t l = 0; l < flag.long_names.size(); l++)
                        {
                            if (argument_name == flag.long_names[l])
                            {
                                create_option(option_created, flag);
                            }
                        }
                    }

                    if (!option_created)
                    {
                        options.push_back(Option { nullptr, {}, arg });
                    }
                }

                // Handle short arguments (-a)
                else if (is_flag(arg) == flag_type::f_short)
                {
                    // Remove one '-' from the argument name
                    std::string argument_name = arg;
                    argument_name.erase(argument_name.begin(), argument_name.begin() + 1);

                    // Find a flag for all the short flags within one argument
                    for (char c : argument_name)
                    {
                        // Add unrecognized option when no option was created using this flag
                        bool option_created = false;

                        for (const Flag &flag : flags)
                        {
                            // Find a matching flag short name
                            for (size_t s = 0; s < flag.short_names.size(); s++)
                            {
                                if (c == flag.short_names[s])
                                {
                                    create_option(option_created, flag);
                                }
                            }
                        }

                        if (!option_created)
                        {
                            options.push_back(Option { nullptr, {}, std::string({ '-', c, '\0' }) });
                        }
                    }
                }

                // Handle Microsoft-style arguments (/a or /argument)
                else if (is_flag(arg) == flag_type::microsoft)
                {
                    // Remove the '/' from the argument name
                    std::string argument_name = arg;
                    argument_name.erase(argument_name.begin(), argument_name.begin() + 1);

                    bool option_created = false;

                    for (const Flag &flag : flags)
                    {
                        bool current_option_created = false;
                        // Find a matching flag long name
                        for (size_t l = 0; l < flag.long_names.size(); l++)
                        {
                            if (argument_name == flag.long_names[l])
                            {
                                create_option(current_option_created, flag);
                            }
                        }

                        // If no long flag matched, check for short flag
                        if (!current_option_created)
                        {
                            // Find a matching flag short name
                            for (size_t s = 0; s < flag.short_names.size(); s++)
                            {
                                if (argument_name[1] == flag.short_names[s])
                                {
                                    create_option(current_option_created, flag);
                                }
                            }
                        }
                        else
                        {
                            option_created = true;
                        }
                    }

                    if (!option_created)
                    {
                        options.push_back(Option { nullptr, {}, arg });
                    }
                }

                // Handle arguments that are not flags
                else
                {
                    options.push_back(Option { nullptr, {}, arg });
                }
            }
            return options;
        }

        // Same as above but shorthand
        inline std::vector<Option> get_options_from_flags(int argc, char **argv, const std::vector<Flag> &flags)
        {
            std::vector<std::string> args;
            for (int i = 1; i < argc; i++)
            {
                args.push_back(argv[i]);
            }
            return get_options_from_flags(args, flags);
        }

        // Print help message of a flag
        inline void print_flag_help(const Flag &flag, size_t flag_indent = 2, size_t description_indent = 40, size_t max_width = 80)
        {
            using namespace std::string_literals;

            // Just a function to print and count the number of characters printed
            auto cprintf = [](std::string format, ...) -> size_t {
                size_t result = 0;
                std::va_list args;
                va_start(args, format);
                result = std::vprintf(format.c_str(), args);
                va_end(args);
                return result;
            };

            size_t chars_printed = 0;

            // Pre-indent
            chars_printed += cprintf(" "s * flag_indent);
            if (flag.short_names.size() == 0)
            {
                chars_printed += cprintf("    ");
            }

            // Short flags (-a)
            for (size_t i = 0; i < flag.short_names.size(); i++)
            {
                if (i != 0)
                {
                    chars_printed += cprintf(", ");
                }
                chars_printed += cprintf("-%c", flag.short_names[i]);
            }

            // Separation between short and long flags
            if (flag.short_names.size() != 0 && flag.long_names.size() != 0)
            {
                chars_printed += cprintf(", ");
            }

            // Long flags (--argument)
            for (size_t i = 0; i < flag.long_names.size(); i++)
            {
                if (i != 0)
                {
                    chars_printed += cprintf(", ");
                }
                chars_printed += cprintf("--%s", flag.long_names[i].c_str());
            }

            // Additional arguments
            for (size_t i = 0; i < flag.additional_arguments.size(); i++)
            {
                chars_printed += printf(" ");
                if (i >= flag.additional_arguments.size() - flag.optional_arguments_count)
                {
                    chars_printed += cprintf("[");
                }
                chars_printed += cprintf("%s", flag.additional_arguments[i].c_str());
                if (i >= flag.additional_arguments.size() - flag.optional_arguments_count)
                {
                    chars_printed += cprintf("]");
                }
            }

            chars_printed += cprintf(" ");

            // Description
            if (chars_printed > description_indent)
            {
                cprintf("\n"s + " "s * (description_indent - 1) + ".");
            }
            else
            {
                cprintf("."s * (description_indent - chars_printed));
            }

            std::vector<std::string> wrapped_lines = apstr::word_wrap(flag.description, max_width - description_indent);
            for (size_t i = 0; i < wrapped_lines.size(); i++)
            {
                if (i != 0)
                {
                    cprintf(" "s * description_indent);
                }
                cprintf(" %s\n", wrapped_lines[i].c_str());
            }
        }

        // Print help message of all flags
        inline void print_help(const std::vector<Flag> &flags, std::string header, std::string footer, size_t flag_indent = 2, size_t description_indent = 40, size_t max_width = 80)
        {
            std::cout << header;
            for (const Flag &flag : flags)
            {
                print_flag_help(flag, flag_indent, description_indent, max_width);
            }
            std::cout << footer;
        }
    } // namespace argp

    // Raw (Binary) file input and output
    namespace rawfile {

        // Raw input file stream (without stream operators)
        class irfile {
            std::ifstream istream;

        public:
            irfile() = default;
            irfile(const std::string &filename)
                : istream(filename, std::ios::binary) {}

            inline void open(const std::string &filename)
            {
                istream.open(filename);
            }

            inline bool fail()
            {
                return istream.fail();
            }

            inline void close()
            {
                istream.close();
            }

            // Read size_t bytes for size of the raw data, and then read the raw data
            inline void read(std::vector<std::byte> &data)
            {
                size_t size = 0;
                if (!istream.eof()) istream.read((char *)&size, sizeof(size));
                data.resize(size);
                if (!istream.eof()) istream.read((char *)data.data(), size);
            }
        };

        // Raw output file stream (without stream operators)
        class orfile {
            std::ofstream ostream;

        public:
            orfile() = default;
            orfile(const std::string &filename)
                : ostream(filename, std::ios::binary) {}

            inline void open(const std::string &filename)
            {
                ostream.open(filename);
            }

            inline bool fail() { return ostream.fail(); }

            inline void close() { ostream.close(); }

            // Write size_t bytes for size of the raw data, and then write the raw data
            inline void write(const std::vector<std::byte> &data)
            {
                size_t size = data.size();
                ostream.write((const char *)&size, sizeof(size));
                ostream.write((const char *)data.data(), size);
            }
        };

        // Raw input/output file stream (without stream operators)
        class rfile : public irfile, public orfile {
        public:
            rfile() = default;
            rfile(const std::string &ifilename, const std::string &ofilename)
                : irfile(ifilename), orfile(ofilename) {}

            inline void open(const std::string &ifilename, const std::string &ofilename)
            {
                irfile::open(ifilename);
                orfile::open(ofilename);
            }

            inline bool fail()
            {
                return irfile::fail() || orfile::fail();
            }

            inline void close()
            {
                irfile::close();
                orfile::close();
            }
        };

        // Convert variable to byte vector
        template <typename T>
        inline std::vector<std::byte> to_bytes(const T &data)
        {
            const size_t t_size = sizeof(T);
            std::vector<std::byte> bytes = std::vector<std::byte>(t_size);
            std::memcpy(bytes.data(), &data, t_size);
            return bytes;
        }

        // Convert some type vector to byte vector
        template <typename T>
        inline std::vector<std::byte> to_bytes(const std::vector<T> &vector)
        {
            const size_t t_size = sizeof(T);
            std::vector<std::byte> bytes = std::vector<std::byte>(t_size * vector.size());
            std::memcpy(bytes.data(), vector.data(), t_size * vector.size());
            return bytes;
        }

        // Convert byte vector to type
        template <typename T>
        inline T to_data(const std::vector<std::byte> &bytes)
            requires(sizeof(T) == bytes.size())
        {
            T data = {};
            const size_t t_size = sizeof(T);
            std::memcpy(&data, bytes.data(), t_size);
            return data;
        }

        // Convert byte vector to some type vector
        template <typename T>
        inline std::vector<T> to_vector(const std::vector<std::byte> &bytes)
            requires(bytes.size() % sizeof(T) == 0)
        {
            const size_t t_size = sizeof(T);
            std::vector<T> vector = std::vector<T>(bytes.size() / t_size);
            std::memcpy(vector.data(), bytes.data(), bytes.size());
            return vector;
        }
    } // namespace rawfile

#ifdef APLIB_RAYLIB
    namespace rl {
        struct vec2 : public glm::vec2 {
            using glm::vec2::vec2;
            inline vec2(Vector2 v)
                : glm::vec2(v.x, v.y) {}
            inline operator Vector2()
            {
                return { x, y };
            }
        };

        struct vec3 : public glm::vec3 {
            using glm::vec3::vec3;
            inline vec3(Vector3 v)
                : glm::vec3(v.x, v.y, v.z) {}
            inline operator Vector3()
            {
                return { x, y, z };
            }
        };

        struct vec4 : public glm::vec4 {
            using glm::vec4::vec4;
            inline vec4(Vector4 v)
                : glm::vec4(v.x, v.y, v.z, v.w) {}
            inline operator Vector4()
            {
                return { x, y, z, w };
            }
        };

        struct mat4 : public glm::mat4 {
            using glm::mat4::mat4;
            inline mat4(Matrix m)
                : glm::mat4(m.m0, m.m4, m.m8, m.m12, m.m1, m.m5, m.m9, m.m13, m.m2, m.m6, m.m10, m.m14, m.m3, m.m7, m.m11, m.m15) {}
            inline operator Matrix()
            {
                return { (*this)[0][0], (*this)[1][0], (*this)[2][0], (*this)[3][0],
                         (*this)[0][1], (*this)[1][1], (*this)[2][1], (*this)[3][1],
                         (*this)[0][2], (*this)[1][2], (*this)[2][2], (*this)[3][2],
                         (*this)[0][3], (*this)[1][3], (*this)[2][3], (*this)[3][3] };
            }
        };

        struct col : public vec4 {
            using vec4::vec4;

            inline unsigned char r() { return x * 255; }
            inline unsigned char g() { return y * 255; }
            inline unsigned char b() { return z * 255; }
            inline unsigned char a() { return w * 255; }

            inline void r(unsigned char v) { x = v / 255.0f; }
            inline void g(unsigned char v) { y = v / 255.0f; }
            inline void b(unsigned char v) { z = v / 255.0f; }
            inline void a(unsigned char v) { w = v / 255.0f; }

            inline col(Color c)
            {
                r(c.r);
                g(c.g);
                b(c.b);
                a(c.a);
            }

            inline operator Color()
            {
                return { r(), g(), b(), a() };
            }

            inline vec4 get_hsv()
            {
                return { (vec3)ColorToHSV(*this), a() };
            }

            inline void set_hsv(const vec4 &hsv)
            {
                *this = ColorFromHSV(hsv.x, hsv.y, hsv.z);
                a(hsv.a);
            }

            inline vec4 &normal()
            {
                return *this;
            }
        };

        inline void raylib_init(std::string title, int width = 800, int height = 450, int fps = 60, unsigned int flags = FLAG_WINDOW_RESIZABLE)
        {
            SetConfigFlags(flags);
            InitWindow(width, height, title.c_str());
            SetTargetFPS(fps);
            SetWindowMinSize(width / 10, height / 10);
            SetExitKey(0);
        }

        inline void raylib_close()
        {
            CloseWindow();
        }
    } // namespace rl
#endif
} // namespace aplib

#endif
