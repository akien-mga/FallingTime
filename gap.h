/*
Copyright (c) 2015, Cong Xu
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.
Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation
and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/
#pragma once

#include <stdbool.h>

#include <chipmunk/chipmunk.h>
#include <SDL.h>

#include "block.h"

// Gaps are a pair of rectangles with a gap in between.
// The player scores after falling through a gap.

struct Gap
{
	Block Left;
	Block Right;
	// Where the gap layer is.
	float Y;
	// Where the gap starts and ends
	float GapLeft;
	float GapRight;

	bool Passed;
};

extern SDL_Surface *GapSurfaces[6];

void GapInit(struct Gap* gap, float y, float gapX);
void GapRemove(struct Gap* gap);
void GapDraw(const struct Gap* gap, const float y);

extern float GapBottom(const struct Gap* gap);

bool GapSurfacesLoad(void);
void GapSurfacesFree(void);
