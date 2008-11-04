/* -*- c -*- */
/* $Id$ */

#ifndef __META_GENERIC_H__
#define __META_GENERIC_H__

/* Copyright (C) 2008 Alexander Chernov <cher@ejudge.ru> */

/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <stdlib.h>

struct meta_info_item
{
  int tag;
  int type;
  size_t size;
  char *name;
  int offset;
};

#ifndef XSIZE
#define XSIZE(t,f) (sizeof(((t*)0)->f))
#endif

struct meta_automaton
{
  unsigned char remap[256];
  int char_num;

  short **st;                   /* states */
  int st_u;
  int st_a;
};

struct meta_automaton *
meta_build_automaton(const struct meta_info_item *item, int num);
int
meta_lookup_string(const struct meta_automaton *atm, const char *str);

#endif /* __META_GENERIC_H__ */
