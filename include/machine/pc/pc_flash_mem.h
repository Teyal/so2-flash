// EPOS Flash Memory Mediator Declarations

#ifndef __pc_flah_h
#define __pc_flash_h

#define __flash_common_only__
#include <machine/flash_mem.h>
#undef  __flash_common_only__

__BEGIN_SYS

class Flash: public Flash_Common
{
    friend class Machine;

private:
    static const unsigned int ADDRESS = Traits<Flash>::ADDRESS;
    static const unsigned int SIZE = Traits<Flash>::SIZE;

public:
    Flash() {}

private:
    static void init();
};

__END_SYS

#endif
