// EPOS Flash Memory Mediator Declarations

#ifndef __flash_mem_h
#define __flash_mem_h

#include <utility/heap.h>
#include <memory.h>

__BEGIN_SYS


class Flash_Common
{
    friend void * ::operator new(size_t, const EPOS::Flash_Allocator &);
    friend void * ::operator new[](size_t, const EPOS::Flash_Allocator &);

protected:
    Flash_Common() {}

public:
    static void * alloc(unsigned int bytes) { return _heap->alloc(bytes); }

protected:
    static Segment * _segment;
    static Heap * _heap;
};

__END_SYS

#if defined(__FLASH_H) && !defined(__flash_common_only__)
#include __FLASH_H

inline void * operator new(size_t bytes, const EPOS::Flash_Allocator & allocator) {
    return _SYS::Flash::_heap->alloc(bytes);
}

inline void * operator new[](size_t bytes, const EPOS::Flash_Allocator & allocator) {
    return _SYS::Flash::_heap->alloc(bytes);
}

#endif

#endif
