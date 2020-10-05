#include <utility/ostream.h>
#include <machine/flash_mem.h>

using namespace EPOS;

OStream cout;

int main()
{
    
    const char *teste = new (FLASH) char[5];
    teste = "test";
    cout << "Hello world!" << teste << endl; 
    //cout << "Hello world" << endl;

    return 0;
}
