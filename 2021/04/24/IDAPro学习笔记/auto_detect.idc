#include <idc.idc>

static auto_detect()
{
    auto name, start_addr, end_addr, func, inst, flag, func_flag;
    flag        = SEARCH_DOWN;
    start_addr  = get_func_attr(here, FUNCATTR_START);
    end_addr    = get_func_attr(start_addr, FUNCATTR_END);
    name        = get_func_name(start_addr);
    func_flag   = get_func_flags(start_addr);

    if (!(FUNC_FRAME & func_flag))
    {
        warning("It is not a BP based function");
        return;
    }

    for (inst = start_addr; inst < end_addr && inst != BADADDR; inst = find_code(inst, flag))
    {
        auto op_type;
        op_type     = get_operand_type(inst, 0);
        if (strstr(print_operand(inst, 0), "esp") == -1)
            continue;

        if (op_type == o_phrase)
        {
            MakeComm(inst, "arg_0");    // [esp] = arg_0
        }
        else if (op_type == o_displ)
        {
            auto val = get_operand_value(inst, 0);
            MakeComm(inst, sprintf("arg_%d", val));
        }
    }
}

static main()
{
    auto_detect();
}
