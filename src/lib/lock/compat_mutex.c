/* Copyright (c) 2003-2004, Roger Dingledine
 * Copyright (c) 2004-2006, Roger Dingledine, Nick Mathewson.
 * Copyright (c) 2007-2018, The Tor Project, Inc. */
/* See LICENSE for licensing information */

#include "lib/lock/compat_mutex.h"
#include "lib/malloc/util_malloc.h"

/** Return a newly allocated, ready-for-use mutex. */
tor_mutex_t *
tor_mutex_new(void)
{
  tor_mutex_t *m = tor_malloc_zero(sizeof(tor_mutex_t));
  tor_mutex_init(m);
  return m;
}
/** Return a newly allocated, ready-for-use mutex.  This one might be
 * non-recursive, if that's faster. */
tor_mutex_t *
tor_mutex_new_nonrecursive(void)
{
  tor_mutex_t *m = tor_malloc_zero(sizeof(tor_mutex_t));
  tor_mutex_init_nonrecursive(m);
  return m;
}
/** Release all storage and system resources held by <b>m</b>. */
void
tor_mutex_free_(tor_mutex_t *m)
{
  if (!m)
    return;
  tor_mutex_uninit(m);
  tor_free(m);
}