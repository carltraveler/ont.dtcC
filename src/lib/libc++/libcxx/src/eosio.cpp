#pragma once

/**
 * Define specific things for the ont system
 */

extern "C" {
   void ont_assert(unsigned int, const char*, unsigned int);
   void __cxa_pure_virtual() { ont_assert(false, "pure virtual method called", 27); }
}
