/*ckwg +29
 * Copyright 2017-2018 by Kitware, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  * Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 *  * Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 *  * Neither name of Kitware, Inc. nor the names of any contributors may be used
 *    to endorse or promote products derived from this software without specific
 *    prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * \file
 * \brief Interface for read_object_track_set_viame_csv
 */

#ifndef VIAME_CORE_READ_OBJECT_TRACK_SET_VIAME_CSV_H
#define VIAME_CORE_READ_OBJECT_TRACK_SET_VIAME_CSV_H

#include <plugins/core/viame_core_export.h>

#include <vital/algo/read_object_track_set.h>

#include <memory>

namespace viame {

class VIAME_CORE_EXPORT read_object_track_set_viame_csv
  : public kwiver::vital::algorithm_impl< read_object_track_set_viame_csv,
      kwiver::vital::algo::read_object_track_set >
{
public:

  static constexpr char const* name = "viame_csv";

  static constexpr char const* description =
    "Object track set viame_csv reader.\n\n"
    "  - Column(s) 1: Detection or Track-id\n"
    "  - Column(s) 2: Video or Image List ID\n"
    "  - Column(s) 3: Unique Frame Identifier\n"
    "  - Column(s) 4-7: Img-bbox(TL_x,TL_y,BR_x,BR_y)"
    "  - Column(s) 8: Detection confidence\n"
    "  - Column(s) 8: Fish Length (0 or -1 if invalid)\n"
    "  - Column(s) 9-10+: Repeated Species, Confidence pairs\n";

  read_object_track_set_viame_csv();
  virtual ~read_object_track_set_viame_csv();

  virtual void open( std::string const& filename );

  virtual void set_configuration( kwiver::vital::config_block_sptr config );
  virtual bool check_configuration( kwiver::vital::config_block_sptr config ) const;

  virtual bool read_set( kwiver::vital::object_track_set_sptr& set );

private:
  class priv;
  std::unique_ptr< priv > d;
};

} // end namespace

#endif // VIAME_CORE_READ_OBJECT_TRACK_SET_VIAME_CSV_H
