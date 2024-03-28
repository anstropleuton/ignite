/*
 * Ignite Programming Language - main.cpp - Contains the CLI code for the ignite transpiler.
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

#include <string>
#include <vector>

#include "ignite.hpp"

// Welcome to the world
int main(int argc, char **argv)
{
    // --------------------------------
    // Pre program
    // --------------------------------

    // BE SURE TO SYNC IT WITH THE BELOW VECTOR AND BELOW FLAG FUNCTIONS
    enum class flag_type {
        output = 0
    };

    // The "BELOW VECTOR"
    std::vector<argp::Flag> flags = {
        argp::Flag { "Output filename", { "output", "out" }, { '0' }, { "filename" }, 0 }
    };

    // --------------------------------
    // Program wide variables
    // --------------------------------

    std::string output_filename;

    // --------------------------------
    // Flag functions
    // --------------------------------

    auto Output = [&](const argp::Option &option) {
        if (option.additional_arguments.size() > 0)
        {
            output_filename = option.additional_arguments[0];
        }
    };

    // --------------------------------
    // Argument parsing stuff
    // --------------------------------

    std::vector<argp::Option> options = argp::get_options_from_flags(argc, argv, flags);
    for (size_t i = 0; i < options.size(); i++)
    {
        argp::Option &option = options[i];
        if (!option.unrecognized_option.empty())
        {
            std::cout << warning_text << "Unrecognized option: " << warning_color << option.unrecognized_option << primary_color;
        }
        if (option.flag == &flags[(int)flag_type::output]) Output(option);
    }
}
