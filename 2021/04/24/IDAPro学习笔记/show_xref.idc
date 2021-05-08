#include <idc.idc>

static show_xref()
{
    auto func, end, target, inst, name, flags, xref;
    flags   = SEARCH_DOWN;
    func    = get_func_attr(here, FUNCATTR_START);

    if (-1 != func)
    {
        name    = get_func_name(func);
        end     = get_func_attr(func, FUNCATTR_END);
        for (inst = func; inst < end; inst = find_code(inst, flags))
        {
            for (target = Rfirst(inst); target != -1; target = Rnext(inst, target))
            {
                xref = get_xref_type();
                if (xref == fl_CN || xref == fl_CF)
                {
                    msg("%s calls %s from %x\n", name, get_func_name(target), inst);
                }
            }
        }
    }
    else
    {
        warning("No function located at %x\n", here);
    }
}

static main()
{
    msg("--------------------\n");
    show_xref();
}