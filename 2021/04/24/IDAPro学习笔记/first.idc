#include <idc.idc>
static first_func()
{
    auto array_str, array_id, my_str;

    array_str   = "my_first_array";
    my_str      = "first string";

    array_id = CreateArray(array_str);

    if (-1 == array_id)
    {
        Message("Array already exists\n");
        array_id = GetArrayId(array_str);
        DeleteArray(array_id);
        array_id = CreateArray(array_str);
    }

    Message("-----------START------------\n");
    SetArrayString(array_id, 0, my_str);
    SetArrayLong(array_id, 0, 12);
    Message("Setting\n");

    Message("str = %s\n", GetArrayElement(AR_STR, array_id, 0));
    Message("val = %d\n", GetArrayElement(AR_LONG, array_id, 0));
    Message("Print Finish\n");

    array_id = GetArrayId(array_str);
    DeleteArray(array_id);
    Message("-----------END------------\n");
}

static main()
{
    first_func();
}
