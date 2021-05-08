#include <idc.idc>

static list_callers(func_name)
{
    auto func_addr, target, xref;
    func_addr   = get_name_ea(BADADDR, func_name);
    if (BADADDR == func_addr)
    {
        msg("[x] %s not exist\n", func_name);
        return;
    }
    func_addr   = get_func_attr(func_addr, FUNCATTR_START);


    for (target = get_first_cref_to(func_addr); target != BADADDR; target = get_next_cref_to(func_addr, target))
    {
        msg("%s calls [%s] at %x\n", get_func_name(target), func_name, target);
        // msg("[%s] at %x\n", func_name, func_addr);
        // xref = get_xref_type();
        // if (xref == fl_CF || xref == fl_CN)
        // {
        // }
    }
}

static main()
{
    msg("--------------------\n");
    list_callers("_strcpy");
    list_callers("_sprintf");
}