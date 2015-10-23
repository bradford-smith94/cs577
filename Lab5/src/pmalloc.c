/* Bradford Smith (bsmith8)
 * CS 577 Lab 5 pmalloc.c
 * 10/22/2015
 * "I pledge my honor that I have abided by the Stevens Honor System."
 */

#include "protect.h"

/* pre: takes in a size_t size
 * post: allocates size bytes plus a guard-page
 * returns: a pointer to the address of the allocated memory
 */
void* pmalloc(size_t size)
{
    struct s_meta meta;
    size_t padding;
    void* guardPage;
    void* buffer;

    /* error check */
    if (size == 0)
        return NULL;

#ifdef DEBUG
    printf("[DEBUG]\t[pmalloc]\tsize given: %lu\n", (unsigned long)size);
    fflush(stdout);
#endif

    /* loop until size is a multiple of ALIGNMENT -- note the semicolon here */
    for (;size % ALIGNMENT != 0; size += 1);

#ifdef DEBUG
    printf("[DEBUG]\t[pmalloc]\tsize after alignment: %lu\n", (unsigned long)size);
    fflush(stdout);
#endif

    /* get the ammount of padding before the buffer (accounts for metadata) */
    padding = PAGE_SIZE - ((size + sizeof(meta)) % PAGE_SIZE);
    padding += sizeof(meta);

#ifdef DEBUG
    printf("[DEBUG]\t[pmalloc]\tfound padding: %lu\n\tsize of s_meta: %lu\n",
            (unsigned long)padding,
            (unsigned long)sizeof(meta));
    fflush(stdout);
#endif

    /* map guard page */
    guardPage = mmap(NULL,
            PAGE_SIZE,
            PROT_NONE,
            MAP_SHARED | MAP_ANONYMOUS,
            -1,
            0);

    if (guardPage == MAP_FAILED)
        return MAP_FAILED;

#ifdef DEBUG
    printf("[DEBUG]\t[pmalloc]\tguard page mapped at: %lu\n\twith size of: %d\n",
            (unsigned long)guardPage,
            PAGE_SIZE);
    fflush(stdout);
#endif

    /* map the buffer */
    buffer = mmap((void *)((unsigned long)guardPage - (size + padding)),
            (size + padding),
            PROT_READ | PROT_WRITE,
            MAP_SHARED | MAP_ANONYMOUS,
            -1,
            0);

    if (buffer == MAP_FAILED)
        return MAP_FAILED;

#ifdef DEBUG
    printf("[DEBUG]\t[pmalloc]\tbuffer mapped at: %lu\n\twith size of: %lu\n",
            (unsigned long)buffer,
            (unsigned long)(size + padding));
    if ((unsigned long)buffer != ((unsigned long)guardPage - (size + padding)))
        printf("[DEBUG]\t[pmalloc]\tbuffer location differs from given: %lu\n",
                ((unsigned long)guardPage - (size + padding)));
    fflush(stdout);
#endif

    /* setup buffer metadata, total length and absolute start */
    meta.len = size + padding + PAGE_SIZE;
    meta.buflen = size;
    meta.ptr = buffer;

#ifdef DEBUG
    printf("[DEBUG]\t[pmalloc]\tsetup metadata\n\tlength: %lu\n\tpointer: %lu\n\tbuflen: %lu\n",
            (unsigned long)meta.len,
            (unsigned long)meta.ptr,
            (unsigned long)meta.buflen);
    fflush(stdout);
#endif

    /* copy the metadata into the buffer at the end of the padding but before
     * the buffer itself */
    memcpy((void *)((unsigned long)buffer + (padding - sizeof(meta))), &meta, sizeof(meta));

#ifdef DEBUG
    printf("[DEBUG]\t[pmalloc]\tpasses memcpy\n");
    fflush(stdout);
#endif

    /* return the start of the buffer */
    return (void *)((unsigned long)buffer + padding);
}
