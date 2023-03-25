/**************************************************************************\
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, Fabrizio Morciano
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

#define BOOST_TEST_NO_LIB 1
#include <boost/test/unit_test.hpp>
#include "Inventor/Wx/widgets/SoWxGLArea.h"

BOOST_AUTO_TEST_SUITE(TestSoWxGLArea);

BOOST_AUTO_TEST_CASE(shouldFailIf_isGLFeatureAvailable_Empty) {
    SoWxGLArea::GLFormat format;
    BOOST_CHECK(!SoWxGLArea::isGLFeatureAvailable(format,
                                                  WX_GL_DOUBLEBUFFER));
    format.push_back(0);
    BOOST_CHECK(!SoWxGLArea::isGLFeatureAvailable(format,
                                                  WX_GL_DOUBLEBUFFER));
}

BOOST_AUTO_TEST_CASE(isGLFeatureAvailable) {
    SoWxGLArea::GLFormat format;
    format.push_back(WX_GL_DOUBLEBUFFER);
    format.push_back(0);
    BOOST_CHECK(SoWxGLArea::isGLFeatureAvailable(format,
                                     WX_GL_DOUBLEBUFFER));

    BOOST_CHECK(!SoWxGLArea::isGLFeatureAvailable(format,
                                                WX_GL_STEREO));
}

BOOST_AUTO_TEST_CASE(shouldFindFormatWithParameter) {
    SoWxGLArea::GLFormat format;
    format.push_back(WX_GL_DOUBLEBUFFER);
    format.push_back(WX_GL_BUFFER_SIZE);
    // Wrong I'm adding GL_STEREO as parameter for format BUFFER_SIZE
    // this is just for checking that does not confuse format with parameters
    format.push_back(WX_GL_STEREO);
    format.push_back(0);
    BOOST_CHECK(!SoWxGLArea::isGLFeatureAvailable(format,
                                                  WX_GL_STEREO));
    BOOST_CHECK(SoWxGLArea::isGLFeatureAvailable(format,
                                                  WX_GL_DOUBLEBUFFER));
    BOOST_CHECK(SoWxGLArea::isGLFeatureAvailable(format,
                                                  WX_GL_BUFFER_SIZE));
}

BOOST_AUTO_TEST_SUITE_END();
