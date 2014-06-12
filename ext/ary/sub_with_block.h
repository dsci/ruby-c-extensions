#ifndef SUB_WITH_BLOCK_NODE
#define SUB_WITH_BLOCK_NODE

#include <ruby.h>

void Init_sub_with_block(VALUE parent);
/* Just yields a block */
static VALUE t_my_method(VALUE self);
/* removes last element from an array */
static VALUE t_remove_last_from_array(VALUE self, VALUE ary);

static VALUE t_my_class_method(VALUE self);
//static VALUE t_create(VALUE self);

#endif
