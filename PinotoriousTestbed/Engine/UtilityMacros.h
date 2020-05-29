#pragma once

#ifndef UTILITY_MACROS_H
#define UTILITY_MACROS_H

#define IN_RANGE(X, MIN, MAX) (X >= MIN && X < MAX)
#define IN_RANGE_INCLUSIVE(X, MIN, MAX) (X >= MIN && X <= MAX)
#define IN_RANGE_ARRAY(X, SIZE) (IN_RANGE(X,0,SIZE))

#endif