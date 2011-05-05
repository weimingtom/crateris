/*
 * Copyright (c) 2011, okazoh_tk. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *  - Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *  - Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *  - Neither the name of the copyright holder nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef CRATERIS_UTILITY_H_INCLUDED_
#define CRATERIS_UTILITY_H_INCLUDED_

#ifdef _WIN32
#ifdef CRATERIS_EXPORTS
#define CR_EXPORT __declspec(dllexport)
#else
#define CR_EXPORT __declspec(dllimport)
#endif
#else
#define CR_EXPORT
#endif

#ifdef __cplusplus
#define CR_API extern "C" CR_EXPORT
#else
#define CR_API extern CR_EXPORT
#endif

template<typename T, typename U = const char*>
struct Pair {
    T key;
    U value;

    typedef T key_type;
    typedef U value_type;
};

#define CR_REC(v)       {v, #v}
#define CR_COUNT_OF(v)  (sizeof(v)/sizeof(v[0]))

#define crFind(pairs, key)    \
    crBinSearch(pairs, CR_COUNT_OF(pairs), key)

template<class T>
typename T::value_type crBinSearch(const T* pairs, int length, typename T::key_type key)
{
    if (!pairs || length <= 0)
        return 0;

    int pivot;
    int top = 0;
    int bottom = length;

    while (top <= bottom) {

        pivot = (top + bottom) >> 1;

        if (pairs[pivot].key == key)
            return pairs[pivot].value;

        if (pairs[pivot].key < key) {
            top = pivot + 1;
        } else {
            bottom = pivot - 1;
        }
    }

    return 0;
}

#endif
