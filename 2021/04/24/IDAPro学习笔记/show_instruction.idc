#include <idc.idc>

static show_instruciton()
{
    auto func, end, count, inst;
    func    = get_func_attr(get_screen_ea(), FUNCATTR_START);

    if (-1 != func)
    {
        end     = get_func_attr(func, FUNCATTR_END);
        count   = 0;
        inst    = func;

        while (inst < end)
        {
            count++;
            inst = find_code(inst, SEARCH_DOWN);
        }
        warning("%s contains %d instructions\n", get_func_name(func), count);
    }
    else
    {
        warning("No function found at location %x\n", get_screen_ea());
    }
} 

static main()
{
    show_instruciton();
}

