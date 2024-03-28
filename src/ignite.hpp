/*
 * Ignite Programming Language - ignite.hpp - Contains API for transpiling Ignite source code.
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

#include "aplib.hpp"
using namespace aplib;
using namespace ansi;

// --------------------------------
// Shortcuts
// --------------------------------

// Colors
const std::string primary_color = white;
const std::string warning_color = yellow;
const std::string error_color = red;

// Texts (yes I would not want to type that again and again)
const std::string warning_text = warning_color + "Warning: " + primary_color;
const std::string error_text = error_color + "Error: " + primary_color;

// --------------------------------
// Main structures
// --------------------------------
