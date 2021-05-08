#include <idc.idc>

static mimic()
{
    auto var_4, addr;
    for (var_4 = 0; var_4 <= 0x3c1; var_4++)
    {
        addr = 0x804b880 + var_4;
        patch_byte(addr, byte(addr) ^ 0x4b);
    }
}

static main()
{
    mimic();
}
