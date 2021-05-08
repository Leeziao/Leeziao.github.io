#include <idc.idc>
static my_enum()
{
    auto addr, end, args, locals, frame, firstArg, name, ret;
    addr = 0;
    for (addr = get_next_func(addr); addr != -1; addr = get_next_func(addr))
    {
        name    = get_func_name(addr);
        end     = get_func_attr(addr, FUNCATTR_END);    // function end addr
        locals  = get_func_attr(addr, FUNCATTR_FRSIZE); // size of local variable
        frame   = get_frame_id(addr);                   // get fucntion stack id
        ret     = get_member_offset(frame, " r");       // get offset of variable " r"(return address)
        if (ret == -1)
            continue;
        firstArg = ret + 4;
        args    = get_struc_size(frame) - firstArg;

        msg("function: %s, starts at %x, ends at %x\n", name, addr, end);
        msg("   Local variable area is %d bytes\n", locals);
        msg("   Arguments occupy %d bytes (%d args)\n", args, args / 4);
    }
    msg("--------------END--------------\n");
}

static main()
{
    my_enum();
}