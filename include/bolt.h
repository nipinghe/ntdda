
#ifndef __BOLT_H__
#define __BOLT_H__

#include "ddadlist.h"

#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif

#ifndef PRINTFUNC
#define PRINTFUNC
typedef int (*PrintFunc)(void * stream,const char * format,...);
#endif

typedef struct _bolt Bolt;
typedef struct _boltlist Boltlist; 
typedef struct _boltmat BoltMat;

/** @todo Move boltmat struct into bolt.c,
 * write the necessary accessor methods to 
 * ensure it remains an incomplete type.
 */
struct _boltmat{
   double e00;
   double t0;
   double f0;
};



Bolt *     bolt_new            (void);
Bolt *     bolt_new_1          (double x1,
                                double y1,
                                double x2,
				double y2);

/**
 * This is primarily used for unit testing to ensure that 
 * the bolt append and retrieve functions work correctly.
 *
 * @return int a for passing, 0 for failing.
 */
int        bolt_equals         (Bolt * b1,
                           	  Bolt * b2);

void       bolt_delete         (Bolt *);

int        bolt_test           (void);

void       bolt_set_endpoints  (Bolt * b, 
                                double x1,
                                double y1,
                                double x2,
                                double y2);

void       bolt_get_endpoints  (Bolt * b, 
                                double * x1,
                                double * y1,
                                double * x2,
                                double * y2);


/** Boltlist methods, which may go into their own
 * header file in the future.
 */


Boltlist * boltlist_new        (void);

/** Free all of the memory associated with a list 
 * of bolts.
 *
 * @warning This function deletes all the bolts in the
 * boltlist as well.  It breaks symmetry in the API, 
 * unfortunately, in c, there is no easy way around 
 * that fact.
 */
void       boltlist_delete     (Boltlist *);

/** Add a Bolt to the end of the list of bolts.
 */
void       boltlist_append     (Boltlist *, 
                                Bolt *);

/** Helper method, useful for transferring bolt data into 
 * arrays, which need to be allocated before the list is 
 * traversed.
 *
 * @return int number of bolts in the list.
 */
int        boltlist_length     (Boltlist *);

/** Internally, DDA uses arrays for everything so this 
 * allows transforming the bolt data into arrays.  Arrays
 * are very inconvenient to work with for dialog boxes, 
 * xml input, drawing etc.  The array of doubles ** are 
 * allocated in the calling function to help maintain 
 * symmetry in the memory handling.
 */
void       boltlist_get_array  (Boltlist *, 
                                double ** boltarray);

void       boltlist_print      (Boltlist *,
				PrintFunc printer,
				void * stream);

#ifdef __cplusplus
}
#endif

#endif /* __BOLT_H__ */
