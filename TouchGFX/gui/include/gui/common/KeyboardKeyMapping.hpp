#ifndef KEYBOARD_KEY_MAPPING_H
#define KEYBOARD_KEY_MAPPING_H

#include <touchgfx/widgets/Keyboard.hpp>
using namespace touchgfx;

/**
 * This file contains all the keymappings for the CustomKeyboard.
 */
static const Keyboard::KeyMapping keyMappingsAlphaLower[35] =
{
    { 1, 49},   // 1
    { 2, 50},   // 2
    { 3, 51},   // 3
    { 4, 52},   // 4
    { 5, 53},   // 5
    { 6, 54},   // 6
    { 7, 55},   // 7
    { 8, 56},   // 8
    { 9, 57},   // 9
    {10, 97},   // a
    {11, 98},   // b
    {12, 99},   // c
    {13, 100},  // d
    {14, 101},  // e
    {15, 102},  // f
    {16, 103},  // g
    {17, 104},  // h
    {18, 105},  // i
    {19, 106},  // j
    {20, 107},  // k
    {21, 108},  // l
    {22, 109},  // m
    {23, 110},  // n
    {24, 111},  // o
    {25, 112},  // p
    {26, 113},  // q
    {27, 114},  // r
    {28, 115},  // s
    {29, 116},  // t
    {30, 117},  // u
    {31, 118},  // v
    {32, 119},  // w
    {33, 120},  // x
    {34, 121},  // y
    {35, 122},  // z
};

static const Keyboard::KeyMappingList keyMappingListAlphaLower =
{
    keyMappingsAlphaLower,
    35
};
#endif
