/*

   Copyright (c) 2006-2010, The Scripps Research Institute

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.

   Author: Dr. Oleg Trott <ot14@columbia.edu>, 
           The Olson Lab, 
           The Scripps Research Institute

*/

#ifndef VINA_PARSE_ERROR_H
#define VINA_PARSE_ERROR_H

#include "common.h"


struct parse_error {
    path file;
    unsigned line;
    std::string reason;
    parse_error(const path& file_, unsigned line_, const std::string& reason_ = "") : file(file_), line(line_), reason(reason_) {}
private:
    parse_error() {}
};

struct stream_parse_error {
    unsigned line;
    std::string reason;
    stream_parse_error(unsigned line_, const std::string& reason_) : line(line_), reason(reason_) {}
    parse_error to_parse_error(const path& name) const {
        return parse_error(name, line, reason);
    }
};

struct atom_syntax_error {
    std::string nature;
    atom_syntax_error(const std::string& nature_) : nature(nature_) {}
};

#endif